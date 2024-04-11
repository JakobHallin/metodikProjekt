#include "Account.class.h"

Account::Account(int id, float balance, QObject *parent) : QObject(parent), id(id), balance(balance) {
    // Get all the stocks from the database that are related to this account
    QString sql = QString("SELECT * FROM Stock WHERE AccountID= %1").arg(id);
    Sql classSql;
    QSqlQuery stmt = classSql.execute(sql); //Becuse user should not set the arguments should be recived from databas

    
    while (stmt.next()) { // Assuming QSqlQuery is used directly or wrapped by Sql::ResultStmt
        int stockId = stmt.value("StocksID").toInt();
        int amount = stmt.value("Amount").toInt();
        this->addStock(new Stock(stockId, amount));
    }
}

int Account::getSize() {
    //return holding.size();
    return holding.size();
}

int Account::getStockID(int index) {
    //return holding[index]->getID();
    return holding.at(index)->getID();
}

int Account::getStockAmount(int index) {
    return holding.at(index)->getAmount();
}

void Account::setBalance(float n) {
    balance = n;
}

int Account::getID() {
    return id;
}

float Account::getBalance() {
    return balance;
}

std::vector<Stock*> Account::getHolding() {
    return holding;
}

void Account::addStock(Stock* stock) {
    holding.push_back(stock);
}

void Account::addBalance(float totalprice) {
    balance += totalprice;
    int accountID = getID();
    QString sql = QString("UPDATE Accounts SET Balance = Balance + %1 WHERE AccountID = %2").arg(totalprice).arg(accountID);
    Sql classSql;
    classSql.execute(sql);
}

void Account::removeFromBalance(float totalprice) {
    balance -= totalprice;
    int accountID = getID();
    QString sql = QString("UPDATE Accounts SET Balance = (SELECT Balance FROM Accounts WHERE AccountID = %1) - %2 WHERE AccountID = %1").arg(accountID).arg(totalprice);
    Sql classSql;
    classSql.execute(sql);
}

float Account::getPrice(int StockID) {
    QString shortName = "";
    QString sql = QString("SELECT * FROM AllStocks WHERE StocksID= %1").arg(StockID);
    Sql classSql;
    QSqlQuery stmt = classSql.execute(sql);
    stmt.bindValue(":stockID", StockID);
    //QSqlRecord rec = stmt.record();
    while(stmt.next()) {
        shortName = stmt.value(stmt.record().indexOf("Short")).toString();
    //row["Short"];
    }
    Api api;
    //return
    int price = api.getPrice(shortName);
    return price;

}

void Account::buyStock(int StockId, int amount) {
    bool flag = false;
    for (size_t i = 0; i < holding.size(); i++) {
        if (StockId == getStockID(i)
            //holding[i]->getID()
            ) {
            flag = true;
            float prep = getPrice(StockId);
            prep *= amount;
            if (getBalance() > prep) {
                changeHolding(i, amount);
                removeFromBalance(prep);
            }
        }
    }
    if (!flag) {
        float prep = getPrice(StockId);
        prep *= amount;
        if (getBalance() > prep) {
            balance -= prep;
            Stock* stock = new Stock(StockId, amount);
            addStock(stock);
            insertNewStock(StockId, amount);
            removeFromBalance(prep);
        }
    }
}

void Account::changeHolding(int index, int amount) {
    holding.at(index)->addAmount(amount);
    int stockAmount = getStockAmount(index);//holding[index]->getAmount();
    int stockID = getStockID(index);//holding[index]->getID();
    updateStockHolding(stockID, stockAmount);
}

void Account::updateStockHolding(int stockID, int stockAmount) {
    //std::string sql = "UPDATE Stock SET Amount = " + std::to_string(stockAmount) + " WHERE StocksID = " + std::to_string(stockID) + " AND AccountID = " + std::to_string(id);
    QString sql = QString("UPDATE Stock SET Amount = %1 WHERE StocksID = %2 AND AccountID = %3").arg(stockAmount).arg(stockID).arg(id);


    Sql classSql;
    classSql.prepareStatement(sql);
    classSql.execute(sql);
}

void Account::insertNewStock(int StockId, int amount) {
    QString sql = "INSERT INTO `Stock`(`StocksID`, `AccountID`, `Amount`) VALUES (?,?,?)";
    int id = getID();
    Sql classSql;
    classSql.insert(sql, StockId, id, amount);
}
//fixar senare
void Account::sellStock(int StockID, int amount) {
    int currentAmount = 0;
    int id = getID();
    //QString sql = "SELECT Amount FROM Stock WHERE StocksID= '" + std::to_string(StockID) + "' AND AccountID = '" + std::to_string(id) + "'";
    QString sql = QString("SELECT Amount FROM Stock WHERE StocksID= %1 AND AccountID = %2").arg(StockID).arg(id);
    Sql classSql;
    QSqlQuery stmt = classSql.execute(sql);
    while(stmt.next()) {
        currentAmount = stmt.value(stmt.record().indexOf("Short")).toInt();
    }
    if (currentAmount >= amount) {
        float price = getPrice(StockID);     
        float totalPrice = price * amount; 
        addBalance(totalPrice);
        int newAmount  = currentAmount - amount;
        updateStockHolding(StockID, newAmount);
        for (size_t i = 0; i < holding.size(); i++) {
            if (StockID == holding[i]->getID()) {
                holding[i]->setAmount(newAmount);
            }              
        }
    }            
}
//signals
void Account::balanceChanged(double newBalance){}
void Account::stocksChanged(){}

