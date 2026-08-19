#include "boardselector.h"
#include "ui_boardselector.h"

#include "widgets/qdualeventbutton.h"

BoardSelector::BoardSelector(BoardDatabase *boardDatabase, QWidget *parent) :
		QWidget(parent),
		ui(new Ui::BoardSelector) {
	ui->setupUi(this);

	ui->scrollArea->setWidgetResizable(true);
	ui->scrollArea->setWidget(ui->scrollFrame);

	connect(boardDatabase, &BoardDatabase::boardAdded, this, &BoardSelector::addBoard);

	addBoardDialog = new AddBoardDialog();
	connect(ui->addBoardButton, &QPushButton::clicked, this, [=]() {
		addBoardDialog->open();
		addBoardDialog->scanForBoards();
	});
	connect(addBoardDialog, &AddBoardDialog::boardCreated, this, [=](QSharedPointer<BoardSettings> board) { emit boardCreated(board); });
}

BoardSelector::~BoardSelector() {
	delete ui;
}

void BoardSelector::buttonClicked(QSharedPointer<BoardSettings> boardSettings) {
	ETCEos *board = new ETCEos(qSharedPointerDynamicCast<EosSettings>(boardSettings));
	EosForm *form = new EosForm(board, this->window());
	emit boardSelected(form);
}

void BoardSelector::buttonRightClicked(QSharedPointer<BoardSettings> boardSettings) {
	// boardSettings->remove();
}

void BoardSelector::addBoard(QSharedPointer<BoardSettings> boardSettings) {
	// Create a board button
	QDualEventButton *button = new QDualEventButton();
	ui->boardList->layout()->addWidget(button);

	// Set up the button
	button->setText(boardSettings->getName());

	// Connect the button clicked signals
	connect(button, &QDualEventButton::clicked, this, [=](bool value) { buttonClicked(boardSettings); });
	connect(button, &QDualEventButton::secondaryClick, this, [=]() { buttonRightClicked(boardSettings); });

	// Connect the board removed signal
	// connect(boardSettings, &BoardSettings::removed, this, [=]() { ui->boardList->layout()->removeWidget(button); });
}
