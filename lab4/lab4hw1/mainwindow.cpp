#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    signalMaper = new QSignalMapper(this);

    signalMaper->setMapping(ui->lineEdit , ui->lineEdit);
    signalMaper->setMapping(ui->lineEdit_2 , ui->lineEdit_2);
    signalMaper->setMapping(ui->lineEdit_3 , ui->lineEdit_3);
    signalMaper->setMapping(ui->lineEdit_4 , ui->lineEdit_4);
    signalMaper->setMapping(ui->lineEdit_5 , ui->lineEdit_5);

    connect(ui->lineEdit , SIGNAL(textEdited(const QString &)) , signalMaper, SLOT(map()));
    connect(ui->lineEdit_2, SIGNAL(textEdited(const QString &)) , signalMaper, SLOT(map()));
    connect(ui->lineEdit_3 , SIGNAL(textEdited(const QString &)) , signalMaper, SLOT(map()));
    connect(ui->lineEdit_4, SIGNAL(textEdited(const QString &)) , signalMaper, SLOT(map()));
    connect(ui->lineEdit_5, SIGNAL(textEdited(const QString &)) , signalMaper, SLOT(map()));

    connect(signalMaper, SIGNAL(mapped(QWidget *)), this, SLOT(lineEditsSlots( QWidget *)));

    connect(ui->lineEdit , SIGNAL(returnPressed()) , this , SLOT(enterPressed()));
    connect(ui->lineEdit_2 , SIGNAL(returnPressed()) , this , SLOT(enterPressed()));
    connect(ui->lineEdit_3 , SIGNAL(returnPressed()) , this , SLOT(enterPressed()));
    connect(ui->lineEdit_4 , SIGNAL(returnPressed()) , this , SLOT(enterPressed()));
    connect(ui->lineEdit_5 , SIGNAL(returnPressed()) , this , SLOT(enterPressed()));

}

// вываодит на экран сообщение
void message(QString message){

    QMessageBox msgBox;
    msgBox.setText(message);
    msgBox.exec();
}

// выводит на экран сообщение со значком предупреждения
void warning(QString message){

    QMessageBox msgBox;
    msgBox.setText(message);
    msgBox.setIcon(QMessageBox::Warning);
    msgBox.exec();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::lineEditsSlots(QWidget * sender)
{
    // супер опасная конструкция, но если учесть, что я навернаяка
    // под QWidget передаю QLineEdit, то можно оставить!
   QLineEdit * senEdit = (QLineEdit *)sender;
   int p = senEdit->cursorPosition();

   if(!p)
       return;

    QString str = senEdit->text();
    QChar symbol = str[p -1];

    // разберемся в десятичным разделителем
    QLocale rus("Russia");
    QChar separ = rus.decimalPoint();

    if(!symbol.isNumber()){
        str.replace(p-1 , 1 , QString(""));
        if(symbol != separ)
            message("требуются цифры для ввода");
        else{
            if(str.indexOf(separ) == -1)
                return;
            else
                message("допустим только один десятичный разделитель");
        }
        senEdit->setText(str);
    }
}


void MainWindow::enterPressed(){
    QWidget * focusW = this->focusWidget();

    if(focusW == nullptr)
        return;
    // читаем имя объекта имеющего фокус
    QString name = focusW->objectName();
    // узнаем ее последний символ
    QChar n = name[name.length() - 1];

    // перезходим к соответсвующиму элементу
    switch (n.unicode())
    {
        case 't':
            ui->lineEdit_2->setFocus();
        break;
        case '2':
            ui->lineEdit_3->setFocus();
        break;
        case '3':
            ui->lineEdit_4->setFocus();
        break;
        case '4':
            ui->lineEdit_5->setFocus();
        break;
        case '5':
            ui->pushButton->setFocus();
        break;
    }

}

void MainWindow::on_pushButton_clicked()
{
    float prior , curr;
    float tariff , extraTarif;
    float limit , summ;
    prior = ui->lineEdit->text().toFloat();
    curr = ui->lineEdit_2->text().toFloat();
    tariff = ui->lineEdit_5->text().toFloat();
    extraTarif = ui->lineEdit_4->text().toFloat();
    limit = ui->lineEdit_3->text().toFloat();

    if(curr < prior){
        warning("Текущее значение показателя счетчика не можем быть меньше предыдущего");
        return;
    }

    float saldo = curr - prior;
    if (saldo <= limit)
    {
       summ = saldo * tariff;
    }
    else
    {
       summ = limit * tariff + (saldo - limit)* extraTarif;
    }

    ui->label_6->setText("итого к оплате: " + QString::number(summ));
}
