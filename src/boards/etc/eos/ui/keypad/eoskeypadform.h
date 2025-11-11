#pragma once

#include "../eosform.h"
#include <QWidget>

namespace Ui {
class EosKeypadForm;
}

class EosKeypadForm : public QWidget {
	Q_OBJECT

public:
	explicit EosKeypadForm(EosForm *eosForm, QWidget *parent = nullptr);
	~EosKeypadForm();

private:
	Ui::EosKeypadForm *ui;

	QMap<qint32, QPushButton *> softKeys;
};
