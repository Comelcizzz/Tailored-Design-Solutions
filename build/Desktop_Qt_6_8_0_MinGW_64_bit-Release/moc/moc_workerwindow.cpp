/****************************************************************************
** Meta object code from reading C++ file 'workerwindow.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../workerwindow.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'workerwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSWorkerWindowENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSWorkerWindowENDCLASS = QtMocHelpers::stringData(
    "WorkerWindow",
    "loadAvailableOrders",
    "",
    "loadAcceptedOrders",
    "acceptOrder",
    "saveWorkDetails",
    "viewOrderDetails",
    "loadCompletedOrders",
    "on_btnLoadCompletedOrders_clicked",
    "on_btnLoadActiveOrders_clicked",
    "on_btnSaveDetails_clicked",
    "on_btnLoadOrders_clicked",
    "on_btnSearchOrders_clicked"
);
#else  // !QT_MOC_HAS_STRINGDATA
#error "qtmochelpers.h not found or too old."
#endif // !QT_MOC_HAS_STRINGDATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSWorkerWindowENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   80,    2, 0x08,    1 /* Private */,
       3,    0,   81,    2, 0x08,    2 /* Private */,
       4,    0,   82,    2, 0x08,    3 /* Private */,
       5,    0,   83,    2, 0x08,    4 /* Private */,
       6,    0,   84,    2, 0x08,    5 /* Private */,
       7,    0,   85,    2, 0x08,    6 /* Private */,
       8,    0,   86,    2, 0x08,    7 /* Private */,
       9,    0,   87,    2, 0x08,    8 /* Private */,
      10,    0,   88,    2, 0x08,    9 /* Private */,
      11,    0,   89,    2, 0x08,   10 /* Private */,
      12,    0,   90,    2, 0x08,   11 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject WorkerWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_CLASSWorkerWindowENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSWorkerWindowENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSWorkerWindowENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<WorkerWindow, std::true_type>,
        // method 'loadAvailableOrders'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'loadAcceptedOrders'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'acceptOrder'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'saveWorkDetails'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'viewOrderDetails'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'loadCompletedOrders'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_btnLoadCompletedOrders_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_btnLoadActiveOrders_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_btnSaveDetails_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_btnLoadOrders_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_btnSearchOrders_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void WorkerWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<WorkerWindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->loadAvailableOrders(); break;
        case 1: _t->loadAcceptedOrders(); break;
        case 2: _t->acceptOrder(); break;
        case 3: _t->saveWorkDetails(); break;
        case 4: _t->viewOrderDetails(); break;
        case 5: _t->loadCompletedOrders(); break;
        case 6: _t->on_btnLoadCompletedOrders_clicked(); break;
        case 7: _t->on_btnLoadActiveOrders_clicked(); break;
        case 8: _t->on_btnSaveDetails_clicked(); break;
        case 9: _t->on_btnLoadOrders_clicked(); break;
        case 10: _t->on_btnSearchOrders_clicked(); break;
        default: ;
        }
    }
    (void)_a;
}

const QMetaObject *WorkerWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *WorkerWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSWorkerWindowENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int WorkerWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 11;
    }
    return _id;
}
QT_WARNING_POP
