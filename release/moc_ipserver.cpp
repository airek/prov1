/****************************************************************************
** Meta object code from reading C++ file 'ipserver.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../ipserver.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ipserver.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_IpServer_t {
    QByteArrayData data[17];
    char stringdata0[222];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_IpServer_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_IpServer_t qt_meta_stringdata_IpServer = {
    {
QT_MOC_LITERAL(0, 0, 8), // "IpServer"
QT_MOC_LITERAL(1, 9, 13), // "ipaddrChanged"
QT_MOC_LITERAL(2, 23, 0), // ""
QT_MOC_LITERAL(3, 24, 13), // "portNrChanged"
QT_MOC_LITERAL(4, 38, 15), // "clientConnected"
QT_MOC_LITERAL(5, 54, 6), // "ipAddr"
QT_MOC_LITERAL(6, 61, 18), // "clientDisconnected"
QT_MOC_LITERAL(7, 80, 6), // "partOK"
QT_MOC_LITERAL(8, 87, 15), // "onNewConnection"
QT_MOC_LITERAL(9, 103, 8), // "readData"
QT_MOC_LITERAL(10, 112, 11), // "QTcpSocket*"
QT_MOC_LITERAL(11, 124, 6), // "socket"
QT_MOC_LITERAL(12, 131, 16), // "removeConnection"
QT_MOC_LITERAL(13, 148, 11), // "onReadyRead"
QT_MOC_LITERAL(14, 160, 20), // "onSocketStateChanged"
QT_MOC_LITERAL(15, 181, 28), // "QAbstractSocket::SocketState"
QT_MOC_LITERAL(16, 210, 11) // "socketState"

    },
    "IpServer\0ipaddrChanged\0\0portNrChanged\0"
    "clientConnected\0ipAddr\0clientDisconnected\0"
    "partOK\0onNewConnection\0readData\0"
    "QTcpSocket*\0socket\0removeConnection\0"
    "onReadyRead\0onSocketStateChanged\0"
    "QAbstractSocket::SocketState\0socketState"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_IpServer[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   64,    2, 0x06 /* Public */,
       3,    0,   65,    2, 0x06 /* Public */,
       4,    1,   66,    2, 0x06 /* Public */,
       6,    1,   69,    2, 0x06 /* Public */,
       7,    0,   72,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       8,    0,   73,    2, 0x08 /* Private */,
       9,    1,   74,    2, 0x08 /* Private */,
      12,    1,   77,    2, 0x08 /* Private */,
      13,    0,   80,    2, 0x08 /* Private */,
      14,    1,   81,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 10,   11,
    QMetaType::Void, 0x80000000 | 10,   11,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 15,   16,

       0        // eod
};

void IpServer::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        IpServer *_t = static_cast<IpServer *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->ipaddrChanged(); break;
        case 1: _t->portNrChanged(); break;
        case 2: _t->clientConnected((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->clientDisconnected((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: _t->partOK(); break;
        case 5: _t->onNewConnection(); break;
        case 6: _t->readData((*reinterpret_cast< QTcpSocket*(*)>(_a[1]))); break;
        case 7: _t->removeConnection((*reinterpret_cast< QTcpSocket*(*)>(_a[1]))); break;
        case 8: _t->onReadyRead(); break;
        case 9: _t->onSocketStateChanged((*reinterpret_cast< QAbstractSocket::SocketState(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 9:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QAbstractSocket::SocketState >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (IpServer::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&IpServer::ipaddrChanged)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (IpServer::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&IpServer::portNrChanged)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (IpServer::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&IpServer::clientConnected)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (IpServer::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&IpServer::clientDisconnected)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (IpServer::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&IpServer::partOK)) {
                *result = 4;
                return;
            }
        }
    }
}

const QMetaObject IpServer::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_IpServer.data,
      qt_meta_data_IpServer,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *IpServer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *IpServer::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_IpServer.stringdata0))
        return static_cast<void*>(const_cast< IpServer*>(this));
    return QObject::qt_metacast(_clname);
}

int IpServer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    }
    return _id;
}

// SIGNAL 0
void IpServer::ipaddrChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void IpServer::portNrChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void IpServer::clientConnected(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void IpServer::clientDisconnected(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void IpServer::partOK()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
