/****************************************************************************
** Meta object code from reading C++ file 'healthypatients.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.6.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../PatientMonitor/healthypatients.h"
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'healthypatients.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.6.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASShealthyPatientsENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASShealthyPatientsENDCLASS = QtMocHelpers::stringData(
    "healthyPatients",
    "receivePatientList",
    "",
    "std::vector<patientInfo>",
    "patients",
    "on_actionWrite_to_file_triggered"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASShealthyPatientsENDCLASS_t {
    uint offsetsAndSizes[12];
    char stringdata0[16];
    char stringdata1[19];
    char stringdata2[1];
    char stringdata3[25];
    char stringdata4[9];
    char stringdata5[33];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASShealthyPatientsENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASShealthyPatientsENDCLASS_t qt_meta_stringdata_CLASShealthyPatientsENDCLASS = {
    {
        QT_MOC_LITERAL(0, 15),  // "healthyPatients"
        QT_MOC_LITERAL(16, 18),  // "receivePatientList"
        QT_MOC_LITERAL(35, 0),  // ""
        QT_MOC_LITERAL(36, 24),  // "std::vector<patientInfo>"
        QT_MOC_LITERAL(61, 8),  // "patients"
        QT_MOC_LITERAL(70, 32)   // "on_actionWrite_to_file_triggered"
    },
    "healthyPatients",
    "receivePatientList",
    "",
    "std::vector<patientInfo>",
    "patients",
    "on_actionWrite_to_file_triggered"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASShealthyPatientsENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   26,    2, 0x0a,    1 /* Public */,
       5,    0,   29,    2, 0x08,    3 /* Private */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject healthyPatients::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_CLASShealthyPatientsENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASShealthyPatientsENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASShealthyPatientsENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<healthyPatients, std::true_type>,
        // method 'receivePatientList'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const std::vector<patientInfo> &, std::false_type>,
        // method 'on_actionWrite_to_file_triggered'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void healthyPatients::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<healthyPatients *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->receivePatientList((*reinterpret_cast< std::add_pointer_t<std::vector<patientInfo>>>(_a[1]))); break;
        case 1: _t->on_actionWrite_to_file_triggered(); break;
        default: ;
        }
    }
}

const QMetaObject *healthyPatients::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *healthyPatients::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASShealthyPatientsENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int healthyPatients::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 2;
    }
    return _id;
}
QT_WARNING_POP
