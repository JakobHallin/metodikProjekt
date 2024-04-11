#include "Stock.class.h"

Stock::Stock(int id, int amount) : id(id), amount(amount) {}

void Stock::setID(int id) {
    this->id = id;
}

void Stock::setAmount(int n) {
    amount = n;
}

int Stock::getAmount() {
    return amount;
}

int Stock::getID() {
    return id;
}

void Stock::addAmount(int number) {
    amount += number;
}