#include "stockview.h"
#include "ui_stockview.h"

stockview::stockview( QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::stockview)
{
    ui->setupUi(this);
    //this->setSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);

    //QString stringId = QString::number(viewModel->id());
    //QString stringAmount = QString::number(viewModel->amount());
    //ui->label->setText(stringId);
    //ui->label_2->setText(stringAmount);
    setMinimumSize(QSize(40, 90));

   /* connect(viewModel, &StockViewModel::amountChanged, this, [this]() {
        ui->label_2->setText(QString::number(this->viewModel->amount()));
    });*/

}
void stockview::setViewmodel(StockViewModel *viewModel){
   /* if (this->viewModel) {
        disconnect(viewModel, &StockViewModel::amountChanged, this, &stockview::updateAmountDisplay);
    }
    */
    this->viewModel = viewModel;
    QString stringId = QString::number(viewModel->id());
    //QString stringAmount = QString::number(viewModel->amount());
    ui->label->setText(stringId);
    //ui->label_2->setText(stringAmount);
    if (viewModel) {
        connect(this->viewModel, &StockViewModel::amountChanged, this, &stockview::updateAmountDisplay);
        updateAmountDisplay(this->viewModel->amount());
    }
}
/*void stockview::updateView(){
    this->ui->label_2->setText(QString::number(this->viewModel->amount()));

}*/
void stockview::updateAmountDisplay(int newAmount){
    this->ui->label_2->setText(QString::number(newAmount));


}

stockview::~stockview()
{
    delete ui;
}
