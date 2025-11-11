#pragma once

#include "../../../actions/qbooleanaction.h"
#include "datatypes/eoschannel.h"
#include "eossettings.h"
#include <QObject>
#include <QOsc>

class ETCEos : public QObject {
	Q_OBJECT

public:
	explicit ETCEos(EosSettings *settings, QObject *parent = nullptr);

	QOscTcpInterface *getInterface() { return &iface; };

	QMap<QString, EosChannel *> getChannelData();

	// Key actions
	QBooleanAction *keyAction0;
	QBooleanAction *keyAction1;
	QBooleanAction *keyAction2;
	QBooleanAction *keyAction3;
	QBooleanAction *keyAction4;
	QBooleanAction *keyAction5;
	QBooleanAction *keyAction6;
	QBooleanAction *keyAction7;
	QBooleanAction *keyAction8;
	QBooleanAction *keyAction9;
	QBooleanAction *keyActionAbout;
	QBooleanAction *keyActionAddress;
	QBooleanAction *keyActionAssert;
	QBooleanAction *keyActionAt;
	QBooleanAction *keyActionBeamPalette;
	QBooleanAction *keyActionBlock;
	QBooleanAction *keyActionCapture;
	QBooleanAction *keyActionClear;
	QBooleanAction *keyActionColorPalette;
	QBooleanAction *keyActionCopyTo;
	QBooleanAction *keyActionCue;
	QBooleanAction *keyActionDecimal;
	QBooleanAction *keyActionDelay;
	QBooleanAction *keyActionDelete;
	QBooleanAction *keyActionEffect;
	QBooleanAction *keyActionEnter;
	QBooleanAction *keyActionFader;
	QBooleanAction *keyActionFan;
	QBooleanAction *keyActionFocusPalette;
	QBooleanAction *keyActionFull;
	QBooleanAction *keyActionGoToCue;
	QBooleanAction *keyActionGroup;
	QBooleanAction *keyActionHelp;
	QBooleanAction *keyActionHigh;
	QBooleanAction *keyActionHome;
	QBooleanAction *keyActionIntensityPalette;
	QBooleanAction *keyActionLabelNote;
	QBooleanAction *keyActionLast;
	QBooleanAction *keyActionLearn;
	QBooleanAction *keyActionLevel;
	QBooleanAction *keyActionMacro;
	QBooleanAction *keyActionMark;
	QBooleanAction *keyActionMinus;
	QBooleanAction *keyActionNext;
	QBooleanAction *keyActionOffset;
	QBooleanAction *keyActionOut;
	QBooleanAction *keyActionPark;
	QBooleanAction *keyActionPart;
	QBooleanAction *keyActionPath;
	QBooleanAction *keyActionPercentPlus;
	QBooleanAction *keyActionPercentMinus;
	QBooleanAction *keyActionPlus;
	QBooleanAction *keyActionPreset;
	QBooleanAction *keyActionQOnly;
	QBooleanAction *keyActionQuery;
	QBooleanAction *keyActionRecallFrom;
	QBooleanAction *keyActionRecord;
	QBooleanAction *keyActionRecordOnly;
	QBooleanAction *keyActionRemDim;
	QBooleanAction *keyActionSelectActive;
	QBooleanAction *keyActionSelectLast;
	QBooleanAction *keyActionSelectManual;
	QBooleanAction *keyActionShift;
	QBooleanAction *keyActionSlash;
	QBooleanAction *keyActionSnapshot;
	QBooleanAction *keyActionSneak;
	QBooleanAction *keyActionSub;
	QBooleanAction *keyActionThru;
	QBooleanAction *keyActionTime;
	QBooleanAction *keyActionTrace;
	QBooleanAction *keyActionUpdate;

public slots:
	void setKeyPressed(QString keyName, bool pressed);
	void queryPatchData(qint32 index);

signals:
	void userCommandLineChanged(QString text);
	void patchUpdated();

private:
	QOscTcpInterface iface;
	void setupKeyAction(QBooleanAction *action, QString keyName);
	void setupConnection();

	EosSettings *boardSettings;

	QMap<QString, EosChannel *> channelList;
};
