#include "qfader.h"
#include "ui_qfader.h"

QFader::QFader(QWidget *parent) :
		QWidget(parent),
		ui(new Ui::QFader) {
	ui->setupUi(this);

	connect(ui->slider, &QAbstractSlider::sliderMoved, this, [=](qint32 value) {
		emit valueChanged(value);
	});
}

QFader::~QFader() {
	delete ui;
}

void QFader::setLabel(QString label) {
	ui->label->setText(label);
}

void QFader::setValue(qint32 value) {
	ui->slider->setValue(value);
}

qint32 QFader::getValue() {
	return ui->slider->value();
}

void QFader::setRange(qint32 min, qint32 max) {
	ui->slider->setRange(min, max);
}
