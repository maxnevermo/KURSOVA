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

//зчитування віку для для подальшого пошуку пацієнтів
//із завищеними показниками Артеріального тиску та Пульсу
void AgeInputDialog::on_checkButton_clicked()
{
    int checkableAge = ui->ageSpinBox->value();
    emit ageSet(checkableAge);
    close();
}

