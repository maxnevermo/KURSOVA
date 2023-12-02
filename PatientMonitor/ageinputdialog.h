#ifndef AGEINPUTDIALOG_H
#define AGEINPUTDIALOG_H

//діалогове вікно для вказування віку
//для подальшого пошуку пацієнтів
//із завищеними показниками Артеріального тиску та Пульсу

#include <QDialog>

namespace Ui {
class AgeInputDialog;
}

class AgeInputDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AgeInputDialog(QWidget *parent = nullptr);
    ~AgeInputDialog();

signals:
    void ageSet(const int &age);

private slots:
    void on_checkButton_clicked();

private:
    Ui::AgeInputDialog *ui;
};

#endif // AGEINPUTDIALOG_H
