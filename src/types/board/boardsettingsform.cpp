#include "boardsettingsform.h"

BoardSettingsForm::BoardSettingsForm(QWidget *parent) : QWidget{ parent } {
}

void BoardSettingsForm::setSettings(QSharedPointer<BoardSettings> settings) {
	this->settings = settings;
}