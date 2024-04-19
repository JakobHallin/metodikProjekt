#include "userview.h"
#include "ui_userview.h"

userview::userview(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::userview)
{
    ui->setupUi(this);
     ui->centralwidget->setStyleSheet("border: 1px solid blue;");
   // setMinimumSize(QSize(800, 1400));

   //ui->scrollArea->setWidgetResizable(true);
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
void userview::setViewmodel(UserViewModel* viewmodel){
    this->viewModel = viewmodel;

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
void userview::generateAccountView(){
    QWidget *scrollWidget = ui->scrollArea->widget();
    QVBoxLayout *scrollLayout;


    if (scrollWidget == nullptr) {
        // If the scroll area does not have a widget, set one with a vertical layout
        scrollWidget = new QWidget();
        //ui->scrollArea->setWidget(scrollWidget); // Assign the new widget to the scroll area

        scrollLayout = new QVBoxLayout(scrollWidget); // Create the layout and assign it to the content widget
        scrollWidget->setLayout(scrollLayout);
    }
    //QVBoxLayout
    else {
        scrollLayout = qobject_cast<QVBoxLayout*>(scrollWidget->layout());

        if (!scrollLayout) { // If the layout is not a QVBoxLayout or does not exist
            // If the cast failed, create a new QVBoxLayout
            scrollLayout = new QVBoxLayout(scrollWidget);

            scrollWidget->setLayout(scrollLayout);


        }
    }

   // scrollLayout->setAlignment(Qt::AlignTop);
    //scrollWidget->layout()->activate();
    scrollLayout->setContentsMargins(10, 10, 10, 10);
    scrollLayout->setSpacing(0);

    for (accountview* view : this->accounts) {
        if (view){
            /*

            view->generateStockView();
            view->setSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);

            //view->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
            //view->getviewModel()->amount();
            //view->getviewModel()->id();
            //view->setSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
            scrollLayout->addWidget(view);
            //scrollLayout->addWidget()

*/
            QScrollArea* individualScrollArea = new QScrollArea(scrollWidget);
            individualScrollArea->setWidgetResizable(true);
            //individualScrollArea->setFrameShape(QFrame::NoFrame); // Optional, removes the frame for aesthetics.
            view->generateStockView();
            individualScrollArea->setWidget(view);
            individualScrollArea->setContentsMargins(10,10,10,10);
            individualScrollArea->setMinimumSize(QSize(400, 450));


            view->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);

            // Add the individual scroll area to the layout instead of the view directly.
            scrollLayout->addWidget(individualScrollArea);

        }
    }

     ui->scrollArea->setWidget(scrollWidget);

    ui->scrollArea->setWidgetResizable(true); // Make sure this is set to allow dynamic resizing
    //scrollWidget->adjustSize(); // Adjust size of the scroll widget after adding children
    //ui->scrollArea->update();
}

void userview::makeAccountView(){

    // this->viewModel = viewModel;
    QVector<AccountViewModel*> myVector = this->viewModel->getAccountViewModel();
                                         //getaViewModels(); //fell hära



    //loop stockviewmodel for stocksviewsmodels
    qDebug() << "amount of stockviews to add:" << myVector.size();
    for (AccountViewModel* viewItem : myVector) {
        if (viewItem){
            qDebug() << "StockViewModel pointer exist";
            accountview* accountView = new accountview();
            qDebug() << "StockView created succseed";
            accountView->setViewmodel(viewItem);
            accountView->makeStockview();
            //accountView->generateStockView();

            accounts.append(accountView);
        }
        else {
            qDebug() << "StockViewModel pointer null";
        }
    }
    this->generateAccountView();

}

