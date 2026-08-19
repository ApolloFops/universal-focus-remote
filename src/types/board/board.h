#pragma once

#include "boardsettings.h"
#include <QObject>

class Board : public QObject {
	Q_OBJECT

	Q_PROPERTY(QString showName READ getShowName WRITE setShowName NOTIFY showNameChanged FINAL)

public:
	explicit Board(QSharedPointer<BoardSettings> settings, QObject *parent = nullptr);

	QSharedPointer<BoardSettings> getSettings();

	QString getBoardName();
	QString getShowName();

signals:
	void showNameChanged(QString name);

protected:
	void setShowName(QString name);

private:
	QSharedPointer<BoardSettings> settings;

	QString showName;
};
