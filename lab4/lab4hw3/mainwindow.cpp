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

    connect(ui->lineEdit , SIGNAL(textEdited(const QString &)) , signalMaper, SLOT(map()));
    connect(ui->lineEdit_2, SIGNAL(textEdited(const QString &)) , signalMaper, SLOT(map()));
    connect(ui->lineEdit_3, SIGNAL(textEdited(const QString &)) , signalMaper, SLOT(map()));

     connect(signalMaper, SIGNAL(mapped(QWidget *)), this, SLOT(lineEditsSlots( QWidget *)));
}

MainWindow::~MainWindow()
{
    delete signalMaper;
    delete ui;
}

// вываодит на экран сообщение
void message(QString message){

    QMessageBox msgBox;
    msgBox.setText(message);
    msgBox.exec();
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

void MainWindow::on_pushButton_clicked()
{
    float sum = ui->lineEdit->text().toFloat();
    float grou = ui->lineEdit_2->text().toFloat();
    float period = ui->lineEdit_3->text().toFloat();

    if(ui->radioButton->isChecked())
        period = period / 30;// переводим дни в месяцы

    int iPeriod = period;
    float result = sum;
    float addValue;
    QString dataString;
    for(int i = 0 ; i < iPeriod; i++){
        // тут проценты простые
        if(ui->radioButton_3->isChecked())
            addValue = sum * grou;
        else
            addValue = grou * result;

        result += addValue;
        dataString = "---------- месяц" + QString::number(i) + " -------------------\n" +
                    "прирост по вкладу: " + QString::number(addValue) +'\n'+
                    "итго на балансе: " + QString::number(result) + "\n" +
                    "---------- месяц" + QString::number(i) + " -------------------\n" ;

        ui->textEdit->setText(ui->textEdit->toPlainText() + dataString);
    }

}
