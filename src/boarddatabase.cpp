#include "boarddatabase.h"
#include "boards/etc/eos/eossettings.h"

#include <QFile>

BoardDatabase::BoardDatabase(QDir *boardDir, QObject *parent) : QObject{ parent } {
	this->boardDir = boardDir;
}

void BoardDatabase::loadAllBoards() {
	QStringList boardFileNames = boardDir->entryList(QDir::Files | QDir::Readable);
	for (const QString &boardName : std::as_const(boardFileNames)) {
		loadBoard(boardDir->filePath(boardName));
	}
}

void BoardDatabase::addBoard(QSharedPointer<BoardSettings> boardSettings) {
	boardList.append(boardSettings);

	QString fileName = QUuid::createUuid().toString(QUuid::WithoutBraces) + ".json";

	boardSettings->setFilePath(boardDir->filePath(fileName));

	// Save settings to disk
	saveBoard(boardSettings);

	emit boardAdded(boardSettings);
}

void BoardDatabase::removeBoard(QSharedPointer<BoardSettings> boardSettings) {
	QFile::remove(boardSettings->getFilePath());

	boardList.removeAll(boardSettings);

	emit boardRemoved(boardSettings);
}

bool BoardDatabase::loadBoard(QString filePath) {
	QFile file(filePath);

	if (!file.open(QIODevice::ReadOnly)) {
		qWarning("Couldn't open board file.");
		return false;
	}

	QByteArray boardData = file.readAll();

	QJsonDocument loadDoc(QJsonDocument::fromJson(boardData));
	QJsonObject json = loadDoc.object();

	QSharedPointer<BoardSettings> boardSettingsObject;

	if (json.contains("model") && json["model"].isString()) {
		if (json["model"] == EosSettings::modelString)
			boardSettingsObject.reset(new EosSettings());
	}

	boardSettingsObject->setFilePath(filePath);
	boardSettingsObject->fromJson(json);

	boardList.append(boardSettingsObject);
	emit boardAdded(boardSettingsObject);

	qDebug() << "Loaded board"
			 << loadDoc["name"].toString();
	return true;
}

bool BoardDatabase::saveBoard(QSharedPointer<BoardSettings> boardSettings) const {
	QFile file(boardSettings->getFilePath());

	if (!file.open(QIODevice::WriteOnly)) {
		qWarning("Couldn't open board file.");
		return false;
	}

	QJsonObject jsonObject = boardSettings->toJson();
	file.write(QJsonDocument(jsonObject).toJson());

	return true;
}