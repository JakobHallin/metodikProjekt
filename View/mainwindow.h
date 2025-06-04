#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "userview.h"
#include "../classes/Sql.class.h"
#include <memory>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

/**
 * @class MainWindow
 * @brief The main application window responsible for user login and application entry point.
 *
 * This class acts as the front controller for the application.
 * It typically displays login UI and handles the transition to the @ref userview upon successful login.
 */
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    /**
     * @brief Constructs the main application window.
     * @param parent Optional parent widget.
     */
    explicit MainWindow(QWidget *parent = nullptr);

    /**
     * @brief Destructor for MainWindow.
     */
    ~MainWindow();

private slots:
    /**
     * @brief Slot triggered when the login button is pressed.
     *
     * Responsible for validating credentials and showing the main user interface if login succeeds.
     */
    void pushLoginButton();

private:
    Ui::MainWindow *ui; /**< Pointer to the generated UI components from Qt Designer. */
};

#endif // MAINWINDOW_H
