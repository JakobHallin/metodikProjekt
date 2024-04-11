#ifndef ACCOUNTVIEW_H
#define ACCOUNTVIEW_H

#include <QMainWindow>
#include <QWidget>
#include <QMainWindow>
#include <QVBoxLayout>
#include "stockview.h"

//#include "ui_accountview.h"
namespace Ui {
class accountview;
}

class accountview : public QMainWindow
{
    Q_OBJECT

public:
    explicit accountview(int accountId, int balance, QWidget *parent = nullptr);
    ~accountview();
    stockview* addStock(int id, int amount);


private:
    Ui::accountview *ui;
    QVector<stockview*> stocks;
};

#endif // ACCOUNTVIEW_H
