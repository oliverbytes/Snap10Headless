/****************************************************************************
** Meta object code from reading C++ file 'UDSUtil.hpp'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../src/UDSUtil.hpp"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'UDSUtil.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_UDSUtil[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // methods: signature, parameters, type, tag, flags
      54,   14,    9,    8, 0x02,
     179,   98,   91,    8, 0x02,
     347,  279,    9,    8, 0x02,
     451,  441,    9,    8, 0x02,
     488,  473,    8,    8, 0x02,
     558,  526,   91,    8, 0x02,
     636,  593,    9,    8, 0x02,
     702,  681,    9,    8, 0x02,
     852,  732,   91,    8, 0x02,
    1095,  969,    9,    8, 0x02,
    1250, 1223,    9,    8, 0x02,
    1360, 1284,    9,    8, 0x02,
    1437, 1284,    9,    8, 0x02,
    1517, 1284,    9,    8, 0x02,
    1591, 1284,    9,    8, 0x02,

       0        // eod
};

static const char qt_meta_stringdata_UDSUtil[] = {
    "UDSUtil\0\0bool\0nextAccountId,nextCategoryId,nextItemId\0"
    "restoreNextIds(qint64,qint64,qint64)\0"
    "qint64\0"
    "name,displayName,serverName,target,icon,lockedIcon,composeIcon,desc,co"
    "mpose,type\0"
    "addAccount(QString,QString,QString,QString,QString,QString,QString,QSt"
    "ring,bool,uds_account_type_t)\0"
    "accountId,name,target,icon,lockedIcon,composeIcon,desc,compose,type\0"
    "updateAccount(qint64,QString,QString,QString,QString,QString,QString,b"
    "ool,uds_account_type_t)\0"
    "accountId\0removeAccount(qint64)\0"
    "accountId,name\0cleanupAccountsExcept(qint64,QString)\0"
    "accountId,name,parentCategoryId\0"
    "addCategory(qint64,QString,qint64)\0"
    "accountId,categoryId,name,parentCategoryId\0"
    "updateCategory(qint64,qint64,QString,qint64)\0"
    "accountId,categoryId\0removeCategory(qint64,qint64)\0"
    "accountId,categoryId,itemMap,name,subject,mimeType,icon,read,syncId,us"
    "erData,extendedData,timestamp,contextState,notify\0"
    "addItem(qint64,qint64,QVariantMap&,QString,QString,QString,QString,boo"
    "l,QString,QString,QString,long long,uint,bool)\0"
    "accountId,categoryId,itemMap,srcId,name,subject,mimeType,icon,read,syn"
    "cId,userData,extendedData,timestamp,contextState,notify\0"
    "updateItem(qint64,qint64,QVariantMap&,QString,QString,QString,QString,"
    "QString,bool,QString,QString,QString,long long,uint,bool)\0"
    "accountId,categoryId,srcId\0"
    "removeItem(qint64,qint64,QString)\0"
    "accountId,action,title,invtarget,invtargettype,imgsource,mimetype,plac"
    "ement\0"
    "addAccountAction(qint64,QString,QString,QString,QString,QString,QStrin"
    "g,int)\0"
    "updateAccountAction(qint64,QString,QString,QString,QString,QString,QSt"
    "ring,int)\0"
    "addItemAction(qint64,QString,QString,QString,QString,QString,QString,i"
    "nt)\0"
    "updateItemAction(qint64,QString,QString,QString,QString,QString,QStrin"
    "g,int)\0"
};

void UDSUtil::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        UDSUtil *_t = static_cast<UDSUtil *>(_o);
        switch (_id) {
        case 0: { bool _r = _t->restoreNextIds((*reinterpret_cast< qint64(*)>(_a[1])),(*reinterpret_cast< qint64(*)>(_a[2])),(*reinterpret_cast< qint64(*)>(_a[3])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 1: { qint64 _r = _t->addAccount((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4])),(*reinterpret_cast< QString(*)>(_a[5])),(*reinterpret_cast< QString(*)>(_a[6])),(*reinterpret_cast< QString(*)>(_a[7])),(*reinterpret_cast< QString(*)>(_a[8])),(*reinterpret_cast< bool(*)>(_a[9])),(*reinterpret_cast< uds_account_type_t(*)>(_a[10])));
            if (_a[0]) *reinterpret_cast< qint64*>(_a[0]) = _r; }  break;
        case 2: { bool _r = _t->updateAccount((*reinterpret_cast< qint64(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4])),(*reinterpret_cast< QString(*)>(_a[5])),(*reinterpret_cast< QString(*)>(_a[6])),(*reinterpret_cast< QString(*)>(_a[7])),(*reinterpret_cast< bool(*)>(_a[8])),(*reinterpret_cast< uds_account_type_t(*)>(_a[9])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 3: { bool _r = _t->removeAccount((*reinterpret_cast< qint64(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 4: _t->cleanupAccountsExcept((*reinterpret_cast< const qint64(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 5: { qint64 _r = _t->addCategory((*reinterpret_cast< qint64(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< qint64(*)>(_a[3])));
            if (_a[0]) *reinterpret_cast< qint64*>(_a[0]) = _r; }  break;
        case 6: { bool _r = _t->updateCategory((*reinterpret_cast< qint64(*)>(_a[1])),(*reinterpret_cast< qint64(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< qint64(*)>(_a[4])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 7: { bool _r = _t->removeCategory((*reinterpret_cast< qint64(*)>(_a[1])),(*reinterpret_cast< qint64(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 8: { qint64 _r = _t->addItem((*reinterpret_cast< qint64(*)>(_a[1])),(*reinterpret_cast< qint64(*)>(_a[2])),(*reinterpret_cast< QVariantMap(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4])),(*reinterpret_cast< QString(*)>(_a[5])),(*reinterpret_cast< QString(*)>(_a[6])),(*reinterpret_cast< QString(*)>(_a[7])),(*reinterpret_cast< bool(*)>(_a[8])),(*reinterpret_cast< QString(*)>(_a[9])),(*reinterpret_cast< QString(*)>(_a[10])),(*reinterpret_cast< QString(*)>(_a[11])),(*reinterpret_cast< long long(*)>(_a[12])),(*reinterpret_cast< uint(*)>(_a[13])),(*reinterpret_cast< bool(*)>(_a[14])));
            if (_a[0]) *reinterpret_cast< qint64*>(_a[0]) = _r; }  break;
        case 9: { bool _r = _t->updateItem((*reinterpret_cast< qint64(*)>(_a[1])),(*reinterpret_cast< qint64(*)>(_a[2])),(*reinterpret_cast< QVariantMap(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4])),(*reinterpret_cast< QString(*)>(_a[5])),(*reinterpret_cast< QString(*)>(_a[6])),(*reinterpret_cast< QString(*)>(_a[7])),(*reinterpret_cast< QString(*)>(_a[8])),(*reinterpret_cast< bool(*)>(_a[9])),(*reinterpret_cast< QString(*)>(_a[10])),(*reinterpret_cast< QString(*)>(_a[11])),(*reinterpret_cast< QString(*)>(_a[12])),(*reinterpret_cast< long long(*)>(_a[13])),(*reinterpret_cast< uint(*)>(_a[14])),(*reinterpret_cast< bool(*)>(_a[15])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 10: { bool _r = _t->removeItem((*reinterpret_cast< qint64(*)>(_a[1])),(*reinterpret_cast< qint64(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 11: { bool _r = _t->addAccountAction((*reinterpret_cast< qint64(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4])),(*reinterpret_cast< QString(*)>(_a[5])),(*reinterpret_cast< QString(*)>(_a[6])),(*reinterpret_cast< QString(*)>(_a[7])),(*reinterpret_cast< int(*)>(_a[8])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 12: { bool _r = _t->updateAccountAction((*reinterpret_cast< qint64(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4])),(*reinterpret_cast< QString(*)>(_a[5])),(*reinterpret_cast< QString(*)>(_a[6])),(*reinterpret_cast< QString(*)>(_a[7])),(*reinterpret_cast< int(*)>(_a[8])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 13: { bool _r = _t->addItemAction((*reinterpret_cast< qint64(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4])),(*reinterpret_cast< QString(*)>(_a[5])),(*reinterpret_cast< QString(*)>(_a[6])),(*reinterpret_cast< QString(*)>(_a[7])),(*reinterpret_cast< int(*)>(_a[8])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 14: { bool _r = _t->updateItemAction((*reinterpret_cast< qint64(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4])),(*reinterpret_cast< QString(*)>(_a[5])),(*reinterpret_cast< QString(*)>(_a[6])),(*reinterpret_cast< QString(*)>(_a[7])),(*reinterpret_cast< int(*)>(_a[8])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        default: ;
        }
    }
}

const QMetaObjectExtraData UDSUtil::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject UDSUtil::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_UDSUtil,
      qt_meta_data_UDSUtil, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &UDSUtil::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *UDSUtil::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *UDSUtil::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_UDSUtil))
        return static_cast<void*>(const_cast< UDSUtil*>(this));
    return QObject::qt_metacast(_clname);
}

int UDSUtil::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
