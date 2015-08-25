/****************************************************************************
** Meta object code from reading C++ file 'HubAccount.hpp'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../src/HubAccount.hpp"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'HubAccount.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_HubAccount[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      25,   11,   12,   11, 0x0a,
      66,   48,   38,   11, 0x0a,
     110,   92,   38,   11, 0x0a,
     145,   11,   12,   11, 0x0a,
     248,  158,  153,   11, 0x0a,
     365,  332,  153,   11, 0x0a,
     412,   48,  153,   11, 0x0a,
     441,   48,  153,   11, 0x0a,
     472,   48,  153,   11, 0x0a,
     526,  505,   11,   11, 0x0a,
     564,  505,   11,   11, 0x0a,
     600,   11,   11,   11, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_HubAccount[] = {
    "HubAccount\0\0QVariantList\0categories()\0"
    "QVariant*\0categoryId,itemId\0"
    "getHubItem(qint64,qint64)\0categoryId,syncId\0"
    "getHubItemBySyncID(qint64,QString)\0"
    "items()\0bool\0"
    "categoryId,itemMap,name,subject,timestamp,itemSyncId,itemUserData,item"
    "ExtendedData,notify\0"
    "addHubItem(qint64,QVariantMap&,QString,QString,qint64,QString,QString,"
    "QString,bool)\0"
    "categoryId,itemId,itemMap,notify\0"
    "updateHubItem(qint64,qint64,QVariantMap&,bool)\0"
    "removeHubItem(qint64,qint64)\0"
    "markHubItemRead(qint64,qint64)\0"
    "markHubItemUnread(qint64,qint64)\0"
    "categoryId,timestamp\0"
    "markHubItemsReadBefore(qint64,qint64)\0"
    "removeHubItemsBefore(qint64,qint64)\0"
    "repopulateHub()\0"
};

void HubAccount::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        HubAccount *_t = static_cast<HubAccount *>(_o);
        switch (_id) {
        case 0: { QVariantList _r = _t->categories();
            if (_a[0]) *reinterpret_cast< QVariantList*>(_a[0]) = _r; }  break;
        case 1: { QVariant* _r = _t->getHubItem((*reinterpret_cast< qint64(*)>(_a[1])),(*reinterpret_cast< qint64(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< QVariant**>(_a[0]) = _r; }  break;
        case 2: { QVariant* _r = _t->getHubItemBySyncID((*reinterpret_cast< qint64(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< QVariant**>(_a[0]) = _r; }  break;
        case 3: { QVariantList _r = _t->items();
            if (_a[0]) *reinterpret_cast< QVariantList*>(_a[0]) = _r; }  break;
        case 4: { bool _r = _t->addHubItem((*reinterpret_cast< qint64(*)>(_a[1])),(*reinterpret_cast< QVariantMap(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4])),(*reinterpret_cast< qint64(*)>(_a[5])),(*reinterpret_cast< QString(*)>(_a[6])),(*reinterpret_cast< QString(*)>(_a[7])),(*reinterpret_cast< QString(*)>(_a[8])),(*reinterpret_cast< bool(*)>(_a[9])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 5: { bool _r = _t->updateHubItem((*reinterpret_cast< qint64(*)>(_a[1])),(*reinterpret_cast< qint64(*)>(_a[2])),(*reinterpret_cast< QVariantMap(*)>(_a[3])),(*reinterpret_cast< bool(*)>(_a[4])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 6: { bool _r = _t->removeHubItem((*reinterpret_cast< qint64(*)>(_a[1])),(*reinterpret_cast< qint64(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 7: { bool _r = _t->markHubItemRead((*reinterpret_cast< qint64(*)>(_a[1])),(*reinterpret_cast< qint64(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 8: { bool _r = _t->markHubItemUnread((*reinterpret_cast< qint64(*)>(_a[1])),(*reinterpret_cast< qint64(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 9: _t->markHubItemsReadBefore((*reinterpret_cast< qint64(*)>(_a[1])),(*reinterpret_cast< qint64(*)>(_a[2]))); break;
        case 10: _t->removeHubItemsBefore((*reinterpret_cast< qint64(*)>(_a[1])),(*reinterpret_cast< qint64(*)>(_a[2]))); break;
        case 11: _t->repopulateHub(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData HubAccount::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject HubAccount::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_HubAccount,
      qt_meta_data_HubAccount, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &HubAccount::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *HubAccount::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *HubAccount::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_HubAccount))
        return static_cast<void*>(const_cast< HubAccount*>(this));
    return QObject::qt_metacast(_clname);
}

int HubAccount::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
