#ifndef ACCOUNTVIEWMODEL_H
#define ACCOUNTVIEWMODEL_H
#include <QObject>
#include "../classes/Account.class.h"
#include "../ViewModel/stockviewmodel.h"
class AccountViewModel: public QObject
{
    Q_OBJECT
public:
    explicit AccountViewModel(QObject * parent= nullptr);
    void setAccount(Account* account);
    int id() const;
    float balance() const;
    Account* getAccount(); //will not be used
    QVector<StockViewModel*> getstockViewModels();

    void buy(int stockID, int amount);
    void sell(int stockID, int amount);
    void addStockViewModel(Account * account);//I already have account



signals: //from model
    void balanceChanged();
    void holdingsChanged();
private:
    Account* account;
    QVector<StockViewModel*> stockViewModels;


private slots: //from view
    void accountUpdate(); //not yet implemented
};

#endif // ACCOUNTVIEWMODEL_H
