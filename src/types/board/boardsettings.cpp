#include "boardsettings.h"

BoardSettings::BoardSettings(QObject *parent) : QObject{ parent } {
}

QJsonObject BoardSettings::toJson() const {
	QJsonObject json;
	json["model"] = modelString;
	json["name"] = name;
	return json;
}

void BoardSettings::fromJson(const QJsonObject &json) {
	if (json["model"] != modelString)
		throw std::runtime_error(QString("Model name mismatch!\n\tClass model: %1\n\tGiven model: %2\n")
										 .arg(modelString, json["model"].toString())
										 .toStdString());

	if (json.contains("name") && json["name"].isString())
		setName(json["name"].toString());
}

void BoardSettings::remove() {
	emit removed();
	delete this;
}

void BoardSettings::setName(QString name) {
	this->name = name;
	emit nameChanged(name);
	emit updated();
}

QString BoardSettings::getName() const {
	return name;
}