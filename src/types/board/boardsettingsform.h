#pragma once

#include <QWidget>

class BoardSettings;

class BoardSettingsForm : public QWidget {
	Q_OBJECT
public:
	explicit BoardSettingsForm(QWidget *parent = nullptr);

signals:

protected:
	void setSettings(QSharedPointer<BoardSettings> settings);

private:
	QSharedPointer<BoardSettings> settings;
};
