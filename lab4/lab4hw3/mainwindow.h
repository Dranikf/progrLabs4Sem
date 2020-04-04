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
public slots:
    void lineEditsSlots(QWidget * sender);// слот для обрботки ввода
private slots:
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    QSignalMapper * signalMaper;
};
#endif // MAINWINDOW_H
