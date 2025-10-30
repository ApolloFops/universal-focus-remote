#include "boardselector.h"
#include "ui_boardselector.h"

#include "widgets/qdualeventbutton.h"

BoardSelector::BoardSelector(QWidget *parent) :
		QWidget(parent),
		ui(new Ui::BoardSelector) {
	ui->setupUi(this);

	ui->scrollArea->setWidgetResizable(true);
	ui->scrollArea->setWidget(ui->scrollFrame);

	addBoardDialog = new AddBoardDialog();
	connect(ui->addBoardButton, &QPushButton::clicked, this, [=]() {
		addBoardDialog->open();
		addBoardDialog->scanForBoards();
	});
	connect(addBoardDialog, &AddBoardDialog::boardCreated, this, [=](EosSettings *board) { this->addBoard(board); emit boardCreated(board); });
}

BoardSelector::~BoardSelector() {
	delete ui;
}

void BoardSelector::buttonClicked(EosSettings *boardSettings) {
	ETCEos *board = new ETCEos(boardSettings);
	emit boardSelected(new EosForm(board));
}

void BoardSelector::buttonRightClicked(EosSettings *boardSettings) {
	boardSettings->remove();
}

void BoardSelector::addBoard(EosSettings *boardSettings) {
	// Create a board button
	QDualEventButton *button = new QDualEventButton();
	ui->boardList->layout()->addWidget(button);

	// Set up the button
	button->setText(boardSettings->getName());

	// Connect the button clicked signals
	connect(button, &QDualEventButton::clicked, this, [=](bool value) { buttonClicked(boardSettings); });
	connect(button, &QDualEventButton::secondaryClick, this, [=]() { buttonRightClicked(boardSettings); });

	// Connect the board removed signal
	connect(boardSettings, &EosSettings::removed, this, [=]() { ui->boardList->layout()->removeWidget(button); });
}
