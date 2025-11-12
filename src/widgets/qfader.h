#pragma once

#include <QWidget>

namespace Ui {
class QFader;
}

class QFader : public QWidget {
	Q_OBJECT

public:
	explicit QFader(QWidget *parent = nullptr);
	~QFader();

	qint32 getValue();

public slots:
	void setLabel(QString label);
	void setValue(qint32 value);
	void setRange(qint32 min, qint32 max);

signals:
	void valueChanged(qint32 value);

private:
	Ui::QFader *ui;
};
