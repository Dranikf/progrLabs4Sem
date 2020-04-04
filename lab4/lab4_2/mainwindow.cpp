#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QSignalMapper"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // создаем объект который поможет нам предать в слоты указатели
    signalMaper = new QSignalMapper(this);

    // финт в том, что в зависимости от того, от какого объекта в
    // signalMaper придет сигнал, он будет предавать указанные объекты
    // так в следующей строке "если сигнал пришел от lineEdit то передаеи в указанный слот
    // указатель на lineEdit"
    signalMaper->setMapping(ui->lineEdit , ui->lineEdit);
    signalMaper->setMapping(ui->lineEdit_2 , ui->lineEdit_2);
    signalMaper->setMapping(ui->lineEdit_3 , ui->lineEdit_3);

    // тут присоединим сигналы редактирования строк ввода
    // к единому слоту map() которому выше указано что в каждом случае слать
    connect(ui->lineEdit , SIGNAL(textEdited(const QString &)) , signalMaper, SLOT(map()));
    connect(ui->lineEdit_2, SIGNAL(textEdited(const QString &)) , signalMaper, SLOT(map()));
    connect(ui->lineEdit_3 , SIGNAL(textEdited(const QString &)) , signalMaper, SLOT(map()));

    // финальный шаг - соединяем сигнал исходящий из signalMaper со слотом который я заранее подготовил
    connect(signalMaper, SIGNAL(mapped(QWidget *)), this, SLOT(lineEditsSlots( QWidget *)));

    // подсоединим также сигналы от полей ввода о нажатии клавиши Enter к
    // заранее созданному слоту enterPressed
    // подключим напрямую минуя SignalMaper, ведь каких специфических аргументов в слот передавать не требуется
    connect(ui->lineEdit , SIGNAL(returnPressed()) , this , SLOT(enterPressed()));
    connect(ui->lineEdit_2 , SIGNAL(returnPressed()) , this , SLOT(enterPressed()));
    connect(ui->lineEdit_3 , SIGNAL(returnPressed()) , this , SLOT(enterPressed()));

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

// выводит на экран сообщение со значком предупреждения
void warning(QString message){

    QMessageBox msgBox;
    msgBox.setText(message);
    msgBox.setIcon(QMessageBox::Warning);
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
            ui->pushButton->setFocus();
        break;
    }

}

void MainWindow::on_pushButton_clicked()
{
   float prior , curr;
   float tariff;
   float summ;
   prior = ui->lineEdit->text().toFloat();
   curr = ui->lineEdit_2->text().toFloat();
   tariff = ui->lineEdit_3->text().toFloat();

   if(curr < prior)
        warning("Текущее значение показателя счетчика не можем быть меньше предыдущего");

    summ = (curr - prior) * tariff;
    ui->label_4->setText("Сумма к оплате: " + QString::number(summ));
}
