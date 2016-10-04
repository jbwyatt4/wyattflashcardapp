#ifndef MISC_H
#define MISC_H

#include <QString>

#define JW_DEBUG
//#define DEMO

class Misc
{
public:
    Misc();
    static QString trimAndLower(const QString &s);
    static QString version();
    static QString app_name();
};

#endif // MISC_H
