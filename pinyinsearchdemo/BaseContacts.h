#ifndef BASECONTACTS_H
#define BASECONTACTS_H
#include <QString>

class BaseContacts{
public:
    BaseContacts();
    BaseContacts(QString id,QString name,QString phoneNumber);
    QString getId() const;
    void setId(const QString &id);

    QString getName() const;
    void setName(const QString &name);

    QString getPhoneNumber() const;
    void setPhoneNumber(const QString &phoneNumber);

private:
    QString id;
    QString name;
    QString phoneNumber;

};
#endif // BASECONTACTS_H
