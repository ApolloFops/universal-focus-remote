#include "eossettings.h"
#include "ui/eossettingsform.h"

const QString BoardSettings::modelString = "etc.eos";

EosSettings::EosSettings(QObject *parent) :
		BoardSettings{ parent } {
}

QJsonObject EosSettings::toJson() const {
	QJsonObject json = BoardSettings::toJson();
	json["ip"] = ip;
	return json;
}

void EosSettings::fromJson(const QJsonObject &json) {
	BoardSettings::fromJson(json);

	if (json.contains("ip") && json["ip"].isString())
		ip = json["ip"].toString();
}

void EosSettings::setIp(QString ip) {
	this->ip = ip;
	emit ipChanged(ip);
	emit updated();
}

QString EosSettings::getIp() const {
	return ip;
}

BoardSettingsForm *EosSettings::createSettingsForm() {
	return new EosSettingsForm(this);
}