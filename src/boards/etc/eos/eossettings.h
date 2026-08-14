#pragma once

#include "../types/board/boardsettings.h"
#include <QJsonObject>

class EosSettings : public BoardSettings {
	Q_OBJECT

	Q_PROPERTY(QString ip READ getIp WRITE setIp NOTIFY ipChanged FINAL);

public:
	explicit EosSettings(QObject *parent = nullptr);

	QJsonObject toJson() const override;
	void fromJson(const QJsonObject &json) override;

	void setIp(QString ip);
	QString getIp() const;

	BoardSettingsForm *createSettingsForm() override;

signals:
	void ipChanged(QString ip);

private:
	QString ip = "127.0.0.1";
};
