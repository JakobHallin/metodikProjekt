#ifndef ACCOUNTVIEWMODEL_H
#define ACCOUNTVIEWMODEL_H

#include <QObject>
#include "../classes/Account.class.h"
#include "../ViewModel/stockviewmodel.h"

/**
 * @class AccountViewModel
 * @brief ViewModel class that wraps an Account object for interaction with the UI.
 *
 * Provides observable access to the account’s ID, balance, and its stocks’ view models.
 * Facilitates buy/sell operations by forwarding to the Account model.
 */
class AccountViewModel : public QObject
{
    Q_OBJECT

public:
    /**
     * @brief Constructs an AccountViewModel.
     *
     * Initializes an empty AccountViewModel with no associated Account.
     *
     * @param parent Optional parent QObject pointer.
     */
    explicit AccountViewModel(QObject * parent = nullptr);

    /**
     * @brief Associates an Account model with this ViewModel.
     *
     * Connects the Account’s balanceChanged signal to this ViewModel’s updateBalance slot.
     * Populates stockViewModels from the Account’s holdings.
     *
     * @param account Pointer to the Account model to wrap.
     */
    void setAccount(Account* account);

    /**
     * @brief Retrieves the account’s unique ID.
     * @return Account ID (int).
     */
    int id() const;

    /**
     * @brief Retrieves the current account balance.
     * @return Balance as a float.
     */
    float balance() const;

    /**
     * @brief Gets the underlying Account model.
     * @return Pointer to the associated Account.
     */
    Account* getAccount();

    /**
     * @brief Retrieves the list of StockViewModel instances for each stock in the account.
     * @return QVector of pointers to StockViewModel.
     */
    QVector<StockViewModel*> getstockViewModels();

    /**
     * @brief Buys a specified number of shares of a stock within this account.
     *
     * Delegates the buy operation to the underlying Account model.
     * The Account model adjusts balance and holdings accordingly.
     *
     * @param stockID ID of the stock to purchase.
     * @param amount  Number of shares to buy.
     */
    void buy(int stockID, int amount);

    /**
     * @brief Sells a specified number of shares of a stock within this account.
     *
     * Delegates the sell operation to the underlying Account model.
     * The Account model adjusts balance and holdings accordingly.
     *
     * @param stockID ID of the stock to sell.
     * @param amount  Number of shares to sell.
     */
    void sell(int stockID, int amount);

    /**
     * @brief Populates the list of StockViewModel objects from the Account’s holdings.
     *
     * Creates a StockViewModel for each Stock in the Account and connects their signals.
     *
     * @param account Pointer to the Account model whose holdings are used.
     */
    void addStockViewModel(Account * account);

    /**
     * @brief Destructor for AccountViewModel.
     *
     * Cleans up any allocated StockViewModel objects.
     */
    ~AccountViewModel();

signals:
    /**
     * @brief Emitted whenever the account balance changes.
     *
     * Connected to UI elements to update displayed balance.
     *
     * @param value New balance value.
     */
    void balanceChanged(float value);

private:
    Account* account;                         /**< Underlying Account model wrapped by this ViewModel */
    QVector<StockViewModel*> stockViewModels; /**< Collection of StockViewModel instances for each stock */

private slots:
    /**
     * @brief Slot called when the underlying Account model’s balance changes.
     *
     * Emits this ViewModel’s balanceChanged signal to notify the UI.
     *
     * @param value Updated balance from the Account model.
     */
    void updateBalance(float value);
};

#endif // ACCOUNTVIEWMODEL_H
