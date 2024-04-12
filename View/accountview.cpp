#include "accountview.h"
#include "ui_accountview.h"
//AccountViewModel* viewModel
accountview::accountview(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::accountview) {
    ui->setupUi(this);
    setMinimumSize(QSize(400, 200));
    //makeStockview();//dont work this->viewmodel not init

    //makeStockview(viewModel);

    /*addStock(2,3);
    addStock(3,5);
    addStock(5,3);
*/
}

accountview::~accountview()
{
    delete ui;
}

void accountview::setViewmodel(AccountViewModel* viewmodel){
    this->viewModel = viewmodel;
}
//void account::setAccount
/*stockview* accountview::addStock(AccountViewModel* viewModel){
   // Stock* stockpointer = viewModel->getAccount()->getHolding().at(0);
   // Stock

}*/
 void accountview::makeStockview(){

     // this->viewModel = viewModel;
      QVector<StockViewModel*> myVector = this->viewModel->getstockViewModels(); //fell hära

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
                    scrollWidget->setLayout(scrollLayout);

                }
            }

            scrollLayout->setAlignment(Qt::AlignTop);
            //scrollWidget->layout()->activate();


//loop stockviewmodel for stocksviewsmodels
            qDebug() << "amount of stockviews to add:" << myVector.size();
        for (StockViewModel* stockviewItem : myVector) {
            if (stockviewItem){
                qDebug() << "StockViewModel pointer exist";
                 stockview* stockView = new stockview();
                qDebug() << "StockView created succseed";
                 stockView->setViewmodel(stockviewItem);
                scrollLayout->addWidget(stockView);
                scrollLayout->setContentsMargins(10, 0, 0, 20);
            //scrollLayout->setAlignment(Qt::AlignTop);
            //stocks.append(stockView);
                stocks.append(stockView);
            }
            else {
                qDebug() << "StockViewModel pointer null";
            }
        }
}

