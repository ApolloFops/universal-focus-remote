#pragma once

#include <QJsonObject>

class BoardSettings : public QObject {
	Q_OBJECT

	Q_PROPERTY(QString name READ getName WRITE setName NOTIFY nameChanged FINAL);

public:
	explicit BoardSettings(QObject *parent = nullptr);

	static const QString modelString;

	virtual QJsonObject toJson() const;
	virtual void fromJson(const QJsonObject &json);

	void remove();

	void setName(QString name);
	QString getName() const;

signals:
	void updated();
	void removed();
	void nameChanged(QString name);

private:
	QString name;
};
