#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <vector>
#include "Sql.class.h"
#include "Api.class.h"
#include <QSqlRecord>
#include "Stock.class.h"
#include <QObject>

/**
 * @class Account
 * @brief Represents a user's trading account, including balance and stock holdings.
 *
 * The Account class allows buying and selling stocks, updating the account balance,
 * and managing the list of Stock objects held by the account.
 */
class Account : public QObject {
    Q_OBJECT

private:
    int id;                     ///< Unique identifier for this account.
    float balance;              ///< Current monetary balance of the account.
    QVector<Stock*> holding;    ///< List of Stock pointers representing holdings.

    /**
     * @brief Updates the holding amount for an existing stock.
     * @param stockID     ID of the stock to update.
     * @param stockAmount New total number of shares for that stock.
     */
    void updateStockHolding(int stockID, int stockAmount); // will remove

    /**
     * @brief Inserts a new stock into the holdings when buying for the first time.
     * @param stockId ID of the stock to insert.
     * @param amount  Number of shares to add.
     */
    void insertNewStock(int stockId, int amount);

    /**
     * @brief Changes the amount of an existing holding.
     * @param index  Index in the holding QVector.
     * @param amount Number of shares to set.
     */
    void changeHolding(int index, int amount); // will remove

    /**
     * @brief Adds to the quantity of an existing stock in holdings.
     * @param index  Index in the holding QVector.
     * @param amount Number of shares to add.
     */
    void addtoholding(int index, int amount);

    /**
     * @brief Removes from the quantity of an existing stock in holdings.
     * @param index  Index in the holding QVector.
     * @param amount Number of shares to remove.
     */
    void removetoholding(int index, int amount);

public:
    /**
     * @brief Constructs an Account object.
     *
     * @param id      Unique account identifier.
     * @param balance Initial balance for the account.
     * @param parent  Optional parent QObject.
     */
    Account(int id, float balance, QObject *parent = nullptr);

    /**
     * @brief Destructor to clean up allocated Stock objects.
     */
    ~Account();

    /**
     * @brief Gets the number of different stocks held in this account.
     * @return Size of the holding QVector.
     */
    int getSize();

    /**
     * @brief Retrieves the stock ID at a given index in holdings.
     * @param index Index in the holding QVector.
     * @return The stock ID.
     */
    int getStockID(int index);

    /**
     * @brief Retrieves the number of shares for a stock at a given index.
     * @param index Index in the holding QVector.
     * @return Number of shares held.
     */
    int getStockAmount(int index);

    /**
     * @brief Sets the account balance to a new value.
     * @param n New balance value.
     */
    void setBalance(float n);

    /**
     * @brief Retrieves the unique account ID.
     * @return Account ID.
     */
    int getID();

    /**
     * @brief Retrieves the current balance.
     * @return Account balance.
     */
    float getBalance();

    /**
     * @brief Retrieves a copy of the list of Stock pointers held.
     * @return QVector of Stock* representing current holdings.
     */
    QVector<Stock*> getHolding();

    /**
     * @brief Adds a Stock object to the holdings.
     *
     * If the stock already exists, updates its amount; otherwise inserts new.
     *
     * @param stock Pointer to the Stock object to add.
     */
    void addStock(Stock* stock);

    /**
     * @brief Increases the balance by a given amount.
     * @param totalprice Amount to add to the balance (e.g., from selling stock).
     */
    void addBalance(float totalprice);

    /**
     * @brief Decreases the balance by a given amount.
     * @param totalprice Amount to subtract from the balance (e.g., when buying stock).
     */
    void removeFromBalance(float totalprice);

    /**
     * @brief Retrieves the current price for a given stock (via API).
     * @param stockID ID of the stock to price.
     * @return The current stock price as a float.
     */
    float getPrice(int stockID);

    /**
     * @brief Buys a specified number of shares of a stock.
     *
     * Queries current price, subtracts cost from balance, and updates holdings.
     *
     * @param StockId ID of the stock to purchase.
     * @param amount  Number of shares to buy.
     */
    void buyStock(int StockId, int amount);

    /**
     * @brief Sells a specified number of shares of a stock.
     *
     * Queries current price, adds proceeds to balance, and updates holdings.
     *
     * @param StockID ID of the stock to sell.
     * @param amount  Number of shares to sell.
     */
    void sellStock(int StockID, int amount);

signals:
    /**
     * @brief Emitted whenever the balance changes.
     * @param value The updated balance.
     */
    void balanceChanged(float value);
};

#endif // ACCOUNT_H
