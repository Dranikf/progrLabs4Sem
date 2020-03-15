#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QMessageBox"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tableWidget->setRowCount(1);
    //QTableWidgetItem * hello = new QTableWidgetItem;
    //hello->setText("hello");
    //ui->tableWidget->createWinId();
}

MainWindow::~MainWindow()
{
    delete ui;
}

// функция ждет укзазатель на таблицу
// и проверяет, есть ли в таблице пустые ячейки
// true - есть false - нету
bool isEmptyValues(QTableWidget * table){
    for (int i =0 ; i < table->rowCount(); i++){
        for(int j = 0 ; j < table->columnCount(); j++){
            // это на тот случай если ячейка совмем ничего не содержит
            if(!table->item(i,j))
                return true;
            // это на тот случай если ячейка содержит пустую строку
            if(table->item(i,j)->text().length() == 0)
                return true;

        }
    }

    return false;
}
// вываодит на кэран сообщение
void message(QString message){

    QMessageBox msgBox;
    msgBox.setText(message);
    msgBox.exec();
}

// обработчик кнопки которая посмотрит сложит ячейки таблицы и вычислит среднее
void MainWindow::on_pushButton_clicked()
{
    int colCout = ui->tableWidget->columnCount();
    float result = 0;

    if(isEmptyValues(ui->tableWidget))
    {
       message("заполните пустые ячейки");
       return;
    }

    bool isOk;
    for (int i = 0; i < colCout; i++)
    {
        result += ui->tableWidget->item(0 , i)->text().toFloat(&isOk);
        // тут проверим можно ли полученнную строку преобразовать в float
        if(!isOk)
        {
            message("получено нечисловое значение");
            return;
        }

        ui->textEdit->setText(ui->textEdit->toPlainText() + "полученная сумма :" + QString::number(result) + "\n");
    }

    ui->textEdit->setText(ui->textEdit->toPlainText() + "результат вычисления :" + QString::number(result) + "\n");
    float avarageValue = result/5;
    ui->textEdit->setText(ui->textEdit->toPlainText() + "среднее значение : " + QString::number(avarageValue) + "\n");
}
