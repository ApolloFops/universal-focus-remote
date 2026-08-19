#include "eossettingsform.h"
#include "ui_eossettingsform.h"

EosSettingsForm::EosSettingsForm(QSharedPointer<EosSettings> settings, QWidget *parent) :
		BoardSettingsForm(parent),
		ui(new Ui::EosSettingsForm) {
	setSettings(settings);

	ui->setupUi(this);

	ui->nameEdit->setText(settings->getName());
	ui->ipEdit->setText(settings->getIp());

	connect(ui->nameEdit, &QLineEdit::textEdited, this, [=](const QString &text) {
		settings->setName(text);
	});

	connect(ui->ipEdit, &QLineEdit::textEdited, this, [=](const QString &text) {
		settings->setIp(text);
	});
}

EosSettingsForm::~EosSettingsForm() {
	delete ui;
}