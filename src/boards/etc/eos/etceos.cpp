#include "etceos.h"

#define SETUP_KEY_ACTION(action, keyString, shortcutKey) \
	action = new QBooleanAction();                       \
	action->setShortcut(shortcutKey);                    \
	setupKeyAction(action, keyString);

ETCEos::ETCEos(EosSettings *settings, QObject *parent) :
		QObject{ parent } {
	boardSettings = settings;

	connect(&iface, &QOscTcpInterface::connected, this, &ETCEos::setupConnection);

	// Set up keypad actions
	SETUP_KEY_ACTION(keyAction0, "0", new QKeySequence(Qt::Key_0));
	SETUP_KEY_ACTION(keyAction1, "1", new QKeySequence(Qt::Key_1));
	SETUP_KEY_ACTION(keyAction2, "2", new QKeySequence(Qt::Key_2));
	SETUP_KEY_ACTION(keyAction3, "3", new QKeySequence(Qt::Key_3));
	SETUP_KEY_ACTION(keyAction4, "4", new QKeySequence(Qt::Key_4));
	SETUP_KEY_ACTION(keyAction5, "5", new QKeySequence(Qt::Key_5));
	SETUP_KEY_ACTION(keyAction6, "6", new QKeySequence(Qt::Key_6));
	SETUP_KEY_ACTION(keyAction7, "7", new QKeySequence(Qt::Key_7));
	SETUP_KEY_ACTION(keyAction8, "8", new QKeySequence(Qt::Key_8));
	SETUP_KEY_ACTION(keyAction9, "9", new QKeySequence(Qt::Key_9));
	SETUP_KEY_ACTION(keyActionAbout, "about", new QKeySequence(Qt::Key_Y));
	SETUP_KEY_ACTION(keyActionAddress, "address", new QKeySequence("Alt+A"));
	SETUP_KEY_ACTION(keyActionAssert, "assert", new QKeySequence("Ctrl+W"));
	SETUP_KEY_ACTION(keyActionAt, "at", new QKeySequence(Qt::Key_A));
	SETUP_KEY_ACTION(keyActionBeamPalette, "beam_palette", new QKeySequence("Alt+B"));
	SETUP_KEY_ACTION(keyActionBlind, "blind", new QKeySequence(Qt::Key_F2));
	SETUP_KEY_ACTION(keyActionBlock, "block", new QKeySequence(Qt::Key_B));
	SETUP_KEY_ACTION(keyActionCapture, "capture", new QKeySequence("Ctrl+Alt+P"));
	SETUP_KEY_ACTION(keyActionClear, "clear_cmd", new QKeySequence(Qt::Key_Backspace));
	SETUP_KEY_ACTION(keyActionColorPalette, "color_palette", new QKeySequence("Alt+C"));
	SETUP_KEY_ACTION(keyActionCopyTo, "copy_to", new QKeySequence(Qt::Key_C));
	SETUP_KEY_ACTION(keyActionCue, "cue", new QKeySequence(Qt::Key_Q));
	SETUP_KEY_ACTION(keyActionData, "data", new QKeySequence("Ctrl+D"));
	SETUP_KEY_ACTION(keyActionDecimal, ".", new QKeySequence(Qt::Key_Period));
	SETUP_KEY_ACTION(keyActionDelay, "delay", new QKeySequence(Qt::Key_D));
	SETUP_KEY_ACTION(keyActionDelete, "delete", new QKeySequence(Qt::Key_Delete));
	SETUP_KEY_ACTION(keyActionDisplayTiming, "display_timing", new QKeySequence("Ctrl+Alt+I"));
	SETUP_KEY_ACTION(keyActionDisplays, "displays", new QKeySequence(Qt::Key_F9));
	SETUP_KEY_ACTION(keyActionEffect, "effect", new QKeySequence("Alt+E"));
	SETUP_KEY_ACTION(keyActionEnter, "enter", new QKeySequence(Qt::Key_Return));
	SETUP_KEY_ACTION(keyActionEscape, "escape", new QKeySequence(Qt::Key_Escape));
	SETUP_KEY_ACTION(keyActionExpand, "expand", new QKeySequence(Qt::Key_F5));
	SETUP_KEY_ACTION(keyActionFader, "fader", nullptr);
	SETUP_KEY_ACTION(keyActionFan, "fan_", new QKeySequence(Qt::Key_W));
	SETUP_KEY_ACTION(keyActionFlexichannelMode, "flexichannel_mode", new QKeySequence(Qt::Key_F3));
	SETUP_KEY_ACTION(keyActionFocusPalette, "focus_palette", new QKeySequence("Alt+F"));
	SETUP_KEY_ACTION(keyActionFormat, "format", new QKeySequence(Qt::Key_F4));
	SETUP_KEY_ACTION(keyActionFull, "full", new QKeySequence(Qt::Key_F));
	SETUP_KEY_ACTION(keyActionGoToCue, "go_to_cue", new QKeySequence("Ctrl+G"));
	SETUP_KEY_ACTION(keyActionGroup, "group", new QKeySequence(Qt::Key_G));
	SETUP_KEY_ACTION(keyActionHelp, "help", new QKeySequence("Alt+/"));
	SETUP_KEY_ACTION(keyActionHigh, "highlight", new QKeySequence(Qt::Key_Backslash));
	SETUP_KEY_ACTION(keyActionHome, "home", new QKeySequence(Qt::Key_Home));
	SETUP_KEY_ACTION(keyActionIntensityPalette, "intensity_palette", new QKeySequence("Alt+I"));
	SETUP_KEY_ACTION(keyActionLabelNote, "label", new QKeySequence(Qt::Key_L));
	SETUP_KEY_ACTION(keyActionLast, "last", new QKeySequence(Qt::Key_PageUp));
	SETUP_KEY_ACTION(keyActionLearn, "learn", new QKeySequence("Alt+L"));
	SETUP_KEY_ACTION(keyActionLevel, "level", new QKeySequence(Qt::CTRL | Qt::Key_V));
	SETUP_KEY_ACTION(keyActionLive, "live", new QKeySequence(Qt::Key_F1));
	SETUP_KEY_ACTION(keyActionMacro, "macro", new QKeySequence(Qt::Key_M));
	SETUP_KEY_ACTION(keyActionMark, "automark_off", nullptr);
	SETUP_KEY_ACTION(keyActionMinus, "-", new QKeySequence(Qt::Key_Minus));
	SETUP_KEY_ACTION(keyActionMoreSoftkeys, "more_softkeys", new QKeySequence("Alt+7"));
	SETUP_KEY_ACTION(keyActionNext, "next", new QKeySequence(Qt::Key_PageDown));
	SETUP_KEY_ACTION(keyActionOffset, "offset", new QKeySequence("Ctrl+O"));
	SETUP_KEY_ACTION(keyActionOut, "out", new QKeySequence(Qt::Key_O));
	SETUP_KEY_ACTION(keyActionPageDown, "page_down", new QKeySequence(Qt::Key_Down));
	SETUP_KEY_ACTION(keyActionPageLeft, "page_left", new QKeySequence(Qt::Key_Left));
	SETUP_KEY_ACTION(keyActionPageRight, "page_right", new QKeySequence(Qt::Key_Right));
	SETUP_KEY_ACTION(keyActionPageUp, "page_up", new QKeySequence(Qt::Key_Up));
	SETUP_KEY_ACTION(keyActionPark, "park", new QKeySequence("Alt+K"));
	SETUP_KEY_ACTION(keyActionPart, "part", new QKeySequence(Qt::Key_P));
	// TODO: Fix these
	SETUP_KEY_ACTION(keyActionPath, "path", new QKeySequence("Ctrl+Alt+W"));
	SETUP_KEY_ACTION(keyActionPercentMinus, "-%", new QKeySequence("Ctrl+t"));
	SETUP_KEY_ACTION(keyActionPercentPlus, "+%", new QKeySequence(Qt::CTRL | Qt::ALT | Qt::Key_Equal));
	SETUP_KEY_ACTION(keyActionPlus, "+", new QKeySequence(Qt::Key_Equal));
	SETUP_KEY_ACTION(keyActionPreset, "preset", new QKeySequence("Alt+P"));
	SETUP_KEY_ACTION(keyActionQOnly, "cueonlytrack", new QKeySequence(Qt::Key_X));
	SETUP_KEY_ACTION(keyActionQuery, "query", new QKeySequence("Ctrl+Q"));
	SETUP_KEY_ACTION(keyActionRecallFrom, "recall_from", new QKeySequence(Qt::Key_E));
	SETUP_KEY_ACTION(keyActionRecord, "record", new QKeySequence(Qt::Key_R));
	SETUP_KEY_ACTION(keyActionRecordOnly, "record_only", new QKeySequence("Ctrl+R"));
	SETUP_KEY_ACTION(keyActionRemDim, "rem_dim", new QKeySequence(Qt::Key_H));
	SETUP_KEY_ACTION(keyActionScrollLock, "page_mode", new QKeySequence("Ctrl+6"));
	SETUP_KEY_ACTION(keyActionSelect, "select", new QKeySequence(Qt::CTRL | Qt::Key_Enter));
	SETUP_KEY_ACTION(keyActionSelectActive, "select_active", new QKeySequence(Qt::CTRL | Qt::Key_A));
	SETUP_KEY_ACTION(keyActionSelectLast, "select_last", new QKeySequence(Qt::CTRL | Qt::Key_L));
	SETUP_KEY_ACTION(keyActionSelectManual, "select_manual", new QKeySequence(Qt::CTRL | Qt::Key_M));
	SETUP_KEY_ACTION(keyActionSetup, "open_setup", new QKeySequence(Qt::ALT | Qt::Key_S));
	SETUP_KEY_ACTION(keyActionShift, "shift", new QKeySequence(Qt::Key_Shift));
	SETUP_KEY_ACTION(keyActionSlash, "\\", new QKeySequence(Qt::Key_Slash));
	SETUP_KEY_ACTION(keyActionSnapshot, "snapshot", new QKeySequence("Ctrl+S"));
	SETUP_KEY_ACTION(keyActionSneak, "sneak", new QKeySequence(Qt::Key_N));
	SETUP_KEY_ACTION(keyActionSoft1, "softkey_1", new QKeySequence("Alt+1"));
	SETUP_KEY_ACTION(keyActionSoft2, "softkey_2", new QKeySequence("Alt+2"));
	SETUP_KEY_ACTION(keyActionSoft3, "softkey_3", new QKeySequence("Alt+3"));
	SETUP_KEY_ACTION(keyActionSoft4, "softkey_4", new QKeySequence("Alt+4"));
	SETUP_KEY_ACTION(keyActionSoft5, "softkey_5", new QKeySequence("Alt+5"));
	SETUP_KEY_ACTION(keyActionSoft6, "softkey_6", new QKeySequence("Alt+6"));
	SETUP_KEY_ACTION(keyActionStage, "staging_mode", new QKeySequence(Qt::Key_F6));
	SETUP_KEY_ACTION(keyActionSub, "sub", new QKeySequence(Qt::Key_S));
	SETUP_KEY_ACTION(keyActionTab, "tab", new QKeySequence(Qt::Key_Tab));
	SETUP_KEY_ACTION(keyActionThru, "thru", new QKeySequence(Qt::Key_T));
	SETUP_KEY_ACTION(keyActionTime, "time", new QKeySequence(Qt::Key_I));
	SETUP_KEY_ACTION(keyActionTrace, "trace", new QKeySequence(Qt::Key_J));
	SETUP_KEY_ACTION(keyActionUndo, "undo", new QKeySequence("Ctrl+X"));
	SETUP_KEY_ACTION(keyActionUpdate, "update", new QKeySequence(Qt::Key_U));

	// Set up command line notifications
	iface.connect("/eos/out/cmd", [=](const QOscMessage &msg, const QHostAddress &sender) {
		emit userCommandLineChanged(msg.toString());
	});

	// Set up softkey notifications
	connect(&iface, &QOscInterface::messageReceived, this, [=](const QOscMessage &message, const QHostAddress &sender) {
		static QRegularExpression expression("\\/eos\\/out\\/softkey\\/(\\d+)");
		QRegularExpressionMatch match = expression.match(message.pattern());
		if (match.hasMatch()) {
			qint32 softkeyIndex = match.captured(1).toInt();
			QString softkeyLabel = message.toString(0);

			softkeyLabels[softkeyIndex] = softkeyLabel;
			emit softkeyLabelChanged(softkeyIndex, softkeyLabel);
		}
	});

	// Set up wheel notifications
	connect(&iface, &QOscInterface::messageReceived, this, [=](const QOscMessage &message, const QHostAddress &sender) {
		static QRegularExpression expression("\\/eos\\/out\\/active\\/wheel\\/(\\d+)");
		static QRegularExpression paramExpression("(.*)\\s{2,}\\[(\\d+)\\]");
		QRegularExpressionMatch match = expression.match(message.pattern());
		if (match.hasMatch()) {
			qint32 wheelIndex = match.captured(1).toInt();
			QString wheelInfo = message.toString(0);
			qint32 wheelGroup = message.toInt(1);
			qint32 wheelLevel = message.toInt(2);

			QRegularExpressionMatch infoMatch = paramExpression.match(wheelInfo);
			QString wheelParam = infoMatch.captured(1);

			if (wheelParam.isEmpty()) {
				channelParams.remove(wheelIndex);
				emit wheelRemoved(wheelIndex);
			} else {
				channelParams[wheelIndex].first = wheelParam;
				channelParams[wheelIndex].second = wheelLevel;
				emit wheelUpdated(wheelIndex);
			}
		}
	});

	// Syncronize patch data
	iface.connect("/eos/out/get/patch/count", [=](const QOscMessage &message, const QHostAddress &sender) {
		QOscBundle bundle;
		for (int i = 0; i < message.toInt(0); i++) {
			bundle << QOscMessage("/eos/get/patch/index", i);
		}
		iface.send(bundle);
	});

	// Set up patch data
	connect(&iface, &QOscInterface::messageReceived, this, [=](const QOscMessage &message, const QHostAddress &sender) {
		static QRegularExpression expression("\\/eos\\/out\\/get\\/patch\\/(\\d+)\\/(\\d+)\\/list\\/(\\d+)\\/(\\d+)");
		QRegularExpressionMatch match = expression.match(message.pattern());
		if (match.hasMatch()) {
			EosChannel *channel = new EosChannel(this);
			channel->channelNumber = match.captured(1).toInt();
			channel->partNumber = match.captured(2).toInt();
			qint32 listIndex = match.captured(3).toInt();
			qint32 listCount = match.captured(4).toInt();
			channel->uid = message.toString(1);
			channel->label = message.toString(2);
			channel->fixtureManufacturer = message.toString(3);
			channel->fixtureModel = message.toString(4);
			channel->address = message.toInt(5);
			channel->intensityAddress = message.toInt(6);
			channel->level = message.toInt(7);
			channel->oscGel = message.toString(8);
			channel->text1 = message.toString(9);
			channel->text2 = message.toString(10);
			channel->text3 = message.toString(11);
			channel->text4 = message.toString(12);
			channel->text5 = message.toString(13);
			channel->text6 = message.toString(14);
			channel->text7 = message.toString(15);
			channel->text8 = message.toString(16);
			channel->text9 = message.toString(17);
			channel->text10 = message.toString(18);
			channel->partCount = message.toInt(19);

			channelList[channel->uid] = channel;

			emit channel->updated();
			emit patchUpdated();
		}
	});

	// Patch notifications
	connect(&iface, &QOscInterface::messageReceived, this, [=](const QOscMessage &message, const QHostAddress &sender) {
		static QRegularExpression expression("\\/eos\\/out\\/notify\\/patch\\/list\\/(\\d+)\\/(\\d+)");
		QRegularExpressionMatch match = expression.match(message.pattern());
		if (match.hasMatch()) {
			// This isn't ideal but it works
			// TODO: Implement a system to only remove channels that no longer exist instead of rebuilding the entire list every sync
			channelList.clear();

			// Get the number of items in the patch. When the count is recieved, a synchronization is triggered by the code above.
			// TODO: Only query items that changed (this will likely require some changes on ETC's side)
			QOscMessage msg("/eos/get/patch/count", 1);
			iface.send(msg);

			qint32 listIndex = match.captured(1).toInt();
			qint32 listCount = match.captured(2).toInt();
		}
	});

	// Bind the network interface so you can send and get messages
	qDebug() << "Connecting to board with IP"
			 << boardSettings->getIp();
	iface.setRemoteAddress(boardSettings->getIp());
	iface.setRemotePort(3037);
}

