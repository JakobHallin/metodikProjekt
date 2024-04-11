#ifndef STOCK_H
#define STOCK_H

class Stock {
private:
    int amount;
    int id;

public:
    Stock(int id, int amount);
    void setID(int id);
    void setAmount(int n);
    int getAmount();
    int getID();
    void addAmount(int number);
};
#endif