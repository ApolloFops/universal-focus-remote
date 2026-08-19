#pragma once

#include <QEnableSharedFromThis>
#include <QFile>
#include <QJsonObject>

class BoardSettingsForm;

class BoardSettings : public QEnableSharedFromThis<BoardSettings> {
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

	void setFilePath(QString filePath);
	QString getFilePath() const;

	void setName(QString name);
	QString getName() const;

	virtual BoardSettingsForm *createSettingsForm() = 0;

private:
	QString filePath;
	QString name;
};

Q_DECLARE_METATYPE(QSharedPointer<BoardSettings>)