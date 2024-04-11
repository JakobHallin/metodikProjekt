#include "accountview.h"
#include "ui_accountview.h"
//AccountViewModel* viewModel
accountview::accountview(AccountViewModel* viewModel, QWidget *parent)
    : QMainWindow(parent), ui(new Ui::accountview) {
    ui->setupUi(this);
    setMinimumSize(QSize(400, 200));
    /*addStock(2,3);
    addStock(3,5);
    addStock(5,3);
*/
}

accountview::~accountview()
{
    delete ui;
}
/*stockview* accountview::addStock(AccountViewModel* viewModel){
   // Stock* stockpointer = viewModel->getAccount()->getHolding().at(0);
   // Stock

}*/
  void accountview::addStock(AccountViewModel* viewModel){


      QVector<StockViewModel*> myVector = viewModel->getstockViewModels();
      for (StockViewModel* stockviewItem : myVector) {
          if (stockviewItem){
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
                scrollLayout->addWidget(stockview);
                scrollLayout->setContentsMargins(10, 0, 0, 20);
        //scrollLayout->setAlignment(Qt::AlignTop);
        //stocks.append(stockView);
            stocks.append(stockView);
            }
        scrollLayout->setAlignment(Qt::AlignTop);
        scrollWidget->layout()->activate();

    //scrollWidget->updateGeometry();
    //ui->scrollArea->updateGeometry();
    // scrollLayout->addWidget(accountView);

    // scrollWidget->adjustSize();
    // scrollLayout->setContentsMargins(10, 0, 0, 20);
    //scrollLayout->update();
      }
    }
}

