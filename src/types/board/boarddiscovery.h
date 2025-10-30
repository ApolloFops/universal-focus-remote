#pragma once

#include <QHostAddress>
#include <QObject>

class BoardDiscovery : public QObject {
	Q_OBJECT
public:
	explicit BoardDiscovery(QObject *parent = nullptr);

	virtual void queryBoards() = 0;

signals:
	void boardFound(const QHostAddress &address, const int &port, const QString &uid, const QString &name);
};
