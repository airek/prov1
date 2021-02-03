/****************************************************************************
** Meta object code from reading C++ file 'sqlquerymodel.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../auxclass/sqlquerymodel.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'sqlquerymodel.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_SqlQueryModel_t {
    QByteArrayData data[5];
    char stringdata0[39];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_SqlQueryModel_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_SqlQueryModel_t qt_meta_stringdata_SqlQueryModel = {
    {
QT_MOC_LITERAL(0, 0, 13), // "SqlQueryModel"
QT_MOC_LITERAL(1, 14, 8), // "setQuery"
QT_MOC_LITERAL(2, 23, 0), // ""
QT_MOC_LITERAL(3, 24, 5), // "query"
QT_MOC_LITERAL(4, 30, 8) // "nrOfRows"

    },
    "SqlQueryModel\0setQuery\0\0query\0nrOfRows"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SqlQueryModel[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // methods: name, argc, parameters, tag, flags
       1,    1,   24,    2, 0x02 /* Public */,
       4,    0,   27,    2, 0x02 /* Public */,

 // methods: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Int,

       0        // eod
};

void SqlQueryModel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        SqlQueryModel *_t = static_cast<SqlQueryModel *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->setQuery((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: { int _r = _t->nrOfRows();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    }
}

const QMetaObject SqlQueryModel::staticMetaObject = {
    { &QSqlQueryModel::staticMetaObject, qt_meta_stringdata_SqlQueryModel.data,
      qt_meta_data_SqlQueryModel,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *SqlQueryModel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SqlQueryModel::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_SqlQueryModel.stringdata0))
        return static_cast<void*>(const_cast< SqlQueryModel*>(this));
    return QSqlQueryModel::qt_metacast(_clname);
}

int SqlQueryModel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QSqlQueryModel::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 2;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
