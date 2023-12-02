#include "editpatient.h"
#include "ui_editpatient.h"

//реалізація діалогового вікна для зміни даних про пацієнта

EditPatient::EditPatient(QWidget *parent, patientInfo *patient)
    : QDialog(parent),
    ui(new Ui::EditPatient),
    editedPatient(patient)
{
    ui->setupUi(this);

    setWindowTitle("Change patient info");

    connect(ui->changeButton, &QPushButton::clicked, this, &EditPatient::on_changeButton_clicked);

    ui->surnameTextEdit->setText(QString::fromStdString(editedPatient->getSurname()));
    ui->ageSpinBox->setValue(editedPatient->getAge());
    ui->bloodTypeCB->setCurrentText(QString::fromStdString(editedPatient->getBloodType()));
    ui->rhFactorCB->setCurrentText(QString::fromStdString(editedPatient->getRhFactor()));
    ui->upperPressureTextEdit->setText(QString::number(editedPatient->getUpPressure()));
    ui->lowerPressureTextEdit->setText(QString::number(editedPatient->getLowPressure()));
    ui->pulseCB->setValue(editedPatient->getPulseValue());
}

EditPatient::~EditPatient()
{
    delete ui;
}

void EditPatient::on_changeButton_clicked()
{
    //зчитування змінених даних
    QString gotSurname = ui->surnameTextEdit->toPlainText();
    int gotAge = ui->ageSpinBox->value();
    QString gotBloodType = ui->bloodTypeCB->currentText();
    QString gotRhFactor = ui->rhFactorCB->currentText();
    QString gotUpperPressureStr = ui->upperPressureTextEdit->toPlainText();
    QString gotLowerPressureStr = ui->lowerPressureTextEdit->toPlainText();
    int gotPulse = ui->pulseCB->value();

    //обробка виняткових ситуацій
    try
    {
        QRegularExpression englishRegex("^[A-Za-z]+$");
        QRegularExpressionMatch englishMatch = englishRegex.match(gotSurname);

        if (!englishMatch.hasMatch()) {
            throw QString("Invalid name.\nPlease use only english letters.");
        }

        if (gotAge < 0)
        {
            throw QString("Invalid age.\nPlease enter a valid age.");
        }

        if (gotBloodType == "Undefined")
        {
            throw QString("Please select a valid blood type.");
        }

        if (gotRhFactor == "Undefined")
        {
            throw QString("Please select a valid Rh factor.");
        }

        bool upperPressureValid;
        int gotUpperPressure = gotUpperPressureStr.toInt(&upperPressureValid);
        if (!upperPressureValid)
        {
            throw QString("Invalid upper pressure.\nPlease enter a valid number.");
        }

        bool lowerPressureValid;
        int gotLowerPressure = gotLowerPressureStr.toInt(&lowerPressureValid);
        if (!lowerPressureValid)
        {
            throw QString("Invalid lower pressure.\nPlease enter a valid number.");
        }

        if (gotPulse <= 40)
        {
            throw QString("Invalid pulse.\nPlease enter a pulse value\ngreater than 40.");
        }

        if (gotUpperPressure < gotLowerPressure)
        {
            throw QString("Invalid pressure values.\nUpper pressure cannot be less than lower pressure.");
        }

        editedPatient->setSurname(gotSurname.toStdString());
        editedPatient->setAge(gotAge);
        editedPatient->setBloodType(gotBloodType.toStdString());
        editedPatient->setRhFactor(gotRhFactor.toStdString());
        editedPatient->setUpPressure(gotUpperPressure);
        editedPatient->setLowPressure(gotLowerPressure);
        editedPatient->setPulseValue(gotPulse);
        accept();
    } catch (const QString error) {
        editDataError(error);
    }
}

//функція для виведення помилки, якщо введено дані неправильного формату
void EditPatient::editDataError(const QString &errorInputMessage) {
    QMessageBox mb("Edit patient",
                   errorInputMessage,
                   QMessageBox::NoIcon,
                   QMessageBox::Ok | QMessageBox::Default,
                   QMessageBox::NoButton,
                   QMessageBox::NoButton);
    QPixmap exportSuccess("C:\\Users\\maxnevermo\\Downloads\\gui-check-no-svgrepo-com.svg");
    mb.setIconPixmap(exportSuccess);
    mb.setStyleSheet("QMessageBox {"
                     "background-color: #C6CCE8;"
                     "color: #000000;"
                     "font-family: 'Gogh';"
                     "font-weight: 400;"
                     "font-size: 20px"
                     "}");
    mb.exec();
}
