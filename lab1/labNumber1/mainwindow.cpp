#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "math.h"
#include "iostream"
#include "QMessageBox"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setVarLabels();
    setT5NValLab();
}

MainWindow::~MainWindow()
{
    delete ui;
}

// функция парсит строку с данными, и пишет в вектор
void parseDataStr(std::vector<QString> * dataPointer, QString str){

    int pos, prePos = 0, i =0;
    QString tempStr;

    while((pos = str.indexOf(" ", prePos)) != -1){

        tempStr = str.mid(prePos, pos - prePos);
        dataPointer->push_back(tempStr);
        prePos = pos + 1;
        i++;

    }

    dataPointer->push_back(str.mid(prePos, str.length() - prePos));

}

void MainWindow::on_resultButton_clicked()
{
   float X, Y, Z , Rez;

   QString temp;

   temp = ui->lineEdit_2->text();
   std::vector<QString> data;
   parseDataStr(&data , temp);

   X = data[0].toFloat();
   Y = data[1].toFloat();
   Z = data[2].toFloat();

   Rez = Y * Z + X * sqrt(abs(Y));

    ui->label_5->setText(QString::number(Rez));
}

void MainWindow::on_resultButton_2_clicked()
{
    float X, Y, Z , Rez;
    QString temp;

    temp = ui->lineEdit_3->text();
    std::vector<QString> data;
    parseDataStr(&data , temp);

    X = data[0].toFloat();
    Y = data[1].toFloat();
    Z = data[2].toFloat();

    if(Z <= 0){

        QMessageBox msgBox;
        msgBox.setText("вычисление десятичного логарифма от отрицаетльного числа невозможно");
        msgBox.exec();
        return;
    }

    QString resultStr = "F(X,Y,Z) = ";
    resultStr += QString::number(X);
    resultStr += "* cos(";
    resultStr += QString::number(Y);
    resultStr += ") + log(";
    resultStr += QString::number(Z);
    resultStr += ")";

    ui->textEdit->setText(resultStr);
    Rez = X * cos(Y) + log10(Z);

    ui->label_7->setText(QString::number(Rez));

}

void MainWindow::on_pushButton_clicked()
{
    QString iStr, xStr , tempString;
    int i; float X;
    float result;

    iStr = ui->lineEdit->text();
    xStr = ui->lineEdit_4->text();

    i = iStr.toInt();
    X = xStr.toFloat();
    if(i%2 == 1 && X > 0){

        tempString = "i нечетное а X положительное \n вычисляю по формуле \n";
        tempString += iStr;
        tempString += "*sqrt(cos(";
        tempString += xStr;
        tempString += "))";
        ui->textEdit_2->setText(tempString);

        result = i*sqrt(cos(X));
        ui->label_13->setText(QString::number(result));

        return;
    }
    else if(i%2 != 1 && X < 0) {

        tempString = "i четное а X отрицательное \n вычисляю по формуле \n (";
        tempString += iStr;
        tempString += "/2)*sqrt(|cos(";
        tempString += xStr;
        tempString += ")|)";
        ui->textEdit_2->setText(tempString);

        result = (i/2)*sqrt(abs(cos(X)));
        ui->label_13->setText(QString::number(result));

        return;
    }
    else {
        tempString = "получен непредусмотренный вариант \n вычисляю по формуле \n sqrt(|";
        tempString += iStr;
        tempString += iStr;
        tempString += "*cos(" + xStr;
        tempString += ")|)";
        ui->textEdit_2->setText(tempString);

        result = sqrt(abs(cos(X)));
        ui->label_13->setText(QString::number(result));

    }
}

// функция установит значения объявленных в h файле пременных в соответсвующие им labels на форме
// для начальной инициализации вызвается в конструкторе
void MainWindow::setVarLabels(){

    ui->xvalue->setText(QString::number(t4x));
    ui->yvalue->setText(QString::number(t4y));
    ui->zvalue->setText(QString::number(t4z));

}

// при нажатии на строку со вкладочками обновим значения в лейблах ответсвенных за переменные
void MainWindow::on_tabWidget_tabBarClicked(int index)
{
    if(index == 3){
        setVarLabels();
    }
    if(index == 4){
        setT5NValLab();
    }
}
// нажатие на кнопку для применения значения для некоторой переменной
void MainWindow::on_pushButton_2_clicked()
{

    switch (ui->comboBox->currentIndex()) {
        case 0:
            t4x = ui->lineEdit_5->text().toFloat();
        break;
        case 1:
            t4y = ui->lineEdit_5->text().toFloat();
        break;
        case 2:
            t4z = ui->lineEdit_5->text().toFloat();
        break;
    }

    setVarLabels();

}
// обработчик нажатия конопки для расчета
void MainWindow::on_pushButton_3_clicked()
{
    // проверим чтоб под логарифмом случайно не было отрицательного числа или нуля
    // для этого достаточно чтобы y > 0
    if(t4y < 0){
        QMessageBox msgBox;
        msgBox.setText("вычисление невозможно с отрицательным y");
        msgBox.exec();
        return;
    }

    float result;

    result = log(pow(t4y , -sqrt(abs(t4x)))) * (t4x - (t4y/2)) +pow(sin(atan(t4z))  , 2);
    ui->label_21->setText(QString::number(result));

}
// функция подставит соответсвуещее значение в Label для значения n
// для начальной инициализации вызывается в консрукторе
void MainWindow::setT5NValLab(){

    ui->nValue->setText(QString::number(t5n));

}
// нажатие кнопочки +
void MainWindow::on_pushButton_4_clicked()
{
    t5n++;
    setT5NValLab();
}
// нажатие кнопочки -
void MainWindow::on_pushButton_5_clicked()
{
    //  нельзя давать задать n < 0
    if(t5n == 0)
        return;
    t5n--;
    setT5NValLab();
}

// удивительно, но в math.h не нашлось функции для подсчета
// факториала, придеться быстренько напсать свою
int fact(int a){

    if (a == 0) return 1;

    int result = 1;
    for(int i = 2; i <= a; i++){
        result *= i;
    }

    return result;
}

// нажатие на кнопку подсчета
void MainWindow::on_pushButton_6_clicked()
{
    float result = 0, tempValue ,x;
    QString processData;
    x = ui->lineEdit_6->text().toFloat();

    for(int i =0 ; i<t5n; i++){

        float f =  fact(i);

        tempValue = pow(x, 2*i)*((2*i+1)/ f);
        processData = ui->textEdit_3->toPlainText();
        processData += "на инерации номер " + QString::number(i) +
                " получено: " + QString::number(tempValue)+ "\n" ;
        ui->textEdit_3->setText(processData);
        result += tempValue;
    }

    ui->label_25->setText(QString::number(result));

}
