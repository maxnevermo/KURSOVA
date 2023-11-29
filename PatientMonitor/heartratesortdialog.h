#ifndef HEARTRATESORTDIALOG_H
#define HEARTRATESORTDIALOG_H

#include <QDialog>

namespace Ui {
class heartRateSortDialog;
}

class heartRateSortDialog : public QDialog
{
    Q_OBJECT

public:
    explicit heartRateSortDialog(QWidget *parent = nullptr);
    ~heartRateSortDialog();

signals:
    void sortButtonClicked(const QString& comboBox1Text);

private slots:
    void on_sortConfirm_clicked();

private:
    Ui::heartRateSortDialog *ui;
};

#endif // HEARTRATESORTDIALOG_H
