/****************************************************************************
** Meta object code from reading C++ file 'backenddbcon.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../auxclass/backenddbcon.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'backenddbcon.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_BackendDbCon_t {
    QByteArrayData data[22];
    char stringdata0[217];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_BackendDbCon_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_BackendDbCon_t qt_meta_stringdata_BackendDbCon = {
    {
QT_MOC_LITERAL(0, 0, 12), // "BackendDbCon"
QT_MOC_LITERAL(1, 13, 7), // "execQry"
QT_MOC_LITERAL(2, 21, 0), // ""
QT_MOC_LITERAL(3, 22, 6), // "strQry"
QT_MOC_LITERAL(4, 29, 9), // "getMinVal"
QT_MOC_LITERAL(5, 39, 9), // "getMaxVal"
QT_MOC_LITERAL(6, 49, 9), // "getMidVal"
QT_MOC_LITERAL(7, 59, 14), // "getSHiftFactor"
QT_MOC_LITERAL(8, 74, 9), // "getSignal"
QT_MOC_LITERAL(9, 84, 10), // "getEFShift"
QT_MOC_LITERAL(10, 95, 10), // "getESShift"
QT_MOC_LITERAL(11, 106, 10), // "getETShift"
QT_MOC_LITERAL(12, 117, 12), // "getAckSignal"
QT_MOC_LITERAL(13, 130, 6), // "listen"
QT_MOC_LITERAL(14, 137, 10), // "serverName"
QT_MOC_LITERAL(15, 148, 6), // "IPAddr"
QT_MOC_LITERAL(16, 155, 6), // "portNr"
QT_MOC_LITERAL(17, 162, 10), // "getDevName"
QT_MOC_LITERAL(18, 173, 9), // "getIpAddr"
QT_MOC_LITERAL(19, 183, 9), // "getPortNr"
QT_MOC_LITERAL(20, 193, 15), // "getServerStatus"
QT_MOC_LITERAL(21, 209, 7) // "getLine"

    },
    "BackendDbCon\0execQry\0\0strQry\0getMinVal\0"
    "getMaxVal\0getMidVal\0getSHiftFactor\0"
    "getSignal\0getEFShift\0getESShift\0"
    "getETShift\0getAckSignal\0listen\0"
    "serverName\0IPAddr\0portNr\0getDevName\0"
    "getIpAddr\0getPortNr\0getServerStatus\0"
    "getLine"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_BackendDbCon[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      16,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // methods: name, argc, parameters, tag, flags
       1,    1,   94,    2, 0x02 /* Public */,
       4,    0,   97,    2, 0x02 /* Public */,
       5,    0,   98,    2, 0x02 /* Public */,
       6,    0,   99,    2, 0x02 /* Public */,
       7,    0,  100,    2, 0x02 /* Public */,
       8,    0,  101,    2, 0x02 /* Public */,
       9,    0,  102,    2, 0x02 /* Public */,
      10,    0,  103,    2, 0x02 /* Public */,
      11,    0,  104,    2, 0x02 /* Public */,
      12,    0,  105,    2, 0x02 /* Public */,
      13,    3,  106,    2, 0x02 /* Public */,
      17,    0,  113,    2, 0x02 /* Public */,
      18,    0,  114,    2, 0x02 /* Public */,
      19,    0,  115,    2, 0x02 /* Public */,
      20,    0,  116,    2, 0x02 /* Public */,
      21,    0,  117,    2, 0x02 /* Public */,

 // methods: parameters
    QMetaType::Bool, QMetaType::QString,    3,
    QMetaType::Int,
    QMetaType::Int,
    QMetaType::Int,
    QMetaType::QString,
    QMetaType::QString,
    QMetaType::QString,
    QMetaType::QString,
    QMetaType::QString,
    QMetaType::Bool,
    QMetaType::Bool, QMetaType::QString, QMetaType::QString, QMetaType::Int,   14,   15,   16,
    QMetaType::QString,
    QMetaType::QString,
    QMetaType::QString,
    QMetaType::Bool,
    QMetaType::QString,

       0        // eod
};

void BackendDbCon::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        BackendDbCon *_t = static_cast<BackendDbCon *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: { bool _r = _t->execQry((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 1: { int _r = _t->getMinVal();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 2: { int _r = _t->getMaxVal();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 3: { int _r = _t->getMidVal();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 4: { QString _r = _t->getSHiftFactor();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 5: { QString _r = _t->getSignal();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 6: { QString _r = _t->getEFShift();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 7: { QString _r = _t->getESShift();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 8: { QString _r = _t->getETShift();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 9: { bool _r = _t->getAckSignal();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 10: { bool _r = _t->listen((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 11: { QString _r = _t->getDevName();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 12: { QString _r = _t->getIpAddr();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 13: { QString _r = _t->getPortNr();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 14: { bool _r = _t->getServerStatus();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 15: { QString _r = _t->getLine();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    }
}

const QMetaObject BackendDbCon::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_BackendDbCon.data,
      qt_meta_data_BackendDbCon,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *BackendDbCon::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *BackendDbCon::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_BackendDbCon.stringdata0))
        return static_cast<void*>(const_cast< BackendDbCon*>(this));
    return QObject::qt_metacast(_clname);
}

int BackendDbCon::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 16)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 16;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 16)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 16;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
