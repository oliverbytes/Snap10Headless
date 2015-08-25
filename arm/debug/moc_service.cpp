/****************************************************************************
** Meta object code from reading C++ file 'service.hpp'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../src/service.hpp"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'service.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Service[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      20,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      36,    9,    8,    8, 0x05,

 // slots: signature, parameters, type, tag, flags
      78,   70,    8,    8, 0x0a,
     115,    8,    8,    8, 0x0a,
     127,    8,    8,    8, 0x0a,
     142,    8,    8,    8, 0x08,
     154,    8,    8,    8, 0x08,
     167,    8,    8,    8, 0x08,

 // methods: signature, parameters, type, tag, flags
     183,  178,    8,    8, 0x02,
     203,    8,    8,    8, 0x02,
     224,  213,    8,    8, 0x02,
     257,  250,    8,    8, 0x02,
     292,  275,    8,    8, 0x02,
     342,  332,  327,    8, 0x02,
     400,  376,  368,    8, 0x02,
     450,  428,    8,    8, 0x02,
     494,  478,  368,    8, 0x02,
     536,    8,  532,    8, 0x02,
     543,    8,    8,    8, 0x02,
     557,  549,  368,    8, 0x02,
     596,  571,  532,    8, 0x02,

       0        // eod
};

static const char qt_meta_stringdata_Service[] = {
    "Service\0\0response,httpcode,endpoint\0"
    "complete(QString,QString,QString)\0"
    "request\0onInvoked(bb::system::InvokeRequest)\0"
    "connected()\0disconnected()\0onTimeout()\0"
    "onComplete()\0timedout()\0data\0"
    "socketSend(QString)\0refresh()\0jsonString\0"
    "parseUpdatesJSON(QString)\0params\0"
    "request(QVariant)\0title,message,id\0"
    "notifyHub(QString,QString,QString)\0"
    "bool\0text,find\0contains(QString,QString)\0"
    "QString\0objectName,defaultValue\0"
    "getSetting(QString,QString)\0"
    "objectName,inputValue\0setSetting(QString,QString)\0"
    "timestamp,token\0generateRequestToken(quint64,QString)\0"
    "int\0init()\0end()\0decimal\0intToHex(int)\0"
    "input_data,messageDigest\0"
    "hash(QString,unsigned char*)\0"
};

void Service::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        Service *_t = static_cast<Service *>(_o);
        switch (_id) {
        case 0: _t->complete((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3]))); break;
        case 1: _t->onInvoked((*reinterpret_cast< const bb::system::InvokeRequest(*)>(_a[1]))); break;
        case 2: _t->connected(); break;
        case 3: _t->disconnected(); break;
        case 4: _t->onTimeout(); break;
        case 5: _t->onComplete(); break;
        case 6: _t->timedout(); break;
        case 7: _t->socketSend((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 8: _t->refresh(); break;
        case 9: _t->parseUpdatesJSON((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 10: _t->request((*reinterpret_cast< QVariant(*)>(_a[1]))); break;
        case 11: _t->notifyHub((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3]))); break;
        case 12: { bool _r = _t->contains((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 13: { QString _r = _t->getSetting((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 14: _t->setSetting((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 15: { QString _r = _t->generateRequestToken((*reinterpret_cast< quint64(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 16: { int _r = _t->init();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 17: _t->end(); break;
        case 18: { QString _r = _t->intToHex((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 19: { int _r = _t->hash((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< unsigned char*(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        default: ;
        }
    }
}

const QMetaObjectExtraData Service::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject Service::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Service,
      qt_meta_data_Service, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Service::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Service::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Service::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Service))
        return static_cast<void*>(const_cast< Service*>(this));
    return QObject::qt_metacast(_clname);
}

int Service::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 20)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 20;
    }
    return _id;
}

// SIGNAL 0
void Service::complete(QString _t1, QString _t2, QString _t3)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
