/****************************************************************************
** Meta object code from reading C++ file 'backend.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../backend.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'backend.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Backend_t {
    QByteArrayData data[53];
    char stringdata0[609];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Backend_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Backend_t qt_meta_stringdata_Backend = {
    {
QT_MOC_LITERAL(0, 0, 7), // "Backend"
QT_MOC_LITERAL(1, 8, 15), // "serverListening"
QT_MOC_LITERAL(2, 24, 0), // ""
QT_MOC_LITERAL(3, 25, 21), // "clientServerConnected"
QT_MOC_LITERAL(4, 47, 24), // "clientServerDisconnected"
QT_MOC_LITERAL(5, 72, 13), // "cntrIncreased"
QT_MOC_LITERAL(6, 86, 16), // "targetsIncreased"
QT_MOC_LITERAL(7, 103, 8), // "cntrZero"
QT_MOC_LITERAL(8, 112, 11), // "targetsZero"
QT_MOC_LITERAL(9, 124, 15), // "socketConnected"
QT_MOC_LITERAL(10, 140, 8), // "ipAddres"
QT_MOC_LITERAL(11, 149, 18), // "clientDisconnected"
QT_MOC_LITERAL(12, 168, 17), // "countersIncreased"
QT_MOC_LITERAL(13, 186, 15), // "targetIncreased"
QT_MOC_LITERAL(14, 202, 11), // "setCntrZero"
QT_MOC_LITERAL(15, 214, 14), // "setTargetsZero"
QT_MOC_LITERAL(16, 229, 14), // "checkIfsetZero"
QT_MOC_LITERAL(17, 244, 6), // "listen"
QT_MOC_LITERAL(18, 251, 10), // "serverName"
QT_MOC_LITERAL(19, 262, 6), // "IPAddr"
QT_MOC_LITERAL(20, 269, 6), // "portNr"
QT_MOC_LITERAL(21, 276, 11), // "startServer"
QT_MOC_LITERAL(22, 288, 12), // "getShiftCntr"
QT_MOC_LITERAL(23, 301, 11), // "getHourCntr"
QT_MOC_LITERAL(24, 313, 9), // "getTarget"
QT_MOC_LITERAL(25, 323, 6), // "partNr"
QT_MOC_LITERAL(26, 330, 6), // "status"
QT_MOC_LITERAL(27, 337, 13), // "getTargetPerH"
QT_MOC_LITERAL(28, 351, 13), // "getTargetPers"
QT_MOC_LITERAL(29, 365, 10), // "getPartQty"
QT_MOC_LITERAL(30, 376, 10), // "getPersQty"
QT_MOC_LITERAL(31, 387, 16), // "getTimeToProduce"
QT_MOC_LITERAL(32, 404, 9), // "setTarget"
QT_MOC_LITERAL(33, 414, 13), // "targetPerHour"
QT_MOC_LITERAL(34, 428, 13), // "getHourTarget"
QT_MOC_LITERAL(35, 442, 7), // "execQry"
QT_MOC_LITERAL(36, 450, 6), // "strQry"
QT_MOC_LITERAL(37, 457, 13), // "writeSettings"
QT_MOC_LITERAL(38, 471, 7), // "targetH"
QT_MOC_LITERAL(39, 479, 7), // "targetS"
QT_MOC_LITERAL(40, 487, 4), // "resH"
QT_MOC_LITERAL(41, 492, 4), // "resS"
QT_MOC_LITERAL(42, 497, 7), // "persQty"
QT_MOC_LITERAL(43, 505, 7), // "partQty"
QT_MOC_LITERAL(44, 513, 9), // "ttProduce"
QT_MOC_LITERAL(45, 523, 10), // "targetPerH"
QT_MOC_LITERAL(46, 534, 9), // "getPartNr"
QT_MOC_LITERAL(47, 544, 9), // "getStatus"
QT_MOC_LITERAL(48, 554, 7), // "getLine"
QT_MOC_LITERAL(49, 562, 10), // "getDevName"
QT_MOC_LITERAL(50, 573, 9), // "getIpAddr"
QT_MOC_LITERAL(51, 583, 9), // "getPortNr"
QT_MOC_LITERAL(52, 593, 15) // "getServerStatus"

    },
    "Backend\0serverListening\0\0clientServerConnected\0"
    "clientServerDisconnected\0cntrIncreased\0"
    "targetsIncreased\0cntrZero\0targetsZero\0"
    "socketConnected\0ipAddres\0clientDisconnected\0"
    "countersIncreased\0targetIncreased\0"
    "setCntrZero\0setTargetsZero\0checkIfsetZero\0"
    "listen\0serverName\0IPAddr\0portNr\0"
    "startServer\0getShiftCntr\0getHourCntr\0"
    "getTarget\0partNr\0status\0getTargetPerH\0"
    "getTargetPers\0getPartQty\0getPersQty\0"
    "getTimeToProduce\0setTarget\0targetPerHour\0"
    "getHourTarget\0execQry\0strQry\0writeSettings\0"
    "targetH\0targetS\0resH\0resS\0persQty\0"
    "partQty\0ttProduce\0targetPerH\0getPartNr\0"
    "getStatus\0getLine\0getDevName\0getIpAddr\0"
    "getPortNr\0getServerStatus"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Backend[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      36,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       7,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,  194,    2, 0x06 /* Public */,
       3,    0,  195,    2, 0x06 /* Public */,
       4,    0,  196,    2, 0x06 /* Public */,
       5,    0,  197,    2, 0x06 /* Public */,
       6,    0,  198,    2, 0x06 /* Public */,
       7,    0,  199,    2, 0x06 /* Public */,
       8,    0,  200,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       9,    1,  201,    2, 0x0a /* Public */,
      11,    1,  204,    2, 0x0a /* Public */,
      12,    0,  207,    2, 0x0a /* Public */,
      13,    0,  208,    2, 0x0a /* Public */,
      14,    0,  209,    2, 0x0a /* Public */,
      15,    0,  210,    2, 0x0a /* Public */,
      16,    0,  211,    2, 0x0a /* Public */,

 // methods: name, argc, parameters, tag, flags
      17,    3,  212,    2, 0x02 /* Public */,
      21,    0,  219,    2, 0x02 /* Public */,
      22,    0,  220,    2, 0x02 /* Public */,
      23,    0,  221,    2, 0x02 /* Public */,
      24,    1,  222,    2, 0x02 /* Public */,
      26,    1,  225,    2, 0x02 /* Public */,
      27,    0,  228,    2, 0x02 /* Public */,
      28,    0,  229,    2, 0x02 /* Public */,
      29,    0,  230,    2, 0x02 /* Public */,
      30,    0,  231,    2, 0x02 /* Public */,
      31,    0,  232,    2, 0x02 /* Public */,
      32,    1,  233,    2, 0x02 /* Public */,
      34,    0,  236,    2, 0x02 /* Public */,
      35,    1,  237,    2, 0x02 /* Public */,
      37,   10,  240,    2, 0x02 /* Public */,
      46,    0,  261,    2, 0x02 /* Public */,
      47,    0,  262,    2, 0x02 /* Public */,
      48,    0,  263,    2, 0x02 /* Public */,
      49,    0,  264,    2, 0x02 /* Public */,
      50,    0,  265,    2, 0x02 /* Public */,
      51,    0,  266,    2, 0x02 /* Public */,
      52,    0,  267,    2, 0x02 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,   10,
    QMetaType::Void, QMetaType::QString,   10,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // methods: parameters
    QMetaType::Bool, QMetaType::QString, QMetaType::QString, QMetaType::Int,   18,   19,   20,
    QMetaType::Void,
    QMetaType::UInt,
    QMetaType::UInt,
    QMetaType::QString, QMetaType::QString,   25,
    QMetaType::Void, QMetaType::QString,   26,
    QMetaType::UInt,
    QMetaType::UInt,
    QMetaType::QString,
    QMetaType::QString,
    QMetaType::QString,
    QMetaType::Void, QMetaType::UInt,   33,
    QMetaType::UInt,
    QMetaType::Bool, QMetaType::QString,   36,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString,   25,   38,   39,   40,   41,   26,   42,   43,   44,   45,
    QMetaType::QString,
    QMetaType::QString,
    QMetaType::QString,
    QMetaType::QString,
    QMetaType::QString,
    QMetaType::QString,
    QMetaType::Bool,

       0        // eod
};

