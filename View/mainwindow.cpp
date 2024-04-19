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
void MainWindow::pushLoginButton(){

    //userview *otherView = new userview();
    //otherView->setAttribute(Qt::WA_DeleteOnClose); // Ensure the view is deleted when closed
    //otherView->show();

    User* usertest = new User("Jakob");
    usertest->getBalance(0);
    UserViewModel* userviewmodel = new UserViewModel();
    userviewmodel->setUser(usertest);
    userview * view = new userview();
    view->setViewmodel(userviewmodel);
    view->makeAccountView();
    //view->generateAccountView();
    view->setAttribute(Qt::WA_DeleteOnClose); // Ensure the view is deleted when closed

    view->show();



}
