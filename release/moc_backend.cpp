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
    QByteArrayData data[68];
    char stringdata0[772];
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
QT_MOC_LITERAL(24, 313, 12), // "getOrderCntr"
QT_MOC_LITERAL(25, 326, 12), // "setOrderCntr"
QT_MOC_LITERAL(26, 339, 9), // "orderCntr"
QT_MOC_LITERAL(27, 349, 9), // "getTarget"
QT_MOC_LITERAL(28, 359, 6), // "partNr"
QT_MOC_LITERAL(29, 366, 6), // "status"
QT_MOC_LITERAL(30, 373, 13), // "getTargetPerH"
QT_MOC_LITERAL(31, 387, 13), // "getTargetPers"
QT_MOC_LITERAL(32, 401, 10), // "getPartQty"
QT_MOC_LITERAL(33, 412, 10), // "getPersQty"
QT_MOC_LITERAL(34, 423, 16), // "getTimeToProduce"
QT_MOC_LITERAL(35, 440, 9), // "setTarget"
QT_MOC_LITERAL(36, 450, 13), // "targetPerHour"
QT_MOC_LITERAL(37, 464, 13), // "getHourTarget"
QT_MOC_LITERAL(38, 478, 7), // "execQry"
QT_MOC_LITERAL(39, 486, 6), // "strQry"
QT_MOC_LITERAL(40, 493, 13), // "writeSettings"
QT_MOC_LITERAL(41, 507, 7), // "targetH"
QT_MOC_LITERAL(42, 515, 7), // "targetS"
QT_MOC_LITERAL(43, 523, 4), // "resH"
QT_MOC_LITERAL(44, 528, 4), // "resS"
QT_MOC_LITERAL(45, 533, 7), // "persQty"
QT_MOC_LITERAL(46, 541, 7), // "partQty"
QT_MOC_LITERAL(47, 549, 9), // "ttProduce"
QT_MOC_LITERAL(48, 559, 10), // "targetPerH"
QT_MOC_LITERAL(49, 570, 7), // "orderId"
QT_MOC_LITERAL(50, 578, 7), // "auxTime"
QT_MOC_LITERAL(51, 586, 7), // "auxDate"
QT_MOC_LITERAL(52, 594, 8), // "prodTime"
QT_MOC_LITERAL(53, 603, 9), // "breakTime"
QT_MOC_LITERAL(54, 613, 9), // "getPartNr"
QT_MOC_LITERAL(55, 623, 9), // "getStatus"
QT_MOC_LITERAL(56, 633, 7), // "getLine"
QT_MOC_LITERAL(57, 641, 10), // "getDevName"
QT_MOC_LITERAL(58, 652, 9), // "getIpAddr"
QT_MOC_LITERAL(59, 662, 9), // "getPortNr"
QT_MOC_LITERAL(60, 672, 15), // "getServerStatus"
QT_MOC_LITERAL(61, 688, 10), // "getOrderID"
QT_MOC_LITERAL(62, 699, 10), // "getAuxTime"
QT_MOC_LITERAL(63, 710, 10), // "getAuxDate"
QT_MOC_LITERAL(64, 721, 11), // "getProdTime"
QT_MOC_LITERAL(65, 733, 12), // "getBreakTime"
QT_MOC_LITERAL(66, 746, 13), // "isDbConnected"
QT_MOC_LITERAL(67, 760, 11) // "connectToDB"

    },
    "Backend\0serverListening\0\0clientServerConnected\0"
    "clientServerDisconnected\0cntrIncreased\0"
    "targetsIncreased\0cntrZero\0targetsZero\0"
    "socketConnected\0ipAddres\0clientDisconnected\0"
    "countersIncreased\0targetIncreased\0"
    "setCntrZero\0setTargetsZero\0checkIfsetZero\0"
    "listen\0serverName\0IPAddr\0portNr\0"
    "startServer\0getShiftCntr\0getHourCntr\0"
    "getOrderCntr\0setOrderCntr\0orderCntr\0"
    "getTarget\0partNr\0status\0getTargetPerH\0"
    "getTargetPers\0getPartQty\0getPersQty\0"
    "getTimeToProduce\0setTarget\0targetPerHour\0"
    "getHourTarget\0execQry\0strQry\0writeSettings\0"
    "targetH\0targetS\0resH\0resS\0persQty\0"
    "partQty\0ttProduce\0targetPerH\0orderId\0"
    "auxTime\0auxDate\0prodTime\0breakTime\0"
    "getPartNr\0getStatus\0getLine\0getDevName\0"
    "getIpAddr\0getPortNr\0getServerStatus\0"
    "getOrderID\0getAuxTime\0getAuxDate\0"
    "getProdTime\0getBreakTime\0isDbConnected\0"
    "connectToDB"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Backend[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      45,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       7,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,  239,    2, 0x06 /* Public */,
       3,    0,  240,    2, 0x06 /* Public */,
       4,    0,  241,    2, 0x06 /* Public */,
       5,    0,  242,    2, 0x06 /* Public */,
       6,    0,  243,    2, 0x06 /* Public */,
       7,    0,  244,    2, 0x06 /* Public */,
       8,    0,  245,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       9,    1,  246,    2, 0x0a /* Public */,
      11,    1,  249,    2, 0x0a /* Public */,
      12,    0,  252,    2, 0x0a /* Public */,
      13,    0,  253,    2, 0x0a /* Public */,
      14,    0,  254,    2, 0x0a /* Public */,
      15,    0,  255,    2, 0x0a /* Public */,
      16,    0,  256,    2, 0x0a /* Public */,

 // methods: name, argc, parameters, tag, flags
      17,    3,  257,    2, 0x02 /* Public */,
      21,    0,  264,    2, 0x02 /* Public */,
      22,    0,  265,    2, 0x02 /* Public */,
      23,    0,  266,    2, 0x02 /* Public */,
      24,    0,  267,    2, 0x02 /* Public */,
      25,    1,  268,    2, 0x02 /* Public */,
      27,    1,  271,    2, 0x02 /* Public */,
      29,    1,  274,    2, 0x02 /* Public */,
      30,    0,  277,    2, 0x02 /* Public */,
      31,    0,  278,    2, 0x02 /* Public */,
      32,    0,  279,    2, 0x02 /* Public */,
      33,    0,  280,    2, 0x02 /* Public */,
      34,    0,  281,    2, 0x02 /* Public */,
      35,    1,  282,    2, 0x02 /* Public */,
      37,    0,  285,    2, 0x02 /* Public */,
      38,    1,  286,    2, 0x02 /* Public */,
      40,   16,  289,    2, 0x02 /* Public */,
      54,    0,  322,    2, 0x02 /* Public */,
      55,    0,  323,    2, 0x02 /* Public */,
      56,    0,  324,    2, 0x02 /* Public */,
      57,    0,  325,    2, 0x02 /* Public */,
      58,    0,  326,    2, 0x02 /* Public */,
      59,    0,  327,    2, 0x02 /* Public */,
      60,    0,  328,    2, 0x02 /* Public */,
      61,    0,  329,    2, 0x02 /* Public */,
      62,    0,  330,    2, 0x02 /* Public */,
      63,    0,  331,    2, 0x02 /* Public */,
      64,    0,  332,    2, 0x02 /* Public */,
      65,    0,  333,    2, 0x02 /* Public */,
      66,    0,  334,    2, 0x02 /* Public */,
      67,    0,  335,    2, 0x02 /* Public */,

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
    QMetaType::UInt,
    QMetaType::Void, QMetaType::UInt,   26,
    QMetaType::QString, QMetaType::QString,   28,
    QMetaType::Void, QMetaType::QString,   29,
    QMetaType::UInt,
    QMetaType::UInt,
    QMetaType::QString,
    QMetaType::QString,
    QMetaType::QString,
    QMetaType::Void, QMetaType::UInt,   36,
    QMetaType::UInt,
    QMetaType::Bool, QMetaType::QString,   39,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString,   28,   41,   42,   43,   44,   29,   45,   46,   47,   48,   26,   49,   50,   51,   52,   53,
    QMetaType::QString,
    QMetaType::QString,
    QMetaType::QString,
    QMetaType::QString,
    QMetaType::QString,
    QMetaType::QString,
    QMetaType::Bool,
    QMetaType::QString,
    QMetaType::Int,
    QMetaType::QString,
    QMetaType::Int,
    QMetaType::Int,
    QMetaType::Bool,
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
        case 18: { uint _r = _t->getOrderCntr();
            if (_a[0]) *reinterpret_cast< uint*>(_a[0]) = std::move(_r); }  break;
        case 19: _t->setOrderCntr((*reinterpret_cast< uint(*)>(_a[1]))); break;
        case 20: { QString _r = _t->getTarget((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 21: _t->status((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 22: { uint _r = _t->getTargetPerH();
            if (_a[0]) *reinterpret_cast< uint*>(_a[0]) = std::move(_r); }  break;
        case 23: { uint _r = _t->getTargetPers();
            if (_a[0]) *reinterpret_cast< uint*>(_a[0]) = std::move(_r); }  break;
        case 24: { QString _r = _t->getPartQty();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 25: { QString _r = _t->getPersQty();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 26: { QString _r = _t->getTimeToProduce();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 27: _t->setTarget((*reinterpret_cast< uint(*)>(_a[1]))); break;
        case 28: { uint _r = _t->getHourTarget();
            if (_a[0]) *reinterpret_cast< uint*>(_a[0]) = std::move(_r); }  break;
        case 29: { bool _r = _t->execQry((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 30: _t->writeSettings((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4])),(*reinterpret_cast< QString(*)>(_a[5])),(*reinterpret_cast< QString(*)>(_a[6])),(*reinterpret_cast< QString(*)>(_a[7])),(*reinterpret_cast< QString(*)>(_a[8])),(*reinterpret_cast< QString(*)>(_a[9])),(*reinterpret_cast< QString(*)>(_a[10])),(*reinterpret_cast< QString(*)>(_a[11])),(*reinterpret_cast< QString(*)>(_a[12])),(*reinterpret_cast< QString(*)>(_a[13])),(*reinterpret_cast< QString(*)>(_a[14])),(*reinterpret_cast< QString(*)>(_a[15])),(*reinterpret_cast< QString(*)>(_a[16]))); break;
        case 31: { QString _r = _t->getPartNr();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 32: { QString _r = _t->getStatus();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 33: { QString _r = _t->getLine();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 34: { QString _r = _t->getDevName();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 35: { QString _r = _t->getIpAddr();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 36: { QString _r = _t->getPortNr();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 37: { bool _r = _t->getServerStatus();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 38: { QString _r = _t->getOrderID();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 39: { int _r = _t->getAuxTime();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 40: { QString _r = _t->getAuxDate();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 41: { int _r = _t->getProdTime();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 42: { int _r = _t->getBreakTime();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 43: { bool _r = _t->isDbConnected();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 44: { bool _r = _t->connectToDB();
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
        if (_id < 45)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 45;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 45)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 45;
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
