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
        ui->tableWidget_3->setColumnWidth(i , 60);
        for(int j = 0; j < ui->tableWidget_3->rowCount(); j++){
            // необхомо установить каждому item
            // запрет на ввод
            item = new QTableWidgetItem();
            item->setFlags(item->flags() ^ Qt::ItemIsEditable);

            ui->tableWidget_3->setItem(j , i , item);

            // заполним случайными float от 0 до 10 (устал их руками подставлять)
            item = new QTableWidgetItem();
            item->setText(QString::number(rand()%10+ float(rand()%10) / 100));
            ui->tableWidget->setItem(i , j , item);
            item = new QTableWidgetItem();
            item->setText(QString::number(rand()%10+ float(rand()%10) / 100));
            ui->tableWidget_2->setItem(i , j , item);
            // заполним случайными float от 0 до 10 (устал из руками подставлять)


        }
    }

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    float result;
    // i - идет по строчкам первой матрицы
    // j - идет по столбикам второй
   for(int i = 0 ; i < 4 ; i++)
       for(int j =0 ; j < 4; j++)
        {
            result = 0;
            // с - идет по элементам i ой строчки первой матрицы и j го столбика второй матрицы
           for(int c = 0; c < 4; c++)
                result += ui->tableWidget->item(i , c)->text().toFloat() * ui->tableWidget_2->item(c , j)->text().toFloat();

           ui->tableWidget_3->item(i , j)->setText(QString::number(result));

       }
}
