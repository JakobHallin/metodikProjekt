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
    explicit stockview(StockViewModel *viewModel, QWidget *parent = nullptr);
    ~stockview();

private:
    Ui::stockview *ui;
    StockViewModel *viewModel;
};

#endif // STOCKVIEW_H
