#ifndef ACCOUNTVIEWMODEL_H
#define ACCOUNTVIEWMODEL_H
#include <QObject>
#include "../classes/Account.class.h"

class AccountViewModel: public QObject
{
    Q_OBJECT
public:
    explicit AccountViewModel(QObject * parent= nullptr);
    void setAccount(Account* account);
    int id() const;
    float balance() const;

    void buy(int stockID, int amount);
    void sell(int stockID, int amount);

signals:
    void balanceChanged();
    void holdingsChanged();
private:
    Account* account;

private slots:
    void accountUpdate(); //not yet implemented
};

#endif // ACCOUNTVIEWMODEL_H
