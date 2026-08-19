#pragma once

#include "boarddatabase.h"
#include "boards/etc/eos/ui/eosform.h"
#include "boardselector.h"

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
	BoardDatabase *boardDatabase;
	BoardSelector *boardSelector;

public slots:
	void setBoardForm(EosForm *boardForm);

private:
	Ui::MainWindow *ui;
};
