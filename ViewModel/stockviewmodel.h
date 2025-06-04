#ifndef STOCKVIEWMODEL_H
#define STOCKVIEWMODEL_H

#include <QObject>
#include "../classes/Stock.class.h"

/**
 * @class StockViewModel
 * @brief ViewModel class that wraps a Stock object for interaction with the UI.
 *
 * Provides observable access to the stock’s ID and amount, forwarding model changes to the view.
 */
class StockViewModel : public QObject {
    Q_OBJECT

public:
    /**
     * @brief Constructs a StockViewModel.
     * @param parent Optional parent QObject pointer.
     */
    explicit StockViewModel(QObject *parent = nullptr);

    /**
     * @brief Associates a Stock model with this ViewModel.
     *
     * Connects the model’s amountChanged signal to this view model’s stockUpdate slot.
     *
     * @param stock Pointer to the Stock model.
     */
    void setStock(Stock* stock);

    /**
     * @brief Retrieves the stock’s unique ID.
     * @return Stock ID (int).
     */
    int id() const;

    /**
     * @brief Retrieves the current amount of shares for this stock.
     * @return Number of shares (int).
     */
    int amount() const;

signals:
    /**
     * @brief Emitted whenever the stock amount changes.
     * @param amount Updated number of shares.
     */
    void amountChanged(int amount);

private slots:
    /**
     * @brief Slot called when the underlying Stock model’s amount changes.
     *
     * Emits this view model’s amountChanged signal.
     *
     * @param newAmount Updated amount from the model.
     */
    void stockUpdate(int newAmount);

private:
    Stock* stock; ///< Underlying Stock model.
};

#endif // STOCKVIEWMODEL_H
