#include "stockviewmodel.h"

StockViewModel::StockViewModel(QObject *parent): QObject(parent){


}
void StockViewModel::setStock(Stock* newStock) {

 /*   if (stock) {
        disconnect(stock, &Stock::amountChanged, this, &StockViewModel::stockUpdate);
    }
*/

    stock = newStock;
    if (stock){
        connect(stock, &Stock::amountChanged, this, &StockViewModel::stockUpdate);
    }

    //connect(stock, &Stock::amountChanged, this, &StockViewModel::stockUpdate);
}
void StockViewModel::stockUpdate(int newAmount) {
    // Update ViewModel properties based on the Stock model
    //emit idChanged();
    emit amountChanged(newAmount);
}

int StockViewModel::id() const {
    return stock ? stock->getID() : 0; //error
}

int StockViewModel::amount() const {
    return stock ? stock->getAmount() : 0;
}
