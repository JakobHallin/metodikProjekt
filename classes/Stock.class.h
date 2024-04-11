#ifndef STOCK_H
#define STOCK_H
#include <QObject>
class Stock: public QObject  {
    Q_OBJECT
private:
    int amount; //ska aldrig ändras
    const int id;
    int testdata = 0;

public:
    explicit Stock(int id, int amount, QObject *parent = nullptr);
    //void setID(int id);
    void setAmount(int n);
    int getID() const { return id; }
//    getAmount();
    int getAmount() { return amount; }
    void addAmount(int number);
signals:
    void amountChanged(int newAmount);

};
#endif
