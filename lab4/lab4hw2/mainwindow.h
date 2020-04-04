#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLineEdit>
#include <QMessageBox>
#include <QSignalMapper>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void convertValues(QString name);

public slots:
    void lineEditsSlots(QWidget * sender);// слот для обрботки ввода
private:
    Ui::MainWindow *ui;
    QSignalMapper * signalMaper;
};
#endif // MAINWINDOW_H
