#pragma once

#include "../eosform.h"
#include "qfader.h"

#include <QHBoxLayout>
#include <QWidget>

namespace Ui {
class EosLampControlsForm;
}

class EosLampControlsForm : public QWidget {
	Q_OBJECT

public:
	explicit EosLampControlsForm(EosForm *eosForm, QWidget *parent = nullptr);
	~EosLampControlsForm();

private:
	Ui::EosLampControlsForm *ui;

	EosForm *eosForm;

	QMap<qint32, QFader *> wheels;
	QHBoxLayout *wheelFrameLayout;

	void updateWheel(qint32 index);
	void removeWheel(qint32 index);
};
