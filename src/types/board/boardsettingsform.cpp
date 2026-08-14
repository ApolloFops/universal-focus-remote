#include "boardsettingsform.h"

BoardSettingsForm::BoardSettingsForm(QWidget *parent) : QWidget{ parent } {
}

void BoardSettingsForm::setSettings(BoardSettings *settings) {
	this->settings = settings;
}

BoardSettings *BoardSettingsForm::getSettings() {
	return settings;
}