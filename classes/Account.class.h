#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <vector>
#include "Sql.class.h"
#include "Api.class.h"
#include <QSqlRecord>
#include "Stock.class.h"
#include <QObject>
//#include "api.h"

class Account: public QObject {
    Q_OBJECT
private:
    int id;
    float balance;
    QVector<Stock*> holding;
    
    void updateStockHolding(int stockID, int stockAmount);
    void insertNewStock(int stockId, int amount);
    void changeHolding(int index, int amount);

public:
    Account(int id, float balance, QObject *parent =nullptr);
    int getSize();
    int getStockID(int index);
    int getStockAmount(int index);
    void setBalance(float n);
    int getID();
    float getBalance();
    QVector<Stock*> getHolding();

    void addStock(Stock* stock);
    void addBalance(float totalprice);
    void removeFromBalance(float totalprice);
    float getPrice(int stockID);

    void buyStock(int StockId, int amount);
    void sellStock(int StockID, int amount);

signals:
    void balanceChanged(float value);
    //void stocksChanged();
};

#endif