QString ETCEos::getSoftkeyLabel(qint32 index) {
	return softkeyLabels[index];
}

QMap<qint32, QPair<QString, qint32>> ETCEos::getChannelParams() {
	return channelParams;
}

QMap<QString, EosChannel *> ETCEos::getChannelData() {
	return channelList;
}

void ETCEos::setKeyPressed(QString keyName, bool pressed) {
	QOscMessage msg(QString("/eos/key/" + keyName), pressed);
	iface.send(msg);
}

void ETCEos::setParameterValue(QString name, qint32 value) {
	QOscMessage msg(QString("/eos/param/" + name), value);
	iface.send(msg);
}

void ETCEos::setupKeyAction(QBooleanAction *action, QString keyName) {
	connect(action, &QBooleanAction::valueChanged, this, [=](bool value) { setKeyPressed(keyName, value); });
}

void ETCEos::setupConnection() {
	qDebug() << "Connected to board";

	QOscBundle bundle;
	bundle << QOscMessage("/eos/user", 1);
	bundle << QOscMessage("/eos/subscribe", 1);

	// Get data counts for synchronization
	bundle << QOscMessage("/eos/get/patch/count", 1);

	iface.send(bundle);
}

void ETCEos::queryPatchData(qint32 index) {
	QOscMessage msg("/eos/get/patch/index", index);
	iface.send(msg);
}
