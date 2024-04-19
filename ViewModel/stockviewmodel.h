#ifndef STOCKVIEWMODEL_H
#define STOCKVIEWMODEL_H
#include <QObject>
#include "../classes/Stock.class.h"
class StockViewModel: public QObject
{
    Q_OBJECT
public:
    explicit StockViewModel(QObject *parent = nullptr);
    void setStock(Stock* stock); // Associate a Stock model with this ViewModel

    int id() const;
    int amount() const;
signals:
    void amountChanged(int amount);
private:
    //int testdata = 2;
    Stock* stock;
private slots:
    void stockUpdate(int newAmount); //works


};

#endif // STOCKVIEWMODEL_H
