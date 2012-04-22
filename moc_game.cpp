/****************************************************************************
** Meta object code from reading C++ file 'game.h'
**
** Created: Sat Apr 21 15:13:23 2012
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "game.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'game.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Game[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
       6,    5,    5,    5, 0x08,
      21,    5,    5,    5, 0x08,
      46,    5,    5,    5, 0x08,
      72,    5,    5,    5, 0x08,
      97,    5,    5,    5, 0x08,
     110,    5,    5,    5, 0x08,
     124,    5,    5,    5, 0x08,
     138,    5,    5,    5, 0x08,
     151,    5,    5,    5, 0x08,
     163,    5,    5,    5, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_Game[] = {
    "Game\0\0startClicked()\0timerEvent(QTimerEvent*)\0"
    "keyPressEvent(QKeyEvent*)\0"
    "paintEvent(QPaintEvent*)\0checkEvent()\0"
    "restartMenu()\0createEnemy()\0secondMenu()\0"
    "thirdMenu()\0victoryMenu()\0"
};

const QMetaObject Game::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_Game,
      qt_meta_data_Game, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Game::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Game::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Game::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Game))
        return static_cast<void*>(const_cast< Game*>(this));
    return QWidget::qt_metacast(_clname);
}

int Game::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: startClicked(); break;
        case 1: timerEvent((*reinterpret_cast< QTimerEvent*(*)>(_a[1]))); break;
        case 2: keyPressEvent((*reinterpret_cast< QKeyEvent*(*)>(_a[1]))); break;
        case 3: paintEvent((*reinterpret_cast< QPaintEvent*(*)>(_a[1]))); break;
        case 4: checkEvent(); break;
        case 5: restartMenu(); break;
        case 6: createEnemy(); break;
        case 7: secondMenu(); break;
        case 8: thirdMenu(); break;
        case 9: victoryMenu(); break;
        default: ;
        }
        _id -= 10;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
