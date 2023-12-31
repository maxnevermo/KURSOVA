QT       += core gui
QT += printsupport


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    addpatientdialog.cpp \
    ageinputdialog.cpp \
    donorstable.cpp \
    editpatient.cpp \
    healthypatients.cpp \
    heartratesortdialog.cpp \
    main.cpp \
    patientinfo.cpp \
    patientmonitor.cpp \
    pressuresortdialog.cpp

HEADERS += \
    addpatientdialog.h \
    ageinputdialog.h \
    donorstable.h \
    editpatient.h \
    healthypatients.h \
    heartratesortdialog.h \
    patientinfo.h \
    patientmonitor.h \
    pressuresortdialog.h

FORMS += \
    addpatientdialog.ui \
    ageinputdialog.ui \
    donorstable.ui \
    editpatient.ui \
    healthypatients.ui \
    heartratesortdialog.ui \
    patientmonitor.ui \
    pressuresortdialog.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
