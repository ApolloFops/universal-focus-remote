#include "addboarddialog.h"
#include "boards/etc/eos/eosdiscovery.h"
#include "ui_addboarddialog.h"

#include <QPushButton>

AddBoardDialog::AddBoardDialog(QWidget *parent) :
		QDialog(parent),
		ui(new Ui::AddBoardDialog) {
	ui->setupUi(this);

	ui->scrollArea->setWidgetResizable(true);
	ui->scrollArea->setWidget(ui->scrollFrame);

	connect(this, &QDialog::accepted, this, &AddBoardDialog::onAccepted);

	eosDiscovery = new EosDiscovery();
	connect(eosDiscovery, &BoardDiscovery::boardFound, this, [=](const QHostAddress &address, const int &port, const QString &uid, const QString &name) {
		if (!uidsFound.contains(uid)) {
			EosSettings *boardSettings = new EosSettings();

			boardSettings->setIp(address.toString());
			boardSettings->setName(name);

			onBoardFound(boardSettings);

			// For whatever reason, the board has a tendency to reply multiple times, so we want to just ignore subsequent responses from the same board
			// TODO: It might be a better idea to reconfigure the existing button when another response is recieved rather than just ignoring it
			uidsFound.append(uid);
		}
	});
}

AddBoardDialog::~AddBoardDialog() {
	delete ui;
}

void AddBoardDialog::scanForBoards() {
	eosDiscovery->queryBoards();
}

void AddBoardDialog::onBoardFound(EosSettings *boardSettings) {
	// Create a board button
	QPushButton *button = new QPushButton();
	ui->boardList->layout()->addWidget(button);

	// Set up the button
	button->setText(boardSettings->getName());

	// Connect the button clicked signal
	connect(button, &QPushButton::clicked, this, [=](bool value) {
		ui->hostnameEdit->setText(boardSettings->getIp());
		ui->boardNameEdit->setText(boardSettings->getName());
	});
}

void AddBoardDialog::onAccepted() {
	EosSettings *settings = new EosSettings();

	settings->setName(ui->boardNameEdit->text());
	settings->setIp(ui->hostnameEdit->text());

	ui->boardNameEdit->clear();
	ui->hostnameEdit->clear();

	emit boardCreated(settings);
}
