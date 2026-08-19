#include "eossettings.h"
#include "ui/eossettingsform.h"

const QString BoardSettings::modelString = "etc.eos";

EosSettings::EosSettings() : BoardSettings{} {
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
}

QString EosSettings::getIp() const {
	return ip;
}

BoardSettingsForm *EosSettings::createSettingsForm() {
	return new BoardSettingsForm();
	// return new EosSettingsForm(sharedFromThis().staticCast<EosSettings>());
}