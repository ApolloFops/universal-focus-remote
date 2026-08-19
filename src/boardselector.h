#pragma once

#include "addboarddialog.h"
#include "boarddatabase.h"
#include "boards/etc/eos/ui/eosform.h"
#include <QWidget>

namespace Ui {
class BoardSelector;
}

class BoardSelector : public QWidget {
	Q_OBJECT

public:
	explicit BoardSelector(BoardDatabase *boardDatabase, QWidget *parent = nullptr);
	~BoardSelector();

	void addBoard(QSharedPointer<BoardSettings> boardSettings);

signals:
	void boardSelected(EosForm *boardForm);
	void boardCreated(QSharedPointer<BoardSettings> boardSettings);

private slots:
	void buttonClicked(QSharedPointer<BoardSettings> boardSettings);
	void buttonRightClicked(QSharedPointer<BoardSettings> boardSettings);

private:
	Ui::BoardSelector *ui;
	BoardDatabase *boardDatabase;
	AddBoardDialog *addBoardDialog;
};
