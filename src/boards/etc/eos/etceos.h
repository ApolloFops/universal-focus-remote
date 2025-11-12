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

	QString getSoftkeyLabel(qint32 index);
	QMap<qint32, QPair<QString, qint32>> getChannelParams();
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
	QBooleanAction *keyActionBlind;
	QBooleanAction *keyActionBlock;
	QBooleanAction *keyActionCapture;
	QBooleanAction *keyActionClear;
	QBooleanAction *keyActionColorPalette;
	QBooleanAction *keyActionCopyTo;
	QBooleanAction *keyActionCue;
	QBooleanAction *keyActionData;
	QBooleanAction *keyActionDecimal;
	QBooleanAction *keyActionDelay;
	QBooleanAction *keyActionDelete;
	QBooleanAction *keyActionDisplayTiming;
	QBooleanAction *keyActionDisplays;
	QBooleanAction *keyActionEffect;
	QBooleanAction *keyActionEnter;
	QBooleanAction *keyActionEscape;
	QBooleanAction *keyActionExpand;
	QBooleanAction *keyActionFader;
	QBooleanAction *keyActionFan;
	QBooleanAction *keyActionFlexichannelMode;
	QBooleanAction *keyActionFocusPalette;
	QBooleanAction *keyActionFormat;
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
	QBooleanAction *keyActionLive;
	QBooleanAction *keyActionMacro;
	QBooleanAction *keyActionMark;
	QBooleanAction *keyActionMinus;
	QBooleanAction *keyActionMoreSoftkeys;
	QBooleanAction *keyActionNext;
	QBooleanAction *keyActionOffset;
	QBooleanAction *keyActionOut;
	QBooleanAction *keyActionPageDown;
	QBooleanAction *keyActionPageLeft;
	QBooleanAction *keyActionPageRight;
	QBooleanAction *keyActionPageUp;
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
	QBooleanAction *keyActionScrollLock;
	QBooleanAction *keyActionSelect;
	QBooleanAction *keyActionSelectActive;
	QBooleanAction *keyActionSelectLast;
	QBooleanAction *keyActionSelectManual;
	QBooleanAction *keyActionSetup;
	QBooleanAction *keyActionShift;
	QBooleanAction *keyActionSlash;
	QBooleanAction *keyActionSnapshot;
	QBooleanAction *keyActionSneak;
	QBooleanAction *keyActionSoft1;
	QBooleanAction *keyActionSoft2;
	QBooleanAction *keyActionSoft3;
	QBooleanAction *keyActionSoft4;
	QBooleanAction *keyActionSoft5;
	QBooleanAction *keyActionSoft6;
	QBooleanAction *keyActionStage;
	QBooleanAction *keyActionSub;
	QBooleanAction *keyActionTab;
	QBooleanAction *keyActionThru;
	QBooleanAction *keyActionTime;
	QBooleanAction *keyActionTrace;
	QBooleanAction *keyActionUndo;
	QBooleanAction *keyActionUpdate;

public slots:
	void setKeyPressed(QString keyName, bool pressed);
	void setParameterValue(QString name, qint32 value);
	void queryPatchData(qint32 index);

signals:
	void userCommandLineChanged(QString text);
	void softkeyLabelChanged(qint32 index, QString label);
	void wheelUpdated(qint32 index);
	void wheelRemoved(qint32 index);
	void patchUpdated();

private:
	QOscTcpInterface iface;
	void setupKeyAction(QBooleanAction *action, QString keyName);
	void setupConnection();

	EosSettings *boardSettings;

	QMap<qint32, QString> softkeyLabels;
	QMap<qint32, QPair<QString, qint32>> channelParams;
	QMap<QString, EosChannel *> channelList;
};
