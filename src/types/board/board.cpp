#include "board.h"

Board::Board(QSharedPointer<BoardSettings> settings, QObject *parent) : QObject{ parent } {
	this->settings.swap(settings);
}

QSharedPointer<BoardSettings> Board::getSettings() {
	return settings;
}

QString Board::getBoardName() {
	return settings->getName();
}

QString Board::getShowName() {
	return showName;
}

void Board::setShowName(QString name) {
	showName = name;
	emit showNameChanged(showName);
}