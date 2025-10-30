#pragma once

#include "../types/board/boarddiscovery.h"
#include <QObject>
#include <QOscUdpInterface>

class EosDiscovery : public BoardDiscovery {
	Q_OBJECT
public:
	explicit EosDiscovery(QObject *parent = nullptr);

	void queryBoards() override;

signals:

private:
	QOscUdpInterface discoveryInterface;
};
