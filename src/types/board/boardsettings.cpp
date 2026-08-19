#include "boardsettings.h"

#include <QMetaProperty>

BoardSettings::BoardSettings() {
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

QVariant BoardSettings::getNamedProperty(QString name) {
	int index = metaObject()->indexOfProperty(name.toUtf8());

	if (index < 0) {
		return QVariant();
	}

	QMetaProperty property = metaObject()->property(index);

	return property.readOnGadget(this);
}

void BoardSettings::setFilePath(QString filePath) {
	this->filePath = filePath;
}

QString BoardSettings::getFilePath() const {
	return filePath;
}

void BoardSettings::setName(QString name) {
	this->name = name;
}

QString BoardSettings::getName() const {
	return name;
}