#ifndef USER_H
#define USER_H

#include <QString>
#include <QDataStream>

class User
{
public:
    User();
    User(QString name_, QString pass_);
    QString name;
    QString pass;
    friend QDataStream &operator <<(QDataStream &stream, const User &sC);
    friend QDataStream &operator >>(QDataStream &stream, User &sC);
};
inline QDataStream &operator <<(QDataStream &stream,const User &sC)
{
    stream << sC.name;
    stream << sC.pass;
    return stream;
}
inline QDataStream &operator >>(QDataStream &stream, User &sC)
{
    stream >> sC.name;
    stream >> sC.pass;
    return stream;
}

#endif // USER_H
