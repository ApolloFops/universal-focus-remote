#pragma once

#include <QWidget>

class BoardSettings;

class BoardSettingsForm : public QWidget {
	Q_OBJECT
public:
	explicit BoardSettingsForm(QWidget *parent = nullptr);

	BoardSettings *getSettings();

signals:

protected:
	void setSettings(BoardSettings *settings);

private:
	BoardSettings *settings;
};
