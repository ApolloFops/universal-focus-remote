#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include <QJsonDocument>
#include <QJsonObject>
#include <QKeyEvent>
#include <QMessageBox>
#include <QStandardPaths>
#include <QStyleFactory>

MainWindow::MainWindow(QWidget *parent) :
		QMainWindow(parent), ui(new Ui::MainWindow) {
	ui->setupUi(this);

	QString boardDirPath = QDir(QStandardPaths::writableLocation(QStandardPaths::AppDataLocation))
								   .filePath("boards");

	QDir *boardDir = new QDir(boardDirPath);
	boardDir->mkpath(boardDirPath);

	boardDatabase = new BoardDatabase(boardDir, this);

	boardSelector = new BoardSelector(boardDatabase, this);
	connect(boardSelector, &BoardSelector::boardSelected, this, &MainWindow::setBoardForm);
	setCentralWidget(boardSelector);

	boardDatabase->loadAllBoards();
}

MainWindow::~MainWindow(){
	delete ui;
}

void MainWindow::setBoardForm(EosForm *boardForm) {
	this->boardForm = boardForm;
	setCentralWidget(boardForm);
}