#include "stockviewmodel.h"

StockViewModel::StockViewModel(QObject *parent): QObject(parent), stock(nullptr){


}
void StockViewModel::setStock(Stock* newStock) {
   /* if (stock) {
        disconnect(stock, nullptr, this, nullptr);
    }
*/
    stock = newStock;
    connect(stock, &Stock::amountChanged, this, &StockViewModel::stockUpdate);
}
void StockViewModel::stockUpdate() {
    // Update ViewModel properties based on the Stock model
    //emit idChanged();
    emit amountChanged();
}

int StockViewModel::id() const {
    return stock ? stock->getID() : 0;
}

int StockViewModel::amount() const {
    return stock ? stock->getAmount() : 0;
}
