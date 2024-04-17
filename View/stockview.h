#ifndef STOCKVIEW_H
#define STOCKVIEW_H
#include "../ViewModel/stockviewmodel.h"
#include <QMainWindow>
#include <qlabel.h>
namespace Ui {
class stockview;
}

class stockview : public QMainWindow
{
    Q_OBJECT

public:
    explicit stockview(QWidget *parent = nullptr);
    ~stockview();
    void setViewmodel(StockViewModel *viewModel);
    StockViewModel * getviewModel(){return viewModel;}
    void updateView(); //will not be used more will use slot
private:
    Ui::stockview *ui;
    StockViewModel *viewModel = nullptr;
private slots:
    void updateAmountDisplay(int newAmount);
};

#endif // STOCKVIEW_H
