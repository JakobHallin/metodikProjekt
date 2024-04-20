#include "Stock.class.h"

Stock::Stock(int id, int amount, QObject *parent) : QObject(parent), id(id), amount(amount) {}

/*
void Stock::setID(int id) {
    this->id = id;
}
*/
void Stock::setAmount(int n) {

        amount = n;

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
void Stock::removeAmount(int number){
    if (amount > number  ) {
        amount -= number;
        emit amountChanged(amount); //emits signal
    }

}
void Stock::addAmount(int number) {
    //amount += number;
    if (number != 0) {
        amount += number;
        emit amountChanged(amount); //emits signal
    }
}
