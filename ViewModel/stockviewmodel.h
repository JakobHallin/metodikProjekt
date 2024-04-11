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
    void amountChanged();
private:
    Stock* stock;
private slots:
    void stockUpdate(); //not yet implemented


};

#endif // STOCKVIEWMODEL_H
