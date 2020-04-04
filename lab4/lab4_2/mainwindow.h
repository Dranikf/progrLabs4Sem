#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLineEdit>
#include <QMessageBox>
#include <QSignalMapper>
#include <QLocale>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void lineEditsSlots(QWidget * sender); // создание слота, который будет
    // пивязан с сигналам на ввод для полей ввод
    // а предан ему будет указатель на ту строку ввода,
    // которая вызвала исполнение этого слота

    //создадим также слот который обработает нажатие клавиши Enter
    void enterPressed();

    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    // вот благодаря этому классу удасться создать
    // передать в слот указтель на произвольный объект
    QSignalMapper * signalMaper;
};
#endif // MAINWINDOW_H
