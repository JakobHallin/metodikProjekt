#ifndef USERVIEW_H
#define USERVIEW_H

#include <QMainWindow>
#include <QVBoxLayout>
#include "accountview.h"
#include "../ViewModel/userviewmodel.h"
#include <QScrollArea>
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

    void setViewmodel(UserViewModel* viewmodel);

    //accountview* addAccountView(int accountId, int balance);
    //AccountGroupBox* addAccountGroup(int accountId, int balance);
    void makeAccountView();
    void generateAccountView();
private:
    Ui::userview *ui;
    QVector<accountview*> accounts;
    UserViewModel* viewModel;
signals:
    void amountChanged(int newAmount);

};

#endif // USERVIEW_H
