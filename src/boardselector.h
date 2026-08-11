#pragma once

#include "addboarddialog.h"
#include "boards/etc/eos/ui/eosform.h"
#include <QWidget>

namespace Ui {
class BoardSelector;
}

class BoardSelector : public QWidget {
	Q_OBJECT

public:
	explicit BoardSelector(QWidget *parent = nullptr);
	~BoardSelector();

	void addBoard(BoardSettings *boardSettings);

signals:
	void boardSelected(EosForm *boardForm);
	void boardCreated(BoardSettings *boardSettings);

private slots:
	void buttonClicked(BoardSettings *boardSettings);
	void buttonRightClicked(BoardSettings *boardSettings);

private:
	Ui::BoardSelector *ui;
	AddBoardDialog *addBoardDialog;
};
