#ifndef PRESSURESORTDIALOG_H
#define PRESSURESORTDIALOG_H

#include <QDialog>

namespace Ui {
class pressureSortDialog;
}

class pressureSortDialog : public QDialog
{
    Q_OBJECT

public:
    explicit pressureSortDialog(QWidget *parent = nullptr);
    ~pressureSortDialog();

signals:
    void sortButtonClicked(const QString& comboBox1Text, const QString& comboBox2Text);

private slots:
    void on_sortConfirm_clicked();

private:
    Ui::pressureSortDialog *ui;
};

#endif // PRESSURESORTDIALOG_H
