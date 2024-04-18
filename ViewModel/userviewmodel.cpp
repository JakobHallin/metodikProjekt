#include "userviewmodel.h"

UserViewModel::UserViewModel(QObject* parent): QObject(parent) {}
void UserViewModel::setUser(User* user){
    this->user = user;
    addAccountViewModel(user);


}
void UserViewModel::addAccountViewModel(User * user){
    //for loop
    QVector<Account*> myVector = user->getAccounts();
    for (Account* account : myVector) {
        if (account) {
            AccountViewModel* pointeraccountviewmodel =  new AccountViewModel();
            pointeraccountviewmodel->setAccount(account);                //(stock);
            this->accountViewModels.append(pointeraccountviewmodel);
            //this->stockViewModels.append(pointerstockviewmodel);


            // StockViewModel* pointerstockviewmodel =  new StockViewModel(account->getHolding().at(0));
        }
    }
}
