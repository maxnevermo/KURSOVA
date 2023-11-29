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
    "sentPatients",
    "",
    "std::vector<patientInfo>",
    "patients",
    "onPatientAdded",
    "patientInfo&",
    "patient",
    "handleAgeSet",
    "age",
    "onPatientChanged",
    "patientInfo*",
    "editedPatient",
    "on_scanButton_clicked",
    "on_addButton_clicked",
    "on_bloodPressureSort_clicked",
    "on_bloodTypeGroupButton_clicked",
    "on_rhGroupHrSort_clicked",
    "on_agePulseCheckButton_clicked",
    "on_actionCancel_action_triggered",
    "on_actionExit_triggered",
    "on_writeButton_clicked",
    "on_normPressureCheckButton_clicked",
    "on_donorCheckButton_clicked",
    "showContextMenu",
    "pos",
    "onDeletePatient",
    "onEditPatient",
    "handleSortButtonClicked",
    "comboBox1Text",
    "comboBox2Text",
    "handleSortButtonHR"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSPatientMonitorENDCLASS_t {
    uint offsetsAndSizes[64];
    char stringdata0[15];
    char stringdata1[13];
    char stringdata2[1];
    char stringdata3[25];
    char stringdata4[9];
    char stringdata5[15];
    char stringdata6[13];
    char stringdata7[8];
    char stringdata8[13];
    char stringdata9[4];
    char stringdata10[17];
    char stringdata11[13];
    char stringdata12[14];
    char stringdata13[22];
    char stringdata14[21];
    char stringdata15[29];
    char stringdata16[32];
    char stringdata17[25];
    char stringdata18[31];
    char stringdata19[33];
    char stringdata20[24];
    char stringdata21[23];
    char stringdata22[35];
    char stringdata23[28];
    char stringdata24[16];
    char stringdata25[4];
    char stringdata26[16];
    char stringdata27[14];
    char stringdata28[24];
    char stringdata29[14];
    char stringdata30[14];
    char stringdata31[19];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSPatientMonitorENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSPatientMonitorENDCLASS_t qt_meta_stringdata_CLASSPatientMonitorENDCLASS = {
    {
        QT_MOC_LITERAL(0, 14),  // "PatientMonitor"
        QT_MOC_LITERAL(15, 12),  // "sentPatients"
        QT_MOC_LITERAL(28, 0),  // ""
        QT_MOC_LITERAL(29, 24),  // "std::vector<patientInfo>"
        QT_MOC_LITERAL(54, 8),  // "patients"
        QT_MOC_LITERAL(63, 14),  // "onPatientAdded"
        QT_MOC_LITERAL(78, 12),  // "patientInfo&"
        QT_MOC_LITERAL(91, 7),  // "patient"
        QT_MOC_LITERAL(99, 12),  // "handleAgeSet"
        QT_MOC_LITERAL(112, 3),  // "age"
        QT_MOC_LITERAL(116, 16),  // "onPatientChanged"
        QT_MOC_LITERAL(133, 12),  // "patientInfo*"
        QT_MOC_LITERAL(146, 13),  // "editedPatient"
        QT_MOC_LITERAL(160, 21),  // "on_scanButton_clicked"
        QT_MOC_LITERAL(182, 20),  // "on_addButton_clicked"
        QT_MOC_LITERAL(203, 28),  // "on_bloodPressureSort_clicked"
        QT_MOC_LITERAL(232, 31),  // "on_bloodTypeGroupButton_clicked"
        QT_MOC_LITERAL(264, 24),  // "on_rhGroupHrSort_clicked"
        QT_MOC_LITERAL(289, 30),  // "on_agePulseCheckButton_clicked"
        QT_MOC_LITERAL(320, 32),  // "on_actionCancel_action_triggered"
        QT_MOC_LITERAL(353, 23),  // "on_actionExit_triggered"
        QT_MOC_LITERAL(377, 22),  // "on_writeButton_clicked"
        QT_MOC_LITERAL(400, 34),  // "on_normPressureCheckButton_cl..."
        QT_MOC_LITERAL(435, 27),  // "on_donorCheckButton_clicked"
        QT_MOC_LITERAL(463, 15),  // "showContextMenu"
        QT_MOC_LITERAL(479, 3),  // "pos"
        QT_MOC_LITERAL(483, 15),  // "onDeletePatient"
        QT_MOC_LITERAL(499, 13),  // "onEditPatient"
        QT_MOC_LITERAL(513, 23),  // "handleSortButtonClicked"
        QT_MOC_LITERAL(537, 13),  // "comboBox1Text"
        QT_MOC_LITERAL(551, 13),  // "comboBox2Text"
        QT_MOC_LITERAL(565, 18)   // "handleSortButtonHR"
    },
    "PatientMonitor",
    "sentPatients",
    "",
    "std::vector<patientInfo>",
    "patients",
    "onPatientAdded",
    "patientInfo&",
    "patient",
    "handleAgeSet",
    "age",
    "onPatientChanged",
    "patientInfo*",
    "editedPatient",
    "on_scanButton_clicked",
    "on_addButton_clicked",
    "on_bloodPressureSort_clicked",
    "on_bloodTypeGroupButton_clicked",
    "on_rhGroupHrSort_clicked",
    "on_agePulseCheckButton_clicked",
    "on_actionCancel_action_triggered",
    "on_actionExit_triggered",
    "on_writeButton_clicked",
    "on_normPressureCheckButton_clicked",
    "on_donorCheckButton_clicked",
    "showContextMenu",
    "pos",
    "onDeletePatient",
    "onEditPatient",
    "handleSortButtonClicked",
    "comboBox1Text",
    "comboBox2Text",
    "handleSortButtonHR"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSPatientMonitorENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
      20,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,  134,    2, 0x06,    1 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       5,    1,  137,    2, 0x0a,    3 /* Public */,
       8,    1,  140,    2, 0x0a,    5 /* Public */,
      10,    1,  143,    2, 0x0a,    7 /* Public */,
      13,    0,  146,    2, 0x08,    9 /* Private */,
      14,    0,  147,    2, 0x08,   10 /* Private */,
      15,    0,  148,    2, 0x08,   11 /* Private */,
      16,    0,  149,    2, 0x08,   12 /* Private */,
      17,    0,  150,    2, 0x08,   13 /* Private */,
      18,    0,  151,    2, 0x08,   14 /* Private */,
      19,    0,  152,    2, 0x08,   15 /* Private */,
      20,    0,  153,    2, 0x08,   16 /* Private */,
      21,    0,  154,    2, 0x08,   17 /* Private */,
      22,    0,  155,    2, 0x08,   18 /* Private */,
      23,    0,  156,    2, 0x08,   19 /* Private */,
      24,    1,  157,    2, 0x08,   20 /* Private */,
      26,    0,  160,    2, 0x08,   22 /* Private */,
      27,    0,  161,    2, 0x08,   23 /* Private */,
      28,    2,  162,    2, 0x08,   24 /* Private */,
      31,    1,  167,    2, 0x08,   27 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 6,    7,
    QMetaType::Void, QMetaType::Int,    9,
    QMetaType::Void, 0x80000000 | 11,   12,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QPoint,   25,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,   29,   30,
    QMetaType::Void, QMetaType::QString,   29,

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
        // method 'sentPatients'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const std::vector<patientInfo> &, std::false_type>,
        // method 'onPatientAdded'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<patientInfo &, std::false_type>,
        // method 'handleAgeSet'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const int &, std::false_type>,
        // method 'onPatientChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<patientInfo *, std::false_type>,
        // method 'on_scanButton_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_addButton_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_bloodPressureSort_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_bloodTypeGroupButton_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_rhGroupHrSort_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_agePulseCheckButton_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_actionCancel_action_triggered'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_actionExit_triggered'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_writeButton_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_normPressureCheckButton_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_donorCheckButton_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'showContextMenu'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QPoint &, std::false_type>,
        // method 'onDeletePatient'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onEditPatient'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'handleSortButtonClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'handleSortButtonHR'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>
    >,
    nullptr
} };

