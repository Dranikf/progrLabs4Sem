#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // в Qt для корректкной работы с табличекй под ячейки надо
    // еще выделить память
    for(int i = 0 ; i < 6 ;i++)
        for(int j = 0 ; j < 5 ; j++)
            ui->tableWidget->setItem(i , j , new QTableWidgetItem);
    // надеюсь на то что компонент мссам в в декструкторе счистит память

    // конструктор в котором заполним таблицу начальными значенриями
    // заполнение второй строки
    ui->tableWidget->item(1 , 1)->setText("Хлеб");
    ui->tableWidget->item(1 ,2) ->setText("Соль");
    ui->tableWidget->item(1 , 3)->setText("Молоко");
    ui->tableWidget->item(1 ,4)->setText("Мясо");
    //-------------------------------------------
    // заполненние третьей строки
    ui->tableWidget->item(2, 1)->setText("75");
    ui->tableWidget->item(2, 2)->setText("13");
    ui->tableWidget->item(2,3)->setText("56");
    ui->tableWidget->item(2, 4)->setText("450");
    //------------------------------------------
    // заполнение четвертой строки
    ui->tableWidget->item(3 ,1)->setText("5.50");
    ui->tableWidget->item(3,2)->setText("4.2");
    ui->tableWidget->item(3, 3)->setText("8.3");
    ui->tableWidget->item(3,4)->setText("123.7");

    // хоть этот следющий код в приведенном примере располагался
    // в обработчике onShow, хотя его спокойно можно было бы поместить
    // и в конструктор
    // для формы в QT я не нашел для формы обработчика подобного onShow
    // потому и закинул в конструктор
    //------------------------------------------
    // зададим ширину столбиков
    int colSizes[] = {110 , 60 , 60 , 60 , 60, 60};
    for(int i = 0 ; i < 5; i++)
        ui->tableWidget->setColumnWidth(i, colSizes[i]);

    QString temp[] = {"№" , "Наименование" , "Кол-во" , "Цена"
                      , "Итого" , "Всего"};
    for( int i = 0; i < 6; i++)
        ui->tableWidget->item(i, 0)->setText(temp[i]);

    // проставим номера
    for(int i = 1;i < ui->tableWidget->columnCount(); i++)
        ui->tableWidget->item(0 , i)->setText(QString::number(i));

}

MainWindow::~MainWindow()
{
    delete ui;
}

// обработчик для нажатия кнопочки
void MainWindow::on_pushButton_clicked()
{
    float kost, rez , result = 0;
    int kol;
    rez = 0;

    // тут необходимо пребирать колонки а не строки
    for (int i = 1 ; i < ui->tableWidget->columnCount(); i++){

        kol = ui->tableWidget->item(2, i)->text().toInt();
        kost = ui->tableWidget->item(3, i)->text().toFloat();
        rez = kol * kost;
        ui->tableWidget->item(4 , i)->setText(QString::number(rez));

        // зечем то это было разбито на два цикла, но поле "Всего"
        // можно заполнить и в этом цикле
        result += rez;
    }

    // и не оптимлаьно постоянно перезаписывать одно и тоже значение
    // внутри цикла, лучше заполнить после него
    ui->tableWidget->item(5 , ui->tableWidget->columnCount() - 1)->setText(QString::number(result));


}
