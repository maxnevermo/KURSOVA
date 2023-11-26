#include "ageinputdialog.h"
#include "ui_ageinputdialog.h"

AgeInputDialog::AgeInputDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AgeInputDialog)
{
    ui->setupUi(this);
    setWindowTitle("Age checker");
}

AgeInputDialog::~AgeInputDialog()
{
    delete ui;
}

void AgeInputDialog::on_checkButton_clicked()
{
    int checkableAge = ui->ageSpinBox->value();
    emit ageSet(checkableAge);
    close();
}

