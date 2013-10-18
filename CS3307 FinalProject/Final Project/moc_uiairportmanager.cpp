/****************************************************************************
** Meta object code from reading C++ file 'uiairportmanager.h'
**
** Created: Tue Mar 29 05:15:55 2011
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../Group10AMS/uiairportmanager.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'uiairportmanager.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_uiairportmanager[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
      21,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      18,   17,   17,   17, 0x08,
      49,   17,   17,   17, 0x08,
      88,   17,   17,   17, 0x08,
     125,   17,   17,   17, 0x08,
     165,  159,   17,   17, 0x08,
     202,   17,   17,   17, 0x08,
     232,   17,   17,   17, 0x08,
     260,   17,   17,   17, 0x08,
     288,   17,   17,   17, 0x08,
     322,   17,   17,   17, 0x08,
     356,   17,   17,   17, 0x08,
     390,   17,   17,   17, 0x08,
     420,   17,   17,   17, 0x08,
     452,   17,   17,   17, 0x08,
     488,   17,   17,   17, 0x08,
     521,   17,   17,   17, 0x08,
     557,   17,   17,   17, 0x08,
     597,   17,   17,   17, 0x08,
     634,   17,   17,   17, 0x08,
     668,   17,   17,   17, 0x08,
     705,   17,   17,   17, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_uiairportmanager[] = {
    "uiairportmanager\0\0on_standDeleteButton_clicked()\0"
    "on_standCreateAddStandButton_clicked()\0"
    "on_standUpdateDeleteButton_clicked()\0"
    "on_standUpdateAddButton_clicked()\0"
    "index\0on_aircraftIDComboBox_activated(int)\0"
    "on_passwordOKButton_clicked()\0"
    "on_bulkfileUpload_clicked()\0"
    "on_bulkfileOutput_clicked()\0"
    "on_aircraftDeleteButton_clicked()\0"
    "on_aircraftUpdateButton_clicked()\0"
    "on_aircraftCreateButton_clicked()\0"
    "on_aircraftOKButton_clicked()\0"
    "on_accountGTCOKButton_clicked()\0"
    "on_accountGTCDeleteButton_clicked()\0"
    "on_accountGTCAddButton_clicked()\0"
    "on_accountAirlineOKButton_clicked()\0"
    "on_accountAirlineDeleteButton_clicked()\0"
    "on_accountAirlineAddButton_clicked()\0"
    "on_airportManagerLOGOUT_clicked()\0"
    "on_flightRequestDenyButton_clicked()\0"
    "on_flightRequestAcceptButton_clicked()\0"
};

const QMetaObject uiairportmanager::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_uiairportmanager,
      qt_meta_data_uiairportmanager, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &uiairportmanager::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *uiairportmanager::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *uiairportmanager::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_uiairportmanager))
        return static_cast<void*>(const_cast< uiairportmanager*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int uiairportmanager::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: on_standDeleteButton_clicked(); break;
        case 1: on_standCreateAddStandButton_clicked(); break;
        case 2: on_standUpdateDeleteButton_clicked(); break;
        case 3: on_standUpdateAddButton_clicked(); break;
        case 4: on_aircraftIDComboBox_activated((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: on_passwordOKButton_clicked(); break;
        case 6: on_bulkfileUpload_clicked(); break;
        case 7: on_bulkfileOutput_clicked(); break;
        case 8: on_aircraftDeleteButton_clicked(); break;
        case 9: on_aircraftUpdateButton_clicked(); break;
        case 10: on_aircraftCreateButton_clicked(); break;
        case 11: on_aircraftOKButton_clicked(); break;
        case 12: on_accountGTCOKButton_clicked(); break;
        case 13: on_accountGTCDeleteButton_clicked(); break;
        case 14: on_accountGTCAddButton_clicked(); break;
        case 15: on_accountAirlineOKButton_clicked(); break;
        case 16: on_accountAirlineDeleteButton_clicked(); break;
        case 17: on_accountAirlineAddButton_clicked(); break;
        case 18: on_airportManagerLOGOUT_clicked(); break;
        case 19: on_flightRequestDenyButton_clicked(); break;
        case 20: on_flightRequestAcceptButton_clicked(); break;
        default: ;
        }
        _id -= 21;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
