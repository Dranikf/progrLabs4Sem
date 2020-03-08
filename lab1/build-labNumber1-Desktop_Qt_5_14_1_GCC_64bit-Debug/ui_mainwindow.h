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
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QTabWidget *tabWidget;
    QWidget *task1;
    QLabel *label_2;
    QLineEdit *lineEdit_2;
    QLabel *label_3;
    QLabel *label_4;
    QPushButton *resultButton;
    QLabel *label_5;
    QWidget *task2;
    QLineEdit *lineEdit_3;
    QPushButton *resultButton_2;
    QLabel *label_7;
    QLabel *label_6;
    QTextEdit *textEdit;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(398, 338);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(20, 10, 351, 271));
        task1 = new QWidget();
        task1->setObjectName(QString::fromUtf8("task1"));
        label_2 = new QLabel(task1);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 10, 171, 17));
        lineEdit_2 = new QLineEdit(task1);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(10, 80, 291, 25));
        label_3 = new QLabel(task1);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(10, 40, 211, 17));
        label_4 = new QLabel(task1);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(20, 140, 54, 17));
        resultButton = new QPushButton(task1);
        resultButton->setObjectName(QString::fromUtf8("resultButton"));
        resultButton->setGeometry(QRect(20, 174, 131, 51));
        label_5 = new QLabel(task1);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(90, 140, 71, 17));
        tabWidget->addTab(task1, QString());
        task2 = new QWidget();
        task2->setObjectName(QString::fromUtf8("task2"));
        lineEdit_3 = new QLineEdit(task2);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));
        lineEdit_3->setGeometry(QRect(20, 20, 291, 25));
        resultButton_2 = new QPushButton(task2);
        resultButton_2->setObjectName(QString::fromUtf8("resultButton_2"));
        resultButton_2->setGeometry(QRect(30, 174, 131, 51));
        label_7 = new QLabel(task2);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(240, 190, 71, 17));
        label_6 = new QLabel(task2);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(190, 190, 54, 17));
        textEdit = new QTextEdit(task2);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setGeometry(QRect(20, 50, 291, 101));
        tabWidget->addTab(task2, QString());
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 398, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "\320\262\321\213\321\207\320\270\321\201\320\273\320\265\320\275\320\270\320\265 \320\277\320\276 \321\204\320\276\321\200\320\274\321\203\320\273\320\265", nullptr));
        lineEdit_2->setText(QString());
        label_3->setText(QCoreApplication::translate("MainWindow", "\320\267\320\260\320\264\320\260\320\271\321\202\320\265 \321\207\320\265\321\200\320\265\320\267 \320\277\321\200\320\276\320\261\320\265\320\273 \321\202\321\200\320\270 \321\207\320\270\321\201\320\273\320\260", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "\320\276\321\202\320\262\320\265\321\202: ", nullptr));
        resultButton->setText(QCoreApplication::translate("MainWindow", "calculate", nullptr));
        label_5->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(task1), QCoreApplication::translate("MainWindow", "\320\227\320\260\320\267\320\260\320\275\320\270\320\265 1", nullptr));
        lineEdit_3->setText(QString());
        resultButton_2->setText(QCoreApplication::translate("MainWindow", "calculate", nullptr));
        label_7->setText(QString());
        label_6->setText(QCoreApplication::translate("MainWindow", "\320\276\321\202\320\262\320\265\321\202: ", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(task2), QCoreApplication::translate("MainWindow", "\320\227\320\260\320\264\320\260\320\275\320\270\320\265 2", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
