#include "pressuresortdialog.h"
#include "ui_pressuresortdialog.h"

pressureSortDialog::pressureSortDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::pressureSortDialog)
{
    ui->setupUi(this);

    setWindowTitle("Pressure sort dialog");
}

pressureSortDialog::~pressureSortDialog()
{
    delete ui;
}

void pressureSortDialog::on_sortConfirm_clicked()
{
    QString comboBox1Text = ui->pressureChoice->currentText();
    QString comboBox2Text = ui->orderChoice->currentText();

    emit sortButtonClicked(comboBox1Text, comboBox2Text);
}

