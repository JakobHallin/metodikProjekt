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


    /*
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
    */


/*
    Stock* stockpointer = new Stock(2,3);
    StockViewModel* viewModel = new StockViewModel();
    viewModel->setStock(stockpointer);

    stockview* stockView = new stockview();
    stockView->setViewmodel(viewModel);
    stockView->show();

 //no memmory losee


*/

    //testin accountview mvvm
/*
    Account test (1, 5000.4);
    Account* account= &test;
    AccountViewModel * accountViewmodel = new AccountViewModel();
    accountViewmodel->setAccount(account);
    QVector <StockViewModel*> stockmodel = accountViewmodel->getstockViewModels();
    qDebug() << stockmodel.at(0)->id();
    accountview* view2= new accountview();
    view2->setViewmodel(accountViewmodel);
    view2->makeStockview();
    view2->generateStockView();
    view2->show();
    //no memmory lose

*/
/*
    User* usertest = new User("Jakob");
    usertest->getBalance(0);
    UserViewModel* userviewmodel = new UserViewModel();
    userviewmodel->setUser(usertest);
    userview * view = new userview();
    view->setViewmodel(userviewmodel);
    view->makeAccountView();
    //view->generateAccountView();
    view->show();
    //no memmory lose;

*/
    std::unique_ptr<QString> message = std::make_unique<QString>("Should have started with making smartpointer");
    std::cout << message->toStdString() << std::endl;
    MainWindow w;
    w.show();
    return a.exec();
}
