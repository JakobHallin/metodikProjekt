#include "stockview.h"
#include "ui_stockview.h"

stockview::stockview(int id, int amount, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::stockview)
{
    ui->setupUi(this);
    QString stringId = QString::number(id);
    QString stringAmount = QString::number(amount);
    ui->label->setText(stringId);
    ui->label_2->setText(stringAmount);
    setMinimumSize(QSize(40, 90));

}

stockview::~stockview()
{
    delete ui;
}
