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
    userview *otherView = new userview();
    otherView->setAttribute(Qt::WA_DeleteOnClose); // Ensure the view is deleted when closed
    otherView->show();

}
