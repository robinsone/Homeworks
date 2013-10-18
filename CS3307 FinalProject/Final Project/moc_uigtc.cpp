/****************************************************************************
** Meta object code from reading C++ file 'uigtc.h'
**
** Created: Tue Mar 29 05:15:57 2011
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../Group10AMS/uigtc.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'uigtc.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_uigtc[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
       7,    6,    6,    6, 0x08,
      41,   35,    6,    6, 0x08,
      85,   35,    6,    6, 0x08,
     129,   35,    6,    6, 0x08,
     173,   35,    6,    6, 0x08,
     218,   35,    6,    6, 0x08,
     263,    6,    6,    6, 0x08,
     292,    6,    6,    6, 0x08,
     327,  321,    6,    6, 0x08,
     373,    6,    6,    6, 0x08,
     393,    6,    6,    6, 0x08,
     422,  420,    6,    6, 0x08,
     437,    6,    6,    6, 0x08,
     454,  452,  447,    6, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_uigtc[] = {
    "uigtc\0\0on_btn_unallocate_clicked()\0"
    "index\0on_comboBox_gateUn_currentIndexChanged(int)\0"
    "on_comboBox_aidOut_currentIndexChanged(int)\0"
    "on_comboBox_aidInc_currentIndexChanged(int)\0"
    "on_comboBox_gateInc_currentIndexChanged(int)\0"
    "on_comboBox_gateOut_currentIndexChanged(int)\0"
    "on_btn_allocateInc_clicked()\0"
    "on_btn_allocateOut_clicked()\0value\0"
    "on_DelayFlightId_currentIndexChanged(QString)\0"
    "on_Logout_clicked()\0on_okDelayFlight_clicked()\0"
    ",\0delay(int,int)\0refresh()\0bool\0f\0"
    "hasBeenAllocated(int)\0"
};

const QMetaObject uigtc::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_uigtc,
      qt_meta_data_uigtc, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &uigtc::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *uigtc::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *uigtc::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_uigtc))
        return static_cast<void*>(const_cast< uigtc*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int uigtc::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: on_btn_unallocate_clicked(); break;
        case 1: on_comboBox_gateUn_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: on_comboBox_aidOut_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: on_comboBox_aidInc_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: on_comboBox_gateInc_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: on_comboBox_gateOut_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: on_btn_allocateInc_clicked(); break;
        case 7: on_btn_allocateOut_clicked(); break;
        case 8: on_DelayFlightId_currentIndexChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 9: on_Logout_clicked(); break;
        case 10: on_okDelayFlight_clicked(); break;
        case 11: delay((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 12: refresh(); break;
        case 13: { bool _r = hasBeenAllocated((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        default: ;
        }
        _id -= 14;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
