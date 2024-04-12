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

private:
    Ui::stockview *ui;
    StockViewModel *viewModel;
};

#endif // STOCKVIEW_H
