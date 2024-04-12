#include "stockview.h"
#include "ui_stockview.h"

stockview::stockview( QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::stockview)
{
    ui->setupUi(this);
    //QString stringId = QString::number(viewModel->id());
    //QString stringAmount = QString::number(viewModel->amount());
    //ui->label->setText(stringId);
    //ui->label_2->setText(stringAmount);
    setMinimumSize(QSize(40, 90));

    /*connect(viewModel, &StockViewModel::amountChanged, this, [this]() {
        ui->label_2->setText(QString::number(this->viewModel->amount()));
    })*/

}
void stockview::setViewmodel(StockViewModel *viewModel){
    this->viewModel = viewModel;
    /*QString stringId = QString::number(viewModel->id());
    QString stringAmount = QString::number(viewModel->amount());
    ui->label->setText(stringId);
    ui->label_2->setText(stringAmount);*/
}


stockview::~stockview()
{
    delete ui;
}
