#include "misc.h"

Misc::Misc()
{
}

QString Misc::trimAndLower(const QString &s) {
    return s.trimmed().toLower();
}

QString Misc::version() {
    //tr does not work with static members
    //https://forum.qt.io/topic/33568/qt-tr-not-working-if-i-am-using-in-static-member/3
    return QString(QT_TR_NOOP("1.0"));
}

QString Misc::app_name() {
    return QString(QT_TR_NOOP("WyattFlashcardApp"));
}
