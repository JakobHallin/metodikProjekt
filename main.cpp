#include "View/mainwindow.h"
#include "classes/User.class.h"
#include "View/userview.h"
#include "classes/Stock.class.h"
#include "classes/Account.class.h"
#include "ViewModel/accountviewmodel.h"
#include "ViewModel/userviewmodel.h"
#include "View/accountview.h"
#include "View/stockview.h"
#include "View/stockview.h"
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QApplication>
#include <QTextStream>
#include <iostream>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
