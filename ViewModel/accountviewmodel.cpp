#include "accountviewmodel.h"

AccountViewModel::AccountViewModel(QObject* parent): QObject(parent) {}



void AccountViewModel::setAccount(Account* account){
    account = account;
    connect(account, &Account::balanceChanged, this, &AccountViewModel::accountUpdate);
    connect(account, &Account::stocksChanged, this, &AccountViewModel::accountUpdate);
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

void AccountViewModel::accountUpdate(){
    emit holdingsChanged();
}
