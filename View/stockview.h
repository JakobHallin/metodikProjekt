#ifndef STOCKVIEW_H
#define STOCKVIEW_H

#include <QMainWindow>
#include <qlabel.h>
namespace Ui {
class stockview;
}

class stockview : public QMainWindow
{
    Q_OBJECT

public:
    explicit stockview(int id, int amount, QWidget *parent = nullptr);
    ~stockview();

private:
    Ui::stockview *ui;
};

#endif // STOCKVIEW_H
