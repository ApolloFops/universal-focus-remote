#pragma once

#include "../../../../types/board/boardsettingsform.h"
#include "../eossettings.h"

namespace Ui {
class EosSettingsForm;
}

class EosSettingsForm : public BoardSettingsForm {
	Q_OBJECT

public:
	explicit EosSettingsForm(EosSettings *settings, QWidget *parent = nullptr);
	~EosSettingsForm();

private:
	Ui::EosSettingsForm *ui;
};
