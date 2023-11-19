/****************************************************************************
** Meta object code from reading C++ file 'patientmonitor.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.6.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../PatientMonitor/patientmonitor.h"
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'patientmonitor.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_CLASSPatientMonitorENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSPatientMonitorENDCLASS = QtMocHelpers::stringData(
    "PatientMonitor",
    "onPatientAdded",
    "",
    "patientInfo",
    "patient",
    "on_scanButton_clicked",
    "on_addButton_clicked",
    "on_bloodPressureSort_clicked",
    "on_bloodTypeGroupButton_clicked"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSPatientMonitorENDCLASS_t {
    uint offsetsAndSizes[18];
    char stringdata0[15];
    char stringdata1[15];
    char stringdata2[1];
    char stringdata3[12];
    char stringdata4[8];
    char stringdata5[22];
    char stringdata6[21];
    char stringdata7[29];
    char stringdata8[32];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSPatientMonitorENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSPatientMonitorENDCLASS_t qt_meta_stringdata_CLASSPatientMonitorENDCLASS = {
    {
        QT_MOC_LITERAL(0, 14),  // "PatientMonitor"
        QT_MOC_LITERAL(15, 14),  // "onPatientAdded"
        QT_MOC_LITERAL(30, 0),  // ""
        QT_MOC_LITERAL(31, 11),  // "patientInfo"
        QT_MOC_LITERAL(43, 7),  // "patient"
        QT_MOC_LITERAL(51, 21),  // "on_scanButton_clicked"
        QT_MOC_LITERAL(73, 20),  // "on_addButton_clicked"
        QT_MOC_LITERAL(94, 28),  // "on_bloodPressureSort_clicked"
        QT_MOC_LITERAL(123, 31)   // "on_bloodTypeGroupButton_clicked"
    },
    "PatientMonitor",
    "onPatientAdded",
    "",
    "patientInfo",
    "patient",
    "on_scanButton_clicked",
    "on_addButton_clicked",
    "on_bloodPressureSort_clicked",
    "on_bloodTypeGroupButton_clicked"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSPatientMonitorENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   44,    2, 0x0a,    1 /* Public */,
       5,    0,   47,    2, 0x08,    3 /* Private */,
       6,    0,   48,    2, 0x08,    4 /* Private */,
       7,    0,   49,    2, 0x08,    5 /* Private */,
       8,    0,   50,    2, 0x08,    6 /* Private */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject PatientMonitor::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_CLASSPatientMonitorENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSPatientMonitorENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSPatientMonitorENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<PatientMonitor, std::true_type>,
        // method 'onPatientAdded'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const patientInfo &, std::false_type>,
        // method 'on_scanButton_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_addButton_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_bloodPressureSort_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_bloodTypeGroupButton_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void PatientMonitor::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<PatientMonitor *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->onPatientAdded((*reinterpret_cast< std::add_pointer_t<patientInfo>>(_a[1]))); break;
        case 1: _t->on_scanButton_clicked(); break;
        case 2: _t->on_addButton_clicked(); break;
        case 3: _t->on_bloodPressureSort_clicked(); break;
        case 4: _t->on_bloodTypeGroupButton_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject *PatientMonitor::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *PatientMonitor::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSPatientMonitorENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int PatientMonitor::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 5;
    }
    return _id;
}
QT_WARNING_POP
