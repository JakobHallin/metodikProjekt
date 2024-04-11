#include "stockview.h"
#include "ui_stockview.h"

stockview::stockview(StockViewModel *viewModel, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::stockview),
    viewModel(viewModel)
{
    ui->setupUi(this);
    QString stringId = QString::number(viewModel->id());
    QString stringAmount = QString::number(viewModel->amount());
    ui->label->setText(stringId);
    ui->label_2->setText(stringAmount);
    setMinimumSize(QSize(40, 90));
    connect(viewModel, &StockViewModel::amountChanged, this, [this, viewModel]() {
        ui->label_2->setText(QString::number(viewModel->amount()));
    });

}

stockview::~stockview()
{
    delete ui;
}
