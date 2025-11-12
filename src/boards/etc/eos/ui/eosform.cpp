#include "eosform.h"
#include "eossyntaxhighlighter.h"
#include "keypad/eoskeypadform.h"
#include "lampcontrols/eoslampcontrolsform.h"
#include "patch/eospatchform.h"
#include "ui_eosform.h"

#include "../widgets/tabs/qboardtabarea.h"
#include <QTabBar>
#include <QTabWidget>
#include <QToolButton>

EosForm::EosForm(ETCEos* board, QWidget *parent) : QWidget(parent), ui(new Ui::EosForm) {
	this->board = board;

	ui->setupUi(this);

	// Set up the command line
	QFontMetrics metrics(ui->commandLine->font());
	int lineHeight = metrics.lineSpacing();
	ui->commandLine->setFixedHeight(lineHeight + 10);
	ui->commandLine->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	connect(board, &ETCEos::userCommandLineChanged, ui->commandLine, [=](QString text) { ui->commandLine->setText(text.replace('#', "♦")); });
	new EosSyntaxHighlighter(ui->commandLine->document());

	// Set up the tab area
	QBoardTabArea *tabArea = new QBoardTabArea();
	tabArea->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
	ui->verticalLayout->insertWidget(1, tabArea);

	// Set up the tab list
	tabArea->addTabToList("Keypad", [=]() -> QWidget * {
		EosKeypadForm *keypadForm = new EosKeypadForm(this);
		return keypadForm;
	});

	tabArea->addTabToList("Patch", [=]() -> QWidget * {
		EosPatchForm *patchForm = new EosPatchForm(this);
		return patchForm;
	});

	tabArea->addTabToList("Lamp Controls", [=]() -> QWidget * {
		EosLampControlsForm *lampControlsForm = new EosLampControlsForm(this);
		return lampControlsForm;
	});
}

EosForm::~EosForm() {
	delete ui;
}
