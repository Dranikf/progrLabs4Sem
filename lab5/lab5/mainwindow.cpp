#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    createActions();
    createMenus();
}

// вываодит на экран сообщение
void message(QString message){

    QMessageBox msgBox;
    msgBox.setText(message);
    msgBox.exec();
}

// функция создающая меню
void MainWindow::createMenus(){

    // так в Qt создается меню
    fileMenu = menuBar()->addMenu(tr("&Файл"));

    fileMenu->addAction(openAction);
    fileMenu->addAction(saveAction);
    fileMenu->addAction(exitAction);

    paramMenu = menuBar()->addMenu(tr("&Параметры"));

    aboutMenu = menuBar()->addMenu(tr("&Справка"));

}

void MainWindow::createActions(){

    openAction = new QAction(tr("&открыть")  , this);
    openAction->setIcon(QIcon::fromTheme("edit-undo"));
    saveAction = new QAction(tr("&сохранить") , this);
    exitAction = new QAction(tr("&выход")  , this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

