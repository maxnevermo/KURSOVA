#include "heartratesortdialog.h"
#include "ui_heartratesortdialog.h"

//реалізація діалогового вікна для вибору порядку сортування за Пульсом

heartRateSortDialog::heartRateSortDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::heartRateSortDialog)
{
    ui->setupUi(this);
    setWindowTitle("Heartrate sort dialog");
}

heartRateSortDialog::~heartRateSortDialog()
{
    delete ui;
}

void heartRateSortDialog::on_sortConfirm_clicked()
{
    QString orderToSort = ui->orderChoice->currentText();

    emit sortButtonClicked(orderToSort);
}

