#pragma once

#include "boards/etc/eos/eossettings.h"
#include "types/board/boarddiscovery.h"
#include <QDialog>

namespace Ui {
class AddBoardDialog;
}

class AddBoardDialog : public QDialog {
	Q_OBJECT

public:
	explicit AddBoardDialog(QWidget *parent = nullptr);
	~AddBoardDialog();

	void scanForBoards();

signals:
	void boardCreated(EosSettings *boardSettings);

private:
	Ui::AddBoardDialog *ui;
	void onBoardFound(EosSettings *boardSettings);
	void onAccepted();
	BoardDiscovery *eosDiscovery;
	QList<QString> uidsFound;
};
