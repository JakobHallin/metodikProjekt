#include "accountview.h"
#include "ui_accountview.h"
//AccountViewModel* viewModel
accountview::accountview(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::accountview) {
    ui->setupUi(this);
    setMinimumSize(QSize(400, 200));
    //makeStockview();//dont work this->viewmodel not init

    //makeStockview(viewModel);
    //connect(ui->BuyButton, &QPushButton::clicked, this, &accountview::pushBuyButton);


    /*addStock(2,3);
    addStock(3,5);
    addStock(5,3);
*/
}

accountview::~accountview()
{
    delete ui;
}
void accountview::pushBuyButton(){
    QString amount = ui->lineEdidAmount->text();
    int intAmount;
    bool amountOk;
    intAmount = amount.toInt(&amountOk);

    QString stockId = ui->lineEditStockId->text();
    int intStockId; // = stockId.toInt();
    bool stockOk;
    intStockId = stockId.toInt(&stockOk);
 //debug
    qDebug() << "Amount:" << amount << "Converted to int:" << intAmount << "Conversion success:" << amountOk;
    qDebug() << "Stock ID:" << stockId << "Converted to int:" << intStockId << "Conversion success:" << stockOk;


    //
    if (amountOk && stockOk && intAmount > 0 && intStockId > 0){
        qDebug()<< "buying from view";
        this->viewModel->buy(intStockId, intAmount); //verkar bli skuma värden
    //this->viewModel->buy(stockId, amount);
    }
    else qDebug()<< "error with buy view buy";
     qDebug() << "done";

}
void accountview::pushSellButton(){
    QString amount = ui->lineEdidAmount->text();
    int intAmount;
    bool amountOk;
    intAmount = amount.toInt(&amountOk);

    QString stockId = ui->lineEditStockId->text();
    int intStockId; // = stockId.toInt();
    bool stockOk;
    intStockId = stockId.toInt(&stockOk);
    //debug
    qDebug() << "Amount:" << amount << "Converted to int:" << intAmount << "Conversion success:" << amountOk;
    qDebug() << "Stock ID:" << stockId << "Converted to int:" << intStockId << "Conversion success:" << stockOk;


    //
    if (amountOk && stockOk && intAmount > 0 && intStockId > 0){
        qDebug()<< "buying from view";
        this->viewModel->sell(intStockId, intAmount); //verkar bli skuma värden
        //this->viewModel->buy(stockId, amount);
    }
    else qDebug()<< "error with buy view buy";
    //ui->BalanceLabel->setText(QString::number(this->viewModel->getAccount()->getBalance()));
    //måste veta vilken stock
    /*
     * for (int i = 0; i< this->stocks.size(); i++){

    this->stocks[i]->updateView();
        qDebug()<< "looped";
    }
    */
    qDebug() << "done";

}

void accountview::setViewmodel(AccountViewModel* viewmodel){
    this->viewModel = viewmodel;
    connect(ui->BuyButton, &QPushButton::clicked, this, &accountview::pushBuyButton);
    connect(ui->SellButton, &QPushButton::clicked, this, &accountview::pushSellButton);

    ui->AccountIdLabel->setText(QString::number(this->viewModel->getAccount()->getID()));
    //ui->BalanceLabel->setText(QString::number(this->viewModel->getAccount()->getBalance()));

    connect(this->viewModel, &AccountViewModel::balanceChanged, this, &accountview::updateBalanceDisplay);
    updateBalanceDisplay(this->viewModel->balance());


    //viewmodel->getAccount()->getID());
    //ui->lab
      //  (stringAmount);
}
//void account::setAccount
/*stockview* accountview::addStock(AccountViewModel* viewModel){
   // Stock* stockpointer = viewModel->getAccount()->getHolding().at(0);
   // Stock

}*/

void accountview::generateStockView(){
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
            for (stockview* stockview : this->stocks) {
                if (stockview){

                    stockview->getviewModel()->amount();
                    stockview->getviewModel()->id();
                    scrollLayout->addWidget(stockview);
                }
            }
}
void accountview::makeStockview(){

     // this->viewModel = viewModel;
    QVector<StockViewModel*> myVector = this->viewModel->getstockViewModels(); //fell hära

    //QWidget *scrollWidget = ui->scrollArea->widget();
    //QVBoxLayout *scrollLayout;

    /*
     * if (scrollWidget == nullptr) {
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
*/


//loop stockviewmodel for stocksviewsmodels
        qDebug() << "amount of stockviews to add:" << myVector.size();
        for (StockViewModel* stockviewItem : myVector) {
            if (stockviewItem){
                qDebug() << "StockViewModel pointer exist";
                 stockview* stockView = new stockview();
                qDebug() << "StockView created succseed";
                 stockView->setViewmodel(stockviewItem);
                //scrollLayout->addWidget(stockView);
                //scrollLayout->setContentsMargins(10, 0, 0, 20);


                stocks.append(stockView);
            }
            else {
                qDebug() << "StockViewModel pointer null";
            }
        }
}
void accountview::updateBalanceDisplay(float value){
    //this.->BalanceLabel->setText(QString::number(this->viewModel->getAccount()->getBalance()));
    this->ui->BalanceLabel->setText(QString::number(this->viewModel->balance()));

}
