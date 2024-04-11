#include "userview.h"
#include "ui_userview.h"

userview::userview(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::userview)
{
    ui->setupUi(this);
    ui->scrollArea->setWidgetResizable(true);
   //accountview* test = addAccountView(1, 10008);
    //test->addStock(100,200);
   /*  accountview* test2 = addAccountView(2, 10008);
   accountview* test3 = addAccountView(3, 10008);
    accountview* test4 = addAccountView(4, 10008);
   accountview* test5 = addAccountView(5, 10008);
   accountview* test6 = addAccountView(6, 10008); */

   //accountview* test7 = addAccountView(6, 10008);
   //accountview* test8 = addAccountView(8, 10008);


    //ui->scrollArea->update();
}

userview::~userview()
{
    delete ui;
}
/*accountview* userview::addAccountView(int accountId, int balance) {
    // Assumes the layout is already created in the constructor
    accountview *accountView = new accountview(accountId, balance, this);
    QWidget *scrollWidget = ui->scrollArea->widget();
    QVBoxLayout *scrollLayout;

    if (scrollWidget == nullptr) {
        // If the scroll area does not have a widget, set one with a vertical layout
        scrollWidget = new QWidget();
        ui->scrollArea->setWidget(scrollWidget); // Assign the new widget to the scroll area
        scrollLayout = new QVBoxLayout(scrollWidget); // Create the layout and assign it to the content widget
        scrollWidget->setLayout(scrollLayout);
    }
    //QVBoxLayout
    else {
        scrollLayout = qobject_cast<QVBoxLayout*>(scrollWidget->layout());

        if (!scrollLayout) { // If the layout is not a QVBoxLayout or does not exist
             // If the cast failed, create a new QVBoxLayout
                scrollLayout = new QVBoxLayout(scrollWidget);
            // Create a new QVBoxLayout if the cast failed
            //scrollLayout = new QVBoxLayout();
            //crollLayout->addWidget(accountView);
            //  scrollLayout->setContentsMargins(10, 0, 0, 20);
            //scrollLayout->setAlignment(Qt::AlignTop);
            //  scrollWidget->setLayout(scrollLayout);
            //accounts.append(accountView);

        }
    }
    if (scrollLayout) {
            scrollLayout->addWidget(accountView);
            scrollLayout->setContentsMargins(10, 0, 0, 20);
           //scrollLayout->setAlignment(Qt::AlignTop);
            accounts.append(accountView);
    }
    scrollLayout->setAlignment(Qt::AlignTop);
    scrollWidget->layout()->activate();

    //scrollWidget->updateGeometry();
    //ui->scrollArea->updateGeometry();
   // scrollLayout->addWidget(accountView);

   // scrollWidget->adjustSize();
   // scrollLayout->setContentsMargins(10, 0, 0, 20);
   //scrollLayout->update();
    return accountView;
}
*/
