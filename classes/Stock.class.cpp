#include "Stock.class.h"

Stock::Stock(int id, int amount, QObject *parent) : QObject(parent), id(id), amount(amount) {}

/*
void Stock::setID(int id) {
    this->id = id;
}
*/
void Stock::setAmount(int n) {
    this->amount = n;
    if (amount != n) {
        amount = n;
        //emit amountChanged(n);
    }
}
/*
int Stock::getAmount() {
    return amount;
}
*/
/*int Stock::getID() {
    return id;
}
*/
void Stock::addAmount(int number) {
    //amount += number;
    if (number != 0) {
        amount += number;
        emit amountChanged(amount); //emits signal
    }
}
