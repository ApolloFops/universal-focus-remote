#include "eoskeypadform.h"
#include "ui_eoskeypadform.h"

#define setupActionButton(button, action) \
	action->setupActionButton(button);

EosKeypadForm::EosKeypadForm(EosForm *eosForm, QWidget *parent) :
		QWidget(parent),
		ui(new Ui::EosKeypadForm) {
	ui->setupUi(this);

	// Bind actions to the buttons
	setupActionButton(ui->key0, eosForm->board->keyAction0);
	setupActionButton(ui->key1, eosForm->board->keyAction1);
	setupActionButton(ui->key2, eosForm->board->keyAction2);
	setupActionButton(ui->key3, eosForm->board->keyAction3);
	setupActionButton(ui->key4, eosForm->board->keyAction4);
	setupActionButton(ui->key5, eosForm->board->keyAction5);
	setupActionButton(ui->key6, eosForm->board->keyAction6);
	setupActionButton(ui->key7, eosForm->board->keyAction7);
	setupActionButton(ui->key8, eosForm->board->keyAction8);
	setupActionButton(ui->key9, eosForm->board->keyAction9);
	setupActionButton(ui->keyAbout, eosForm->board->keyActionAbout);
	setupActionButton(ui->keyAssert, eosForm->board->keyActionAssert);
	setupActionButton(ui->keyAt, eosForm->board->keyActionAt);
	setupActionButton(ui->keyBeamPalette, eosForm->board->keyActionBeamPalette);
	setupActionButton(ui->keyBlock, eosForm->board->keyActionBlock);
	setupActionButton(ui->keyCapture, eosForm->board->keyActionCapture);
	setupActionButton(ui->keyClear, eosForm->board->keyActionClear);
	setupActionButton(ui->keyColorPalette, eosForm->board->keyActionColorPalette);
	setupActionButton(ui->keyCopyTo, eosForm->board->keyActionCopyTo);
	setupActionButton(ui->keyCue, eosForm->board->keyActionCue);
	setupActionButton(ui->keyDecimal, eosForm->board->keyActionDecimal);
	setupActionButton(ui->keyDelay, eosForm->board->keyActionDelay);
	setupActionButton(ui->keyDelete, eosForm->board->keyActionDelete);
	setupActionButton(ui->keyEffect, eosForm->board->keyActionEffect);
	setupActionButton(ui->keyEnter, eosForm->board->keyActionEnter);
	setupActionButton(ui->keyFan, eosForm->board->keyActionFan);
	setupActionButton(ui->keyFocusPalette, eosForm->board->keyActionFocusPalette);
	setupActionButton(ui->keyFull, eosForm->board->keyActionFull);
	setupActionButton(ui->keyGoToCue, eosForm->board->keyActionGoToCue);
	setupActionButton(ui->keyGroup, eosForm->board->keyActionGroup);
	setupActionButton(ui->keyHigh, eosForm->board->keyActionHigh);
	setupActionButton(ui->keyHome, eosForm->board->keyActionHome);
	setupActionButton(ui->keyIntensityPalette, eosForm->board->keyActionIntensityPalette);
	setupActionButton(ui->keyLabelNote, eosForm->board->keyActionLabelNote);
	setupActionButton(ui->keyLast, eosForm->board->keyActionLast);
	setupActionButton(ui->keyLevel, eosForm->board->keyActionLevel);
	setupActionButton(ui->keyMark, eosForm->board->keyActionMark);
	setupActionButton(ui->keyMinus, eosForm->board->keyActionMinus);
	setupActionButton(ui->keyNext, eosForm->board->keyActionNext);
	setupActionButton(ui->keyOffset, eosForm->board->keyActionOffset);
	setupActionButton(ui->keyOut, eosForm->board->keyActionOut);
	setupActionButton(ui->keyPark, eosForm->board->keyActionPark);
	setupActionButton(ui->keyPart, eosForm->board->keyActionPart);
	setupActionButton(ui->keyPath, eosForm->board->keyActionPath);
	setupActionButton(ui->keyPercentMinus, eosForm->board->keyActionPercentMinus);
	setupActionButton(ui->keyPercentPlus, eosForm->board->keyActionPercentPlus);
	setupActionButton(ui->keyPlus, eosForm->board->keyActionPlus);
	setupActionButton(ui->keyPreset, eosForm->board->keyActionPreset);
	setupActionButton(ui->keyQOnly, eosForm->board->keyActionQOnly);
	setupActionButton(ui->keyQuery, eosForm->board->keyActionQuery);
	setupActionButton(ui->keyRecallFrom, eosForm->board->keyActionRecallFrom);
	setupActionButton(ui->keyRecord, eosForm->board->keyActionRecord);
	setupActionButton(ui->keyRecordOnly, eosForm->board->keyActionRecordOnly);
	setupActionButton(ui->keyRemDim, eosForm->board->keyActionRemDim);
	setupActionButton(ui->keySelectActive, eosForm->board->keyActionSelectActive);
	setupActionButton(ui->keySelectLast, eosForm->board->keyActionSelectLast);
	setupActionButton(ui->keySelectManual, eosForm->board->keyActionSelectManual);
	setupActionButton(ui->keyShift, eosForm->board->keyActionShift);
	setupActionButton(ui->keySlash, eosForm->board->keyActionSlash);
	setupActionButton(ui->keySneak, eosForm->board->keyActionSneak);
	setupActionButton(ui->keySub, eosForm->board->keyActionSub);
	setupActionButton(ui->keyThru, eosForm->board->keyActionThru);
	setupActionButton(ui->keyTime, eosForm->board->keyActionTime);
	setupActionButton(ui->keyTrace, eosForm->board->keyActionTrace);
	setupActionButton(ui->keyUpdate, eosForm->board->keyActionUpdate);
}

EosKeypadForm::~EosKeypadForm() {
	delete ui;
}
