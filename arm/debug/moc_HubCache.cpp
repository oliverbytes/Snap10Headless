/****************************************************************************
** Meta object code from reading C++ file 'HubCache.hpp'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../src/HubCache.hpp"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'HubCache.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_HubCache[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       6,   49, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      20,   10,    9,    9, 0x0a,
      50,   38,    9,    9, 0x0a,
      85,   74,    9,    9, 0x0a,
     121,  113,    9,    9, 0x0a,
     157,  142,    9,    9, 0x0a,
     195,  188,    9,    9, 0x0a,
     220,  214,    9,    9, 0x0a,

 // properties: name, type, flags
      10,  243, 0x02095103,
      38,  247, 0x0a095103,
     255,  243, 0x02095001,
      74,  270, 0x09095103,
     283,  243, 0x02095001,
     214,  270, 0x09095103,

       0        // eod
};

static const char qt_meta_stringdata_HubCache[] = {
    "HubCache\0\0accountId\0setAccountId(int)\0"
    "accountName\0setAccountName(QString)\0"
    "categories\0setCategories(QVariantList)\0"
    "itemMap\0addItem(QVariantMap)\0"
    "itemId,itemMap\0updateItem(qint64,QVariantMap)\0"
    "itemId\0removeItem(qint64)\0items\0"
    "setItems(QVariantList)\0int\0QString\0"
    "lastCategoryId\0QVariantList\0lastItemId\0"
};

void HubCache::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        HubCache *_t = static_cast<HubCache *>(_o);
        switch (_id) {
        case 0: _t->setAccountId((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->setAccountName((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->setCategories((*reinterpret_cast< QVariantList(*)>(_a[1]))); break;
        case 3: _t->addItem((*reinterpret_cast< QVariantMap(*)>(_a[1]))); break;
        case 4: _t->updateItem((*reinterpret_cast< qint64(*)>(_a[1])),(*reinterpret_cast< QVariantMap(*)>(_a[2]))); break;
        case 5: _t->removeItem((*reinterpret_cast< qint64(*)>(_a[1]))); break;
        case 6: _t->setItems((*reinterpret_cast< QVariantList(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData HubCache::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject HubCache::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_HubCache,
      qt_meta_data_HubCache, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &HubCache::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *HubCache::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *HubCache::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_HubCache))
        return static_cast<void*>(const_cast< HubCache*>(this));
    return QObject::qt_metacast(_clname);
}

int HubCache::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    }
#ifndef QT_NO_PROPERTIES
      else if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< int*>(_v) = accountId(); break;
        case 1: *reinterpret_cast< QString*>(_v) = accountName(); break;
        case 2: *reinterpret_cast< int*>(_v) = lastCategoryId(); break;
        case 3: *reinterpret_cast< QVariantList*>(_v) = categories(); break;
        case 4: *reinterpret_cast< int*>(_v) = lastItemId(); break;
        case 5: *reinterpret_cast< QVariantList*>(_v) = items(); break;
        }
        _id -= 6;
    } else if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: setAccountId(*reinterpret_cast< int*>(_v)); break;
        case 1: setAccountName(*reinterpret_cast< QString*>(_v)); break;
        case 3: setCategories(*reinterpret_cast< QVariantList*>(_v)); break;
        case 5: setItems(*reinterpret_cast< QVariantList*>(_v)); break;
        }
        _id -= 6;
    } else if (_c == QMetaObject::ResetProperty) {
        _id -= 6;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 6;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 6;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 6;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 6;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 6;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}
QT_END_MOC_NAMESPACE
