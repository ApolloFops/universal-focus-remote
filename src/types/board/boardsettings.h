#pragma once

#include <QEnableSharedFromThis>
#include <QJsonObject>

class BoardSettingsForm;

//class BoardSettings : public QEnableSharedFromThis<BoardSettings> {
class BoardSettings {
	Q_GADGET

	Q_PROPERTY(QString name READ getName WRITE setName FINAL);

public:
	explicit BoardSettings();
	~BoardSettings() {
		qDebug() << "testing";
	}

	virtual const QMetaObject *metaObject() const { return &staticMetaObject; }

	static const QString modelString;

	virtual QJsonObject toJson() const;
	virtual void fromJson(const QJsonObject &json);

	QVariant getNamedProperty(QString name);

	void setName(QString name);
	QString getName() const;

	virtual BoardSettingsForm *createSettingsForm() = 0;

private:
	QString name;
};
