#include "eosdiscovery.h"

#include <QOscMessage>

EosDiscovery::EosDiscovery(QObject *parent) :
		BoardDiscovery{ parent } {
	discoveryInterface.setRemoteAddress("255.255.255.255");
	discoveryInterface.setRemotePort(3034);
	discoveryInterface.setLocalPort(3035);

	discoveryInterface.connect("/etc/discovery/reply", [=](const QOscMessage &msg, const QHostAddress &sender) {
		QString hostIP = sender.toString();
		int hostPort = msg.toInt(0);
		QString hostName = msg.toString(1);
		QString hostUID = msg.toString(2);

		emit boardFound(QHostAddress(hostIP), hostPort, hostUID, hostName);
	});
}

void EosDiscovery::queryBoards() {
	QOscMessage discoveryRequest("/etc/discovery/request");
	discoveryRequest << QOscValue(3035)
					 << QOscValue("Universal Focus Remote");
	discoveryInterface.send(discoveryRequest);
}
