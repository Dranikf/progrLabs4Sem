#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "QMessageBox"
#include "QVBoxLayout"
#include "QLabel"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QLabel *infoLabel;
    // объявление коренных меню
    QMenu * fileMenu;
    QMenu * paramMenu;
    QMenu * aboutMenu;

    // объявление вложенных меню
    QAction * openAction;
    QAction * saveAction;
    QAction * exitAction;

    // функция создающая меню
    void createMenus();
    // функция создающая вложенные меню
    void createActions();

};
#endif // MAINWINDOW_H
