#pragma once

#include "../types/board/boardsettings.h"
#include <QJsonObject>

class EosSettings : public BoardSettings {
	Q_GADGET

	Q_PROPERTY(QString ip READ getIp WRITE setIp FINAL);

public:
	explicit EosSettings();

	virtual const QMetaObject *metaObject() const override { return &staticMetaObject; }

	QJsonObject toJson() const override;
	void fromJson(const QJsonObject &json) override;

	void setIp(QString ip);
	QString getIp() const;

	BoardSettingsForm *createSettingsForm() override;

private:
	QString ip = "127.0.0.1";
};
