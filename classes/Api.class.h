#ifndef API_H
#define API_H
#include <QString>
/**
 * @class Api
 * @brief Provides access to external data such as stock prices.
 *
 * The Api class simulates or wraps access to an external API.
 * Currently, it provides a method to retrieve a stock price based on a short name.
 */
class Api{
private:
    //private $price;

public:
    //double getPrice(QString shortName);
    /**
     * @brief Retrieves the price for a given stock symbol.
     * @param shortName The stock symbol (e.g., "AAPL", "GOOGL").
     * @return The price as an integer (e.g., cents or unitless simulation).
     */
    int  getPrice(QString shortName);
};
#endif // API_H
