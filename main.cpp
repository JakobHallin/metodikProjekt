#include "View/mainwindow.h"
#include "classes/User.class.h"
#include "classes/Stock.class.h"
#include "classes/Account.class.h"
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
    /*
     * QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL"); // Use the MySQL driver for MariaDB
    db.setHostName("localhost"); // Or your specific database host
    db.setDatabaseName("metodik"); // Your database name
    db.setUserName("root"); // Your database username
    db.setPassword("hallin"); // Your database password
    db.setPort(3306); // Default MySQL/MariaDB port, change if necessary

    if (!db.open()) {
        qDebug() << "Error: connection with database failed:" << db.lastError().text();
    } else {
        qDebug() << "Database: connection ok";
    }*/

    //test for stock
    Stock stock1(2,3);
    //get amount works
    QString testStock =  QString::number(stock1.getAmount());
    qDebug() << testStock;
    //getId works
    testStock = QString::number(stock1.getID());
    qDebug() << testStock;
    //adding works
    stock1.addAmount(2);
    testStock = QString::number(stock1.getAmount());
    qDebug() << testStock;
    //finished test for stocks


    //testing account
    Account account1(1, 24.4); //får account stocks

    account1.getBalance();
    //QTextStream output(stdout);
    QString str =  QString::number(account1.getBalance());
    qDebug() << str;
    QString str2 = QString::number(account1.getStockID(1)); //funkar men om den är utanför size så blir det fel

    qDebug() << str2;

    User test("Jakob");
    //account och Stocks funkar
    stockview s(2,3);
    s.show();

    MainWindow w;
    w.show();
    return a.exec();
}
