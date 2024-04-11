#ifndef USERVIEW_H
#define USERVIEW_H

#include <QMainWindow>
#include <QVBoxLayout>
#include "accountview.h"

namespace Ui {
class userview;
}

class userview : public QMainWindow
{
    Q_OBJECT

public:
    explicit userview(QWidget *parent = nullptr); //should get userID
    ~userview();
    //void addAccountView(accountview *accountView);
    accountview* addAccountView(int accountId, int balance);
    //AccountGroupBox* addAccountGroup(int accountId, int balance);

private:
    Ui::userview *ui;
    QVector<accountview*> accounts;
signals:
    void amountChanged(int newAmount);

};

#endif // USERVIEW_H
