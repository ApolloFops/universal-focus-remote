#pragma once

#include "types/board/boarddiscovery.h"
#include "types/board/boardsettings.h"
#include "types/board/boardsettingsform.h"
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
	void boardCreated(QSharedPointer<BoardSettings> boardSettings);

private:
	Ui::AddBoardDialog *ui;
	QSharedPointer<BoardSettings> settingsBeingEdited;
	BoardSettingsForm *settingsForm;
	void onBoardFound(QSharedPointer<BoardSettings> boardSettings);
	void showBoardEditor(BoardSettingsForm *boardEditor);
	void hideBoardEditor();
	void onAccepted();
	BoardDiscovery *eosDiscovery;
	QList<QString> uidsFound;
};
