#ifndef USER_H
#define USER_H

#include <vector>
#include <QObject>
#include "Sql.class.h"
#include "Account.class.h"

/**
 * @class User
 * @brief Manages a collection of accounts and stock operations for a user.
 *
 * The User class handles multiple Account instances, identified by a unique userID.
 * It provides functionality for buying/selling stocks across accounts, checking balances,
 * and verifying if a particular stock exists.
 */
class User : public QObject {
    Q_OBJECT

private:
    QVector<Account*> Accounts;  ///< List of accounts owned by the user.
    QString userID;              ///< Unique identifier for the user.

public:
    /**
     * @brief Constructs a User object with the specified user ID.
     * @param userID Unique identifier for the user.
     */
    User(QString userID);

    /**
     * @brief Destructor to clean up the User object and associated accounts.
     */
    ~User();

    /**
     * @brief Retrieves the user ID.
     * @return The user ID as a QString.
     */
    QString getUserID() { return this->userID; }

    /**
     * @brief Gets the number of accounts the user owns.
     * @return The number of accounts.
     */
    int getSize();

    /**
     * @brief Retrieves the number of stocks in a specified account.
     * @param AccountIndex Index of the account in the list.
     * @return The number of stocks in the account.
     */
    int getAmountStocks(int AccountIndex);

    /**
     * @brief Gets the ID of a stock in a user's account.
     * @param AccountIndex Index of the account.
     * @param stockIndex Index of the stock within the account.
     * @return The stock ID.
     */
    int getAccountsStockID(int AccountIndex, int stockIndex);

    /**
     * @brief Gets the amount of a particular stock in a user's account.
     * @param AccountIndex Index of the account.
     * @param stockIndex Index of the stock within the account.
     * @return The amount of the stock.
     */
    int getAccountsStockAmount(int AccountIndex, int stockIndex);

    /**
     * @brief Gets the ID of a user's account.
     * @param index Index of the account in the list.
     * @return The account ID.
     */
    int getAccountID(int index);

    /**
     * @brief Retrieves the balance of a user's account.
     * @param index Index of the account in the list.
     * @return The account balance.
     */
    float getBalance(int index);

    /**
     * @brief Buys a specified amount of a stock for a given account.
     *
     * Deducts the necessary funds from the account balance and updates holdings.
     *
     * @param AccountIndex Index of the account.
     * @param StockID      ID of the stock.
     * @param amount       Number of stock units to buy.
     */
    void buyFromAccountStockAmount(int AccountIndex, int StockID, int amount);

    /**
     * @brief Sells a specified amount of a stock from a given account.
     *
     * Adds the sale proceeds to the account balance and updates holdings.
     *
     * @param AccountIndex Index of the account.
     * @param StockID      ID of the stock.
     * @param amount       Number of stock units to sell.
     */
    void sellFromAccountStockAmount(int AccountIndex, int StockID, int amount);

    /**
     * @brief Adds a new account to the user.
     * @param Add Pointer to the Account object to add.
     */
    void addAccount(Account* Add);

    /**
     * @brief Retrieves all accounts associated with the user.
     * @return A QVector containing pointers to Account objects.
     */
    QVector<Account*> getAccounts();

    /**
     * @brief Changes the balance of a specific account.
     * @param index  Index of the account.
     * @param amount Amount to add (or subtract if negative).
     */
    void changeBalance(int index, float amount);

    /**
     * @brief Checks if a stock exists across the user's accounts.
     * @param id The stock ID to check.
     * @return true if the stock exists, false otherwise.
     */
    bool stockExist(int id);
};

#endif // USER_H
