#include "board.h"

Board::Board(BoardSettings *settings, QObject *parent) : QObject{ parent } {
	this->settings = settings;
}

BoardSettings *Board::getSettings() {
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