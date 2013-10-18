/****************************************************************************
** Meta object code from reading C++ file 'uiairlinerep.h'
**
** Created: Tue Mar 29 05:15:56 2011
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../Group10AMS/uiairlinerep.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'uiairlinerep.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_uiairlinerep[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
      18,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      14,   13,   13,   13, 0x08,
      40,   13,   13,   13, 0x08,
      65,   13,   13,   13, 0x08,
      91,   13,   13,   13, 0x08,
     116,   13,   13,   13, 0x08,
     139,   13,   13,   13, 0x08,
     161,   13,   13,   13, 0x08,
     185,   13,   13,   13, 0x08,
     210,   13,   13,   13, 0x08,
     235,   13,   13,   13, 0x08,
     263,   13,   13,   13, 0x08,
     291,   13,   13,   13, 0x08,
     320,   13,   13,   13, 0x08,
     348,   13,   13,   13, 0x08,
     371,   13,   13,   13, 0x08,
     393,   13,   13,   13, 0x08,
     442,   13,   13,   13, 0x08,
     492,   13,   13,   13, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_uiairlinerep[] = {
    "uiairlinerep\0\0on_reqOutSubmit_clicked()\0"
    "on_reqInSubmit_clicked()\0"
    "on_reqOutWeekly_clicked()\0"
    "on_reqOutDaily_clicked()\0"
    "on_reqOutOne_clicked()\0on_reqInOne_clicked()\0"
    "on_reqInDaily_clicked()\0"
    "on_reqInWeekly_clicked()\0"
    "on_addAircraft_clicked()\0"
    "on_deleteAircraft_clicked()\0"
    "on_editaircraftid_clicked()\0"
    "on_exceptOutUpdate_clicked()\0"
    "on_exceptInUpdate_clicked()\0"
    "on_outCancel_clicked()\0on_inCancel_clicked()\0"
    "on_exceptInFlightID_currentIndexChanged(QString)\0"
    "on_exceptOutFlightID_currentIndexChanged(QString)\0"
    "on_pushButton_9_clicked()\0"
};

const QMetaObject uiairlinerep::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_uiairlinerep,
      qt_meta_data_uiairlinerep, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &uiairlinerep::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *uiairlinerep::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *uiairlinerep::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_uiairlinerep))
        return static_cast<void*>(const_cast< uiairlinerep*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int uiairlinerep::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: on_reqOutSubmit_clicked(); break;
        case 1: on_reqInSubmit_clicked(); break;
        case 2: on_reqOutWeekly_clicked(); break;
        case 3: on_reqOutDaily_clicked(); break;
        case 4: on_reqOutOne_clicked(); break;
        case 5: on_reqInOne_clicked(); break;
        case 6: on_reqInDaily_clicked(); break;
        case 7: on_reqInWeekly_clicked(); break;
        case 8: on_addAircraft_clicked(); break;
        case 9: on_deleteAircraft_clicked(); break;
        case 10: on_editaircraftid_clicked(); break;
        case 11: on_exceptOutUpdate_clicked(); break;
        case 12: on_exceptInUpdate_clicked(); break;
        case 13: on_outCancel_clicked(); break;
        case 14: on_inCancel_clicked(); break;
        case 15: on_exceptInFlightID_currentIndexChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 16: on_exceptOutFlightID_currentIndexChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 17: on_pushButton_9_clicked(); break;
        default: ;
        }
        _id -= 18;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