void PatientMonitor::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<PatientMonitor *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->sentPatients((*reinterpret_cast< std::add_pointer_t<std::vector<patientInfo>>>(_a[1]))); break;
        case 1: _t->onPatientAdded((*reinterpret_cast< std::add_pointer_t<patientInfo&>>(_a[1]))); break;
        case 2: _t->handleAgeSet((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 3: _t->onPatientChanged((*reinterpret_cast< std::add_pointer_t<patientInfo*>>(_a[1]))); break;
        case 4: _t->on_scanButton_clicked(); break;
        case 5: _t->on_addButton_clicked(); break;
        case 6: _t->on_bloodPressureSort_clicked(); break;
        case 7: _t->on_bloodTypeGroupButton_clicked(); break;
        case 8: _t->on_rhGroupHrSort_clicked(); break;
        case 9: _t->on_agePulseCheckButton_clicked(); break;
        case 10: _t->on_actionCancel_action_triggered(); break;
        case 11: _t->on_actionExit_triggered(); break;
        case 12: _t->on_writeButton_clicked(); break;
        case 13: _t->on_normPressureCheckButton_clicked(); break;
        case 14: _t->on_donorCheckButton_clicked(); break;
        case 15: _t->showContextMenu((*reinterpret_cast< std::add_pointer_t<QPoint>>(_a[1]))); break;
        case 16: _t->onDeletePatient(); break;
        case 17: _t->onEditPatient(); break;
        case 18: _t->handleSortButtonClicked((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2]))); break;
        case 19: _t->handleSortButtonHR((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (PatientMonitor::*)(const std::vector<patientInfo> & );
            if (_t _q_method = &PatientMonitor::sentPatients; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
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
        if (_id < 20)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 20;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 20)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 20;
    }
    return _id;
}

// SIGNAL 0
void PatientMonitor::sentPatients(const std::vector<patientInfo> & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
