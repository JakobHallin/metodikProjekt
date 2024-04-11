#ifndef USER_H
#define USER_H

#include <vector>
#include <QObject>
#include "Sql.class.h"
#include "Account.class.h"

class User: public QObject {
private:
    std::vector<Account*> Accounts;

public:
    User(QString userID);
    int getSize();
    int getAmountStocks(int AccountIndex);
    int getAccountsStockID(int AccountIndex, int stockIndex);
    int getAccountsStockAmount(int AccountIndex, int stockIndex);
    int getAccountID(int index);
    float getBalance(int index);
    void buyFromAccountStockAmount(int AccountIndex, int StockID, int amount);
    void sellFromAccountStockAmount(int AccountIndex, int StockID, int amount);
    void addAccount(Account* Add);
    std::vector<Account*> getAccounts();
    void changeBalance(int index, float amount);
    bool stockExist(int id);
};

#endif
