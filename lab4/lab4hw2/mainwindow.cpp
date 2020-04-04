#include "mainwindow.h"
#include "ui_mainwindow.h"

// вываодит на экран сообщение
void message(QString message){

    QMessageBox msgBox;
    msgBox.setText(message);
    msgBox.exec();
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    signalMaper = new QSignalMapper(this);
    signalMaper->setMapping(ui->lineEdit , ui->lineEdit);
    signalMaper->setMapping(ui->lineEdit_2 , ui->lineEdit_2);

    connect(ui->lineEdit , SIGNAL(textEdited(const QString &)) , signalMaper, SLOT(map()));
    connect(ui->lineEdit_2, SIGNAL(textEdited(const QString &)) , signalMaper, SLOT(map()));

    connect(signalMaper, SIGNAL(mapped(QWidget *)), this, SLOT(lineEditsSlots( QWidget *)));

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
    delete signalMaper;
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

    convertValues(sender->objectName());

}

void MainWindow::convertValues(QString name){

    float val , newVal;

    if(name == "lineEdit"){

        val = ui->lineEdit->text().toFloat();
        newVal = val/2.2046;
        ui->lineEdit_2->setText(QString::number(newVal));

    }
    if(name == "lineEdit_2"){

        val = ui->lineEdit_2->text().toFloat();
        newVal = val * 2.2046;
        ui->lineEdit->setText(QString::number(newVal));

    }

}
