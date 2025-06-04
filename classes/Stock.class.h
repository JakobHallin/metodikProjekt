#ifndef STOCK_H
#define STOCK_H

#include <QObject>

/**
 * @class Stock
 * @brief Represents a stock in the system with ID, name, and price.
 *
 * The Stock class encapsulates a stock’s unique identifier and the number of shares
 * (amount) owned. It emits a signal whenever the amount changes.
 */
class Stock : public QObject {
    Q_OBJECT

private:
    int amount;            ///< Number of shares owned (does not change elsewhere).
    const int id;          ///< Unique identifier for this stock.
    int testdata = 0;      ///< Test data (for debugging or placeholder).

public:
    /**
     * @brief Constructs a Stock object.
     *
     * Initializes a Stock with the given ID and starting amount.
     *
     * @param id     The stock ID.
     * @param amount Initial number of shares.
     * @param parent Optional parent QObject.
     */
    explicit Stock(int id, int amount, QObject *parent = nullptr);

    /**
     * @brief Sets the amount of shares owned.
     *
     * Updates the internal amount and emits amountChanged() if the value changes.
     *
     * @param n New number of shares.
     */
    void setAmount(int n);

    /**
     * @brief Gets the stock ID.
     * @return Stock ID.
     */
    int getID() const { return id; }

    /**
     * @brief Gets the amount of shares owned.
     * @return The amount of stocks.
     */
    int getAmount() const { return amount; }

    /**
     * @brief Adds to the current amount of shares.
     *
     * Increases the number of shares and emits amountChanged().
     *
     * @param number Number of shares to add.
     */
    void addAmount(int number);

    /**
     * @brief Removes from the current amount of shares.
     *
     * Decreases the number of shares and emits amountChanged().
     *
     * @param number Number of shares to remove.
     */
    void removeAmount(int number);

signals:
    /**
     * @brief Emitted whenever the amount changes.
     * @param newAmount The updated number of shares.
     */
    void amountChanged(int newAmount);
};

#endif // STOCK_H
