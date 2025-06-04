#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->pushbutton, &QPushButton::clicked, this, &MainWindow::pushLoginButton);
}
MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::pushLoginButton(){ //tested try catch makes it dont work if wrong username

    //userview *otherView = new userview();
    //otherView->setAttribute(Qt::WA_DeleteOnClose); // Ensure the view is deleted when closed
    //otherView->show();

    QString username = ui->username->text();
    //cheack if username is valid;
    //then
    //std::string sql = "SELECT * FROM Accounts WHERE UserID = '" + std::to_string(userID) + "'";
    QString sql = QString("SELECT * FROM Accounts WHERE UserID= '%1'").arg(username); // '%1' för att see till att den inte antar det som coulumn

    Sql classSql;
    QSqlQuery stmt = classSql.execute(sql);
    if (!stmt.exec()) { // Notice the use of exec() directly on the QSqlQuery object
        qDebug() << "Failed to execute the query:" << stmt.lastError();
        return;
    }
    if (stmt.next()) {

        User* usertest = new User(username);
        usertest->getBalance(0);
        UserViewModel* userviewmodel = new UserViewModel();
        userviewmodel->setUser(usertest);
        userview * view = new userview();
        view->setViewmodel(userviewmodel);


        view->makeAccountView();
        //view->generateAccountView();
        view->setAttribute(Qt::WA_DeleteOnClose); // Ensure the view is deleted when closed
        //works by using parrent


        view->show();
    }

}
