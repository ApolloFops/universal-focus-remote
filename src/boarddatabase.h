#pragma once

#include "types/board/boardsettings.h"
#include <QDir>
#include <QObject>

class BoardDatabase : public QObject {
	Q_OBJECT
public:
	explicit BoardDatabase(QDir *boardDir, QObject *parent = nullptr);

	void loadAllBoards();
	void addBoard(QSharedPointer<BoardSettings> boardSettings);

signals:
	void boardAdded(QSharedPointer<BoardSettings> boardSettings);

private:
	QDir *boardDir;
	QList<QSharedPointer<BoardSettings>> boardList;

	bool loadBoard(QString filePath);
	bool saveBoard(QSharedPointer<BoardSettings> boardSettings, QString fileName) const;
};
