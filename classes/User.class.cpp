#include "User.class.h"


User::User(QString userID) {
    QString userID2 = "jakob";
    //userID = userID.toLower();
    //std::string sql = "SELECT * FROM Accounts WHERE UserID = '" + std::to_string(userID) + "'";
    QString sql = QString("SELECT * FROM Accounts WHERE UserID= '%1'").arg(userID2); // '%1' för att see till att den inte antar det som coulumn

    Sql classSql;
    QSqlQuery stmt = classSql.execute(sql); //error here cause Execute failed: "Unknown column 'jakob' in 'where clause' QMYSQL: Unable to execute query"
    if (!stmt.exec()) { // Notice the use of exec() directly on the QSqlQuery object
        qDebug() << "Failed to execute the query:" << stmt.lastError();
        return;
    }
    while (stmt.next()) {
        int accountID = stmt.value(stmt.record().indexOf("AccountID")).toInt();
        int balance = stmt.value(stmt.record().indexOf("Balance")).toInt();

        addAccount(new Account(accountID, balance));
    }
}

int User::getSize() {
    return Accounts.size();
}

int User::getAmountStocks(int AccountIndex) {
    return Accounts.at(AccountIndex)->getSize();
}

int User::getAccountsStockID(int AccountIndex, int stockIndex) {
    return Accounts.at(AccountIndex)->getStockID(stockIndex);
}

int User::getAccountsStockAmount(int AccountIndex, int stockIndex) {
    return Accounts.at(AccountIndex)->getStockAmount(stockIndex);
}

int User::getAccountID(int index) {
    return Accounts.at(index)->getID();
}

float User::getBalance(int index) {
    return Accounts.at(index)->getBalance();
}

void User::buyFromAccountStockAmount(int AccountIndex, int StockID, int amount) {
    Accounts.at(AccountIndex)->buyStock(StockID, amount);
}

void User::sellFromAccountStockAmount(int AccountIndex, int StockID, int amount) {
    Accounts.at(AccountIndex)->sellStock(StockID, amount);
}

void User::addAccount(Account* Add) {
    Accounts.push_back(Add);
}

std::vector<Account*> User::getAccounts() {
    return Accounts;
}

void User::changeBalance(int index, float amount) {
    Accounts.at(index)->addBalance(amount);
}

bool User::stockExist(int id) {
    QString sql = QString("Select * FROM AllStocks WHERE StocksID= %1").arg(id);
    Sql classSql;
    QSqlQuery stmt = classSql.execute(sql);
    int count = 0;
    while (stmt.next()) {
        count++;
    }
    return (count == 1);
}


