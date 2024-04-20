#ifndef USERVIEWMODEL_H
#define USERVIEWMODEL_H
#include <QObject>
#include "../classes/User.class.h"
#include "../ViewModel/accountviewmodel.h"
class UserViewModel: public QObject
{
     Q_OBJECT
public:
    UserViewModel(QObject * parent= nullptr);
    ~UserViewModel();
    void setUser(User* user);
    QString getUserID(){ return user->getUserID();}
    void addAccountViewModel(User * user);
    QVector<AccountViewModel*> getAccountViewModel(){return this->accountViewModels;}



private:
    User* user;
    QVector<AccountViewModel*> accountViewModels;
//senare kanske implementera byte
};

#endif // USERVIEWMODEL_H
