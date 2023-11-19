#include "addpatientdialog.h"
#include "ui_addpatientdialog.h"

addPatientDialog::addPatientDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addPatientDialog)
{
    ui->setupUi(this);
    setWindowTitle("Add new patient");
    QStringList bloodTypeList = {"Undefined", "I", "II", "III", "IV"};
    ui->bloodTypeCB->addItems(bloodTypeList);

    QStringList rhFactorList = {"Undefined", "+", "-"};
    ui->rhFactorCB->addItems(rhFactorList);


    QGraphicsDropShadowEffect *shadowSurnameInput = new QGraphicsDropShadowEffect();
    shadowSurnameInput->setBlurRadius(15);
    shadowSurnameInput->setXOffset(0);
    shadowSurnameInput->setColor(QColor(0, 0, 0, 30));

    QGraphicsDropShadowEffect *shadowAgeInput = new QGraphicsDropShadowEffect();
    shadowAgeInput->setBlurRadius(15);
    shadowAgeInput->setXOffset(0);
    shadowAgeInput->setColor(QColor(0, 0, 0, 30));

    QGraphicsDropShadowEffect *shadowBloodTypeInput = new QGraphicsDropShadowEffect();
    shadowBloodTypeInput->setBlurRadius(15);
    shadowBloodTypeInput->setXOffset(0);
    shadowBloodTypeInput->setColor(QColor(0, 0, 0, 30));

    QGraphicsDropShadowEffect *shadowRhFactorInput = new QGraphicsDropShadowEffect();
    shadowRhFactorInput->setBlurRadius(15);
    shadowRhFactorInput->setXOffset(0);
    shadowRhFactorInput->setColor(QColor(0, 0, 0, 30));

    QGraphicsDropShadowEffect *shadowUpperPresInput = new QGraphicsDropShadowEffect();
    shadowUpperPresInput->setBlurRadius(15);
    shadowUpperPresInput->setXOffset(0);
    shadowUpperPresInput->setColor(QColor(0, 0, 0, 30));

    QGraphicsDropShadowEffect *shadowLowerPresInput = new QGraphicsDropShadowEffect();
    shadowLowerPresInput->setBlurRadius(15);
    shadowLowerPresInput->setXOffset(0);
    shadowLowerPresInput->setColor(QColor(0, 0, 0, 30));

    QGraphicsDropShadowEffect *shadowPulseInput = new QGraphicsDropShadowEffect();
    shadowPulseInput->setBlurRadius(15);
    shadowPulseInput->setXOffset(0);
    shadowPulseInput->setColor(QColor(0, 0, 0, 30));

    QGraphicsDropShadowEffect *shadowAddButton = new QGraphicsDropShadowEffect();
    shadowAddButton->setBlurRadius(15);
    shadowAddButton->setXOffset(0);
    shadowAddButton->setColor(QColor(0, 0, 0, 30));

    ui->surnameTextEdit->setGraphicsEffect(shadowSurnameInput);
    ui->ageSpinBox->setGraphicsEffect(shadowAgeInput);
    ui->bloodTypeCB->setGraphicsEffect(shadowBloodTypeInput);
    ui->rhFactorCB->setGraphicsEffect(shadowRhFactorInput);
    ui->upperPressureTextEdit->setGraphicsEffect(shadowUpperPresInput);
    ui->lowerPressureTextEdit->setGraphicsEffect(shadowLowerPresInput);
    ui->pulseCB->setGraphicsEffect(shadowPulseInput);
    ui->addButton->setGraphicsEffect(shadowAddButton);
}

void addPatientDialog::addDataError(const QString &errorMessage) {
    QMessageBox mb("Add new patient",
                   errorMessage,
                   QMessageBox::NoIcon,
                   QMessageBox::Yes | QMessageBox::Default,
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

addPatientDialog::~addPatientDialog()
{
    delete ui;
}

void addPatientDialog::on_addButton_clicked()
{
    QString gotName = ui->surnameTextEdit->toPlainText();
    int gotAge = ui->ageSpinBox->value();
    QString gotBloodType = ui->bloodTypeCB->currentText();
    QString gotRhFactor = ui->rhFactorCB->currentText();
    QString gotUpperPressureStr = ui->upperPressureTextEdit->toPlainText();
    QString gotLowerPressureStr = ui->lowerPressureTextEdit->toPlainText();
    int gotPulse = ui->pulseCB->value();

    try
    {
        QRegularExpression ukrainianRegex("^[А-ЩЬЮЯҐЄIІЇа-щьюяґєiії]+$");
        QRegularExpressionMatch ukrainianMatch = ukrainianRegex.match(gotName);
        if (!ukrainianMatch.hasMatch())
        {
            throw QString("Invalid surname.\nPlease use only Ukrainian letters.");
        }

        if (gotAge <= 0)
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

        if (gotPulse <= 0)
        {
            throw QString("Invalid pulse.\nPlease enter a pulse value\ngreater than 0.");
        }

        if (gotUpperPressure < gotLowerPressure)
        {
            throw QString("Invalid pressure values.\nUpper pressure cannot be less than lower pressure.");
        }

        patientInfo newPatient(gotName.toStdString(), gotAge, gotBloodType.toStdString(),
                               gotRhFactor.toStdString(), gotUpperPressure, gotLowerPressure, gotPulse);
        emit patientAdded(newPatient);
    }
    catch (const QString &errorMessage)
    {
       addDataError(errorMessage);
    }
}
