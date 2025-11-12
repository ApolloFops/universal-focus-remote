#include "eoslampcontrolsform.h"
#include "ui_eoslampcontrolsform.h"

EosLampControlsForm::EosLampControlsForm(EosForm *eosForm, QWidget *parent) :
		QWidget(parent),
		ui(new Ui::EosLampControlsForm) {
	ui->setupUi(this);
	this->eosForm = eosForm;

	ui->scrollArea->setWidgetResizable(true);
	ui->scrollArea->setWidget(ui->scrollFrame);

	wheelFrameLayout = new QHBoxLayout(ui->wheelFrame);
	wheelFrameLayout->setContentsMargins(QMargins());

	for (auto [key, value] : eosForm->board->getChannelParams().asKeyValueRange()) {
		updateWheel(key);
	}

	connect(eosForm->board, &ETCEos::wheelUpdated, this, &EosLampControlsForm::updateWheel);
	connect(eosForm->board, &ETCEos::wheelRemoved, this, &EosLampControlsForm::removeWheel);
}

EosLampControlsForm::~EosLampControlsForm() {
	delete ui;
}

void EosLampControlsForm::updateWheel(qint32 index) {
	// This is probably really inefficient but I don't really care tbh
	// Might rework later if I feel like it
	QPair<QString, qint32> value = eosForm->board->getChannelParams().value(index);

	// Create a new fader if one doesn't exist
	if (!wheels.contains(index)) {
		QFader *slider = new QFader(this);

		slider->setRange(0, 100);

		connect(slider, &QFader::valueChanged, this, [=](qint32 newValue) {
			eosForm->board->setParameterValue(value.first, newValue);
		});

		wheelFrameLayout->addWidget(slider);
		// TODO: The horizontal scaling seems to be a little bit inconsistent. Need to investigate this.
		wheelFrameLayout->setStretchFactor(slider, 1);
		wheels[index] = slider;
	}

	wheels[index]->setLabel(value.first);
	wheels[index]->setValue(value.second);
}

void EosLampControlsForm::removeWheel(qint32 index) {
	delete wheels.take(index);
}
