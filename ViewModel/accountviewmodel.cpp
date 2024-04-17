#include "accountviewmodel.h"

AccountViewModel::AccountViewModel(QObject* parent): QObject(parent) {

}



void AccountViewModel::setAccount(Account* account){
    this->account = account;
    //connect(account, &Account::balanceChanged, this, &AccountViewModel::accountUpdate);
    //connect(account, &Account::stocksChanged, this, &AccountViewModel::accountUpdate);
    connect(this->account, &Account::balanceChanged, this, &AccountViewModel::updateBalance); //Stock::amountChanged, this, &StockViewModel::stockUpdate);
    addStockViewModel(account);
}
int AccountViewModel::id() const{
    return account ? account->getID() : -1;
}

float AccountViewModel::balance() const{
    return account ? account->getBalance() : 0.0f;
}


void AccountViewModel::buy(int stockID, int amount){
    if (account) {
        account->buyStock(stockID, amount);
    }
}
void AccountViewModel::sell(int stockID, int amount){
    if (account) {
        account->sellStock(stockID, amount);
    }
}
void AccountViewModel::updateBalance(float value){
    emit balanceChanged(value);

}
/*void AccountViewModel::accountUpdate(){
    emit holdingsChanged();
}
*/
Account* AccountViewModel::getAccount(){ //will not be used
    return account;
}
void AccountViewModel::addStockViewModel(Account * account){
    //for loop
     QVector<Stock*> myVector = account->getHolding();
    for (Stock* stock : myVector) {
         if (stock) {
            StockViewModel* pointerstockviewmodel =  new StockViewModel();
             pointerstockviewmodel->setStock(stock);
             this->stockViewModels.append(pointerstockviewmodel);


            // StockViewModel* pointerstockviewmodel =  new StockViewModel(account->getHolding().at(0));
        }

    }

    //this->stockViewModels.append(pointerstockviewmodel);


}
QVector<StockViewModel*> AccountViewModel::getstockViewModels(){
    return this->stockViewModels;
}
