#pragma once

#include "boards/etc/eos/ui/eosform.h"
#include "boardselector.h"
#include "types/board/boardsettings.h"

#include <QDir>
#include <QFile>
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
	Q_OBJECT

public:
	MainWindow(QWidget *parent = nullptr);
	~MainWindow();
	EosForm *boardForm;
	BoardSelector *boardSelector;

	bool loadBoard(QString filePath);
	bool saveBoard(BoardSettings *boardSettings, QString fileName) const;

	void read(const QJsonObject &json);
	void write(QJsonObject &json) const;

public slots:
	void setBoardForm(EosForm *boardForm);

private:
	Ui::MainWindow *ui;
	void setupBoard(BoardSettings *boardSettings, QString fileName);
	void onBoardCreated(BoardSettings *boardSettings);
	QDir *boardDir;
};
