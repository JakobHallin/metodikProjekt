/********************************************************************************
** Form generated from reading UI file 'stockview.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STOCKVIEW_H
#define UI_STOCKVIEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_stockview
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *stockview)
    {
        if (stockview->objectName().isEmpty())
            stockview->setObjectName("stockview");
        stockview->resize(365, 116);
        centralwidget = new QWidget(stockview);
        centralwidget->setObjectName("centralwidget");
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(80, 30, 67, 17));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(250, 30, 67, 17));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(20, 30, 67, 17));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(180, 30, 67, 17));
        stockview->setCentralWidget(centralwidget);
        menubar = new QMenuBar(stockview);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 365, 22));
        stockview->setMenuBar(menubar);
        statusbar = new QStatusBar(stockview);
        statusbar->setObjectName("statusbar");
        stockview->setStatusBar(statusbar);

        retranslateUi(stockview);

        QMetaObject::connectSlotsByName(stockview);
    } // setupUi

    void retranslateUi(QMainWindow *stockview)
    {
        stockview->setWindowTitle(QCoreApplication::translate("stockview", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("stockview", "TextLabel", nullptr));
        label_2->setText(QCoreApplication::translate("stockview", "TextLabel", nullptr));
        label_3->setText(QCoreApplication::translate("stockview", "StockID:", nullptr));
        label_4->setText(QCoreApplication::translate("stockview", "Amount:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class stockview: public Ui_stockview {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STOCKVIEW_H
