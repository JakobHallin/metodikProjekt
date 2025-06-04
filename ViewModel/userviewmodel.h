#ifndef USERVIEWMODEL_H
#define USERVIEWMODEL_H

#include <QObject>
#include "../classes/User.class.h"
#include "../ViewModel/accountviewmodel.h"

/**
 * @class UserViewModel
 * @brief ViewModel class that connects the User model to the View interface.
 *
 * Provides access to user data and user-related account ViewModels.
 * It serves as an intermediary between the User model and the view layer in an MVVM architecture.
 */
class UserViewModel : public QObject
{
    Q_OBJECT

public:
    /**
     * @brief Constructs a UserViewModel object.
     *
     * Initializes with no associated User. Call setUser() to associate a User model.
     *
     * @param parent Optional parent QObject pointer.
     */
    UserViewModel(QObject * parent = nullptr);

    /**
     * @brief Destructor for UserViewModel.
     *
     * Cleans up any allocated AccountViewModel objects.
     */
    ~UserViewModel();

    /**
     * @brief Associates a User model with this ViewModel.
     *
     * Populates accountViewModels by creating an AccountViewModel for each of the User’s accounts.
     *
     * @param user Pointer to a User object whose data will be exposed.
     */
    void setUser(User* user);

    /**
     * @brief Gets the ID of the associated User.
     * @return User ID as a QString.
     */
    QString getUserID() { return user->getUserID(); }

    /**
     * @brief Generates AccountViewModel instances from a given User's accounts.
     *
     * Clears any existing AccountViewModels and creates new ones based on the User model.
     *
     * @param user Pointer to a User object whose accounts will be used.
     */
    void addAccountViewModel(User * user);

    /**
     * @brief Retrieves the list of AccountViewModel instances.
     * @return A QVector of pointers to AccountViewModel.
     */
    QVector<AccountViewModel*> getAccountViewModel() { return this->accountViewModels; }

private:
    User* user;                                   /**< Underlying User model wrapped by this ViewModel */
    QVector<AccountViewModel*> accountViewModels; /**< Collection of AccountViewModel instances for each account */
    // senare kanske implementera byte
};

#endif // USERVIEWMODEL_H
