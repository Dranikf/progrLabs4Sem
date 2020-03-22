#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QTableWidgetItem * item;
    for(int i =0 ; i < ui->tableWidget->columnCount(); i ++)
    {
        // установим ширину колонок
        ui->tableWidget->setColumnWidth(i , 20);
        ui->tableWidget_2->setColumnWidth(i , 20);
        ui->tableWidget_3->setColumnWidth(i , 20);
        for(int j = 0; j < ui->tableWidget_3->rowCount(); j++)
            item = new QTableWidgetItem();
            item->flags().setFlag(Qt::ItemIsEditable , false);
            ui->tableWidget_3->setItem(0 , 0 , item);
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

