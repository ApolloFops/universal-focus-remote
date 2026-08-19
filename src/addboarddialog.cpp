#include "addboarddialog.h"
#include "boards/etc/eos/eosdiscovery.h"
#include "boards/etc/eos/eossettings.h"
#include "ui_addboarddialog.h"

#include <QPushButton>

AddBoardDialog::AddBoardDialog(QWidget *parent) :
		QDialog(parent),
		ui(new Ui::AddBoardDialog) {
	ui->setupUi(this);

	ui->discoveredBoardScrollArea->setWidgetResizable(true);
	ui->discoveredBoardScrollArea->setWidget(ui->discoveredBoardFrame);

	connect(this, &QDialog::accepted, this, &AddBoardDialog::onAccepted);
	connect(this, &QDialog::finished, this, [=](int result) { hideBoardEditor(); });

	// Button box buttons
	connect(ui->stackedWidget, &QStackedWidget::currentChanged, this, [=](int index) {
		if (index == 0) {
			ui->cancelButton->setText("Cancel");

			ui->nextButton->setText("Next");
			ui->nextButton->setEnabled(false);
		} else if (index == 1) {
			ui->cancelButton->setText("Back");

			ui->nextButton->setText("Create");
			ui->nextButton->setEnabled(true);
		}
	});

	connect(ui->cancelButton, &QPushButton::clicked, this, [=](bool checked) {
		if (ui->stackedWidget->currentIndex() == 0) {
			reject();
		} else if (ui->stackedWidget->currentIndex() == 1) {
			hideBoardEditor();
		}
	});

	ui->nextButton->setDefault(true);
	connect(ui->nextButton, &QPushButton::clicked, this, [=](bool checked) {
		if (ui->stackedWidget->currentIndex() == 1) {
			accept();
		}
	});

	// Board Discovery
	eosDiscovery = new EosDiscovery();
	connect(eosDiscovery, &BoardDiscovery::boardFound, this, [=](const QHostAddress &address, const int &port, const QString &uid, const QString &name) {
		if (!uidsFound.contains(uid)) {
			QSharedPointer<EosSettings> boardSettings = QSharedPointer<EosSettings>::create();

			boardSettings->setIp(address.toString());
			boardSettings->setName(name);

			onBoardFound(boardSettings);

			// For whatever reason, the board has a tendency to reply multiple times, so we want to just ignore subsequent responses from the same board
			// TODO: It might be a better idea to reconfigure the existing button when another response is recieved rather than just ignoring it
			uidsFound.append(uid);
		}
	});

	// Model Buttons
	connect(ui->modelButtonEos, &QPushButton::clicked, this, [=](bool checked) {
		QSharedPointer<EosSettings> boardSettings = QSharedPointer<EosSettings>::create();
		showBoardEditor(boardSettings);
	});
}

AddBoardDialog::~AddBoardDialog() {
	delete ui;
}

void AddBoardDialog::scanForBoards() {
	eosDiscovery->queryBoards();
}

void AddBoardDialog::onBoardFound(QSharedPointer<BoardSettings> boardSettings) {
	// Create a board button
	QPushButton *button = new QPushButton();
	ui->discoveredBoardList->layout()->addWidget(button);

	// Set up the button
	button->setText(boardSettings->getName());

	// Connect the button clicked signal
	connect(button, &QPushButton::clicked, this, [=](bool value) mutable {
		showBoardEditor(boardSettings);
	});
}

void AddBoardDialog::showBoardEditor(QSharedPointer<BoardSettings> boardSettings) {
	settingsBeingEdited.swap(boardSettings);
	settingsForm = settingsBeingEdited->createSettingsForm();

	ui->settingsEditorPage->layout()->addWidget(settingsForm);
	ui->stackedWidget->setCurrentIndex(1);
}

void AddBoardDialog::hideBoardEditor() {
	ui->stackedWidget->setCurrentIndex(0);

	if (settingsForm) {
		ui->settingsEditorPage->layout()->removeWidget(settingsForm);
		settingsForm->deleteLater();
		settingsForm = nullptr;
	}
}

void AddBoardDialog::onAccepted() {
	emit boardCreated(settingsBeingEdited);
}