void Backend::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Backend *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->serverListening(); break;
        case 1: _t->clientServerConnected(); break;
        case 2: _t->clientServerDisconnected(); break;
        case 3: _t->cntrIncreased(); break;
        case 4: _t->targetsIncreased(); break;
        case 5: _t->cntrZero(); break;
        case 6: _t->targetsZero(); break;
        case 7: _t->socketConnected((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 8: _t->clientDisconnected((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 9: _t->countersIncreased(); break;
        case 10: _t->targetIncreased(); break;
        case 11: _t->setCntrZero(); break;
        case 12: _t->setTargetsZero(); break;
        case 13: _t->checkIfsetZero(); break;
        case 14: { bool _r = _t->listen((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 15: _t->startServer(); break;
        case 16: { uint _r = _t->getShiftCntr();
            if (_a[0]) *reinterpret_cast< uint*>(_a[0]) = std::move(_r); }  break;
        case 17: { uint _r = _t->getHourCntr();
            if (_a[0]) *reinterpret_cast< uint*>(_a[0]) = std::move(_r); }  break;
        case 18: { QString _r = _t->getTarget((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 19: _t->status((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 20: { uint _r = _t->getTargetPerH();
            if (_a[0]) *reinterpret_cast< uint*>(_a[0]) = std::move(_r); }  break;
        case 21: { uint _r = _t->getTargetPers();
            if (_a[0]) *reinterpret_cast< uint*>(_a[0]) = std::move(_r); }  break;
        case 22: { QString _r = _t->getPartQty();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 23: { QString _r = _t->getPersQty();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 24: { QString _r = _t->getTimeToProduce();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 25: _t->setTarget((*reinterpret_cast< uint(*)>(_a[1]))); break;
        case 26: { uint _r = _t->getHourTarget();
            if (_a[0]) *reinterpret_cast< uint*>(_a[0]) = std::move(_r); }  break;
        case 27: { bool _r = _t->execQry((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 28: _t->writeSettings((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4])),(*reinterpret_cast< QString(*)>(_a[5])),(*reinterpret_cast< QString(*)>(_a[6])),(*reinterpret_cast< QString(*)>(_a[7])),(*reinterpret_cast< QString(*)>(_a[8])),(*reinterpret_cast< QString(*)>(_a[9])),(*reinterpret_cast< QString(*)>(_a[10]))); break;
        case 29: { QString _r = _t->getPartNr();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 30: { QString _r = _t->getStatus();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 31: { QString _r = _t->getLine();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 32: { QString _r = _t->getDevName();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 33: { QString _r = _t->getIpAddr();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 34: { QString _r = _t->getPortNr();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 35: { bool _r = _t->getServerStatus();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Backend::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Backend::serverListening)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (Backend::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Backend::clientServerConnected)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (Backend::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Backend::clientServerDisconnected)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (Backend::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Backend::cntrIncreased)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (Backend::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Backend::targetsIncreased)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (Backend::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Backend::cntrZero)) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (Backend::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Backend::targetsZero)) {
                *result = 6;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Backend::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_Backend.data,
    qt_meta_data_Backend,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Backend::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Backend::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Backend.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int Backend::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 36)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 36;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 36)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 36;
    }
    return _id;
}

// SIGNAL 0
void Backend::serverListening()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void Backend::clientServerConnected()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void Backend::clientServerDisconnected()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void Backend::cntrIncreased()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void Backend::targetsIncreased()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void Backend::cntrZero()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}

// SIGNAL 6
void Backend::targetsZero()
{
    QMetaObject::activate(this, &staticMetaObject, 6, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
