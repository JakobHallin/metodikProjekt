/********************************************************************************
** Form generated from reading UI file 'userview.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USERVIEW_H
#define UI_USERVIEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_userview
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *userview)
    {
        if (userview->objectName().isEmpty())
            userview->setObjectName("userview");
        userview->resize(582, 547);
        centralwidget = new QWidget(userview);
        centralwidget->setObjectName("centralwidget");
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(60, 30, 67, 17));
        scrollArea = new QScrollArea(centralwidget);
        scrollArea->setObjectName("scrollArea");
        scrollArea->setGeometry(QRect(50, 60, 511, 381));
        scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        scrollArea->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName("scrollAreaWidgetContents");
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 495, 379));
        scrollArea->setWidget(scrollAreaWidgetContents);
        userview->setCentralWidget(centralwidget);
        menubar = new QMenuBar(userview);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 582, 22));
        userview->setMenuBar(menubar);
        statusbar = new QStatusBar(userview);
        statusbar->setObjectName("statusbar");
        userview->setStatusBar(statusbar);

        retranslateUi(userview);

        QMetaObject::connectSlotsByName(userview);
    } // setupUi

    void retranslateUi(QMainWindow *userview)
    {
        userview->setWindowTitle(QCoreApplication::translate("userview", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("userview", "User:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class userview: public Ui_userview {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USERVIEW_H
