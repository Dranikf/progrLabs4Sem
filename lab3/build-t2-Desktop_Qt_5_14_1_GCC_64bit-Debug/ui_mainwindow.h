/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QTableWidget *tableWidget_2;
    QLabel *label;
    QTableWidget *tableWidget;
    QLabel *label_2;
    QTableWidget *tableWidget_3;
    QPushButton *pushButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(725, 241);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        tableWidget_2 = new QTableWidget(centralwidget);
        if (tableWidget_2->columnCount() < 4)
            tableWidget_2->setColumnCount(4);
        if (tableWidget_2->rowCount() < 4)
            tableWidget_2->setRowCount(4);
        tableWidget_2->setObjectName(QString::fromUtf8("tableWidget_2"));
        tableWidget_2->setGeometry(QRect(240, 20, 180, 121));
        tableWidget_2->setBaseSize(QSize(84, 0));
        tableWidget_2->setRowCount(4);
        tableWidget_2->setColumnCount(4);
        tableWidget_2->horizontalHeader()->setVisible(false);
        tableWidget_2->verticalHeader()->setVisible(false);
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(220, 70, 16, 20));
        tableWidget = new QTableWidget(centralwidget);
        if (tableWidget->columnCount() < 4)
            tableWidget->setColumnCount(4);
        if (tableWidget->rowCount() < 4)
            tableWidget->setRowCount(4);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setGeometry(QRect(20, 20, 180, 121));
        tableWidget->setBaseSize(QSize(84, 0));
        tableWidget->setRowCount(4);
        tableWidget->setColumnCount(4);
        tableWidget->horizontalHeader()->setVisible(false);
        tableWidget->verticalHeader()->setVisible(false);
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(430, 70, 54, 17));
        tableWidget_3 = new QTableWidget(centralwidget);
        if (tableWidget_3->columnCount() < 4)
            tableWidget_3->setColumnCount(4);
        if (tableWidget_3->rowCount() < 4)
            tableWidget_3->setRowCount(4);
        tableWidget_3->setObjectName(QString::fromUtf8("tableWidget_3"));
        tableWidget_3->setGeometry(QRect(450, 20, 271, 121));
        tableWidget_3->setBaseSize(QSize(84, 0));
        tableWidget_3->setRowCount(4);
        tableWidget_3->setColumnCount(4);
        tableWidget_3->horizontalHeader()->setVisible(false);
        tableWidget_3->verticalHeader()->setVisible(false);
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(500, 170, 80, 21));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 725, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "*", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "=", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "\321\200\320\260\321\201\321\201\321\207\320\270\321\202\320\260\321\202\321\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
