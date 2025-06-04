/********************************************************************************
** Form generated from reading UI file 'accountview.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ACCOUNTVIEW_H
#define UI_ACCOUNTVIEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_accountview
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QLabel *label_2;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QPushButton *BuyButton;
    QPushButton *SellButton;
    QLineEdit *lineEditStockId;
    QLineEdit *lineEdidAmount;
    QLabel *AccountIdLabel;
    QLabel *BalanceLabel;
    QLabel *label_3;
    QLabel *label_4;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *accountview)
    {
        if (accountview->objectName().isEmpty())
            accountview->setObjectName("accountview");
        accountview->resize(342, 420);
        centralwidget = new QWidget(accountview);
        centralwidget->setObjectName("centralwidget");
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(10, 20, 81, 31));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(210, 30, 67, 17));
        scrollArea = new QScrollArea(centralwidget);
        scrollArea->setObjectName("scrollArea");
        scrollArea->setGeometry(QRect(10, 70, 321, 181));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName("scrollAreaWidgetContents");
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 319, 179));
        scrollArea->setWidget(scrollAreaWidgetContents);
        BuyButton = new QPushButton(centralwidget);
        BuyButton->setObjectName("BuyButton");
        BuyButton->setGeometry(QRect(50, 300, 89, 41));
        SellButton = new QPushButton(centralwidget);
        SellButton->setObjectName("SellButton");
        SellButton->setGeometry(QRect(210, 300, 91, 41));
        lineEditStockId = new QLineEdit(centralwidget);
        lineEditStockId->setObjectName("lineEditStockId");
        lineEditStockId->setGeometry(QRect(70, 260, 71, 21));
        lineEdidAmount = new QLineEdit(centralwidget);
        lineEdidAmount->setObjectName("lineEdidAmount");
        lineEdidAmount->setGeometry(QRect(240, 260, 71, 21));
        AccountIdLabel = new QLabel(centralwidget);
        AccountIdLabel->setObjectName("AccountIdLabel");
        AccountIdLabel->setGeometry(QRect(100, 20, 51, 31));
        BalanceLabel = new QLabel(centralwidget);
        BalanceLabel->setObjectName("BalanceLabel");
        BalanceLabel->setGeometry(QRect(290, 30, 67, 17));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(180, 260, 61, 21));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(10, 260, 61, 21));
        accountview->setCentralWidget(centralwidget);
        menubar = new QMenuBar(accountview);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 342, 22));
        accountview->setMenuBar(menubar);
        statusbar = new QStatusBar(accountview);
        statusbar->setObjectName("statusbar");
        accountview->setStatusBar(statusbar);

        retranslateUi(accountview);

        QMetaObject::connectSlotsByName(accountview);
    } // setupUi

    void retranslateUi(QMainWindow *accountview)
    {
        accountview->setWindowTitle(QCoreApplication::translate("accountview", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("accountview", "AcccountID", nullptr));
        label_2->setText(QCoreApplication::translate("accountview", "Balance:", nullptr));
        BuyButton->setText(QCoreApplication::translate("accountview", "Buy", nullptr));
        SellButton->setText(QCoreApplication::translate("accountview", "Sell", nullptr));
        lineEditStockId->setText(QCoreApplication::translate("accountview", "0", nullptr));
        lineEdidAmount->setText(QCoreApplication::translate("accountview", "0", nullptr));
        AccountIdLabel->setText(QCoreApplication::translate("accountview", "0", nullptr));
        BalanceLabel->setText(QCoreApplication::translate("accountview", "0", nullptr));
        label_3->setText(QCoreApplication::translate("accountview", "Amount:", nullptr));
        label_4->setText(QCoreApplication::translate("accountview", "StockId:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class accountview: public Ui_accountview {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ACCOUNTVIEW_H
