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
	setupActionButton(ui->keyAddress, eosForm->board->keyActionAddress);
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
	setupActionButton(ui->keyFader, eosForm->board->keyActionFader);
	setupActionButton(ui->keyFan, eosForm->board->keyActionFan);
	setupActionButton(ui->keyFocusPalette, eosForm->board->keyActionFocusPalette);
	setupActionButton(ui->keyFull, eosForm->board->keyActionFull);
	setupActionButton(ui->keyGoToCue, eosForm->board->keyActionGoToCue);
	setupActionButton(ui->keyGroup, eosForm->board->keyActionGroup);
	setupActionButton(ui->keyHelp, eosForm->board->keyActionHelp);
	setupActionButton(ui->keyHigh, eosForm->board->keyActionHigh);
	setupActionButton(ui->keyHome, eosForm->board->keyActionHome);
	setupActionButton(ui->keyIntensityPalette, eosForm->board->keyActionIntensityPalette);
	setupActionButton(ui->keyLabelNote, eosForm->board->keyActionLabelNote);
	setupActionButton(ui->keyLast, eosForm->board->keyActionLast);
	setupActionButton(ui->keyLearn, eosForm->board->keyActionLearn);
	setupActionButton(ui->keyLevel, eosForm->board->keyActionLevel);
	setupActionButton(ui->keyMacro, eosForm->board->keyActionMacro);
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
	setupActionButton(ui->keySnapshot, eosForm->board->keyActionSnapshot);
	setupActionButton(ui->keySneak, eosForm->board->keyActionSneak);
	setupActionButton(ui->keySoft1, eosForm->board->keyActionSoft1);
	setupActionButton(ui->keySoft2, eosForm->board->keyActionSoft2);
	setupActionButton(ui->keySoft3, eosForm->board->keyActionSoft3);
	setupActionButton(ui->keySoft4, eosForm->board->keyActionSoft4);
	setupActionButton(ui->keySoft5, eosForm->board->keyActionSoft5);
	setupActionButton(ui->keySoft6, eosForm->board->keyActionSoft6);
	setupActionButton(ui->keySub, eosForm->board->keyActionSub);
	setupActionButton(ui->keyThru, eosForm->board->keyActionThru);
	setupActionButton(ui->keyTime, eosForm->board->keyActionTime);
	setupActionButton(ui->keyTrace, eosForm->board->keyActionTrace);
	setupActionButton(ui->keyUpdate, eosForm->board->keyActionUpdate);

	softKeys[1] = ui->keySoft1;
	softKeys[2] = ui->keySoft2;
	softKeys[3] = ui->keySoft3;
	softKeys[4] = ui->keySoft4;
	softKeys[5] = ui->keySoft5;
	softKeys[6] = ui->keySoft6;

	for (auto [key, value] : softKeys.asKeyValueRange()) {
		value->setText(eosForm->board->getSoftkeyLabel(key));
	}

	connect(eosForm->board, &ETCEos::softkeyLabelChanged, this, [=](qint32 index, QString label) {
		if (softKeys.contains(index)) {
			softKeys[index]->setText(label);
		}
	});
}

EosKeypadForm::~EosKeypadForm() {
	delete ui;
}
