#include "BaseContacts.h"

BaseContacts::BaseContacts()
{

}

BaseContacts::BaseContacts(QString id, QString name, QString phoneNumber)
{
    this->id=id;
    this->name=name;
    this->phoneNumber=phoneNumber;
}

QString BaseContacts::getId() const
{
    return this->id;
}

void BaseContacts::setId(const QString &id)
{
    this->id = id;
}

QString BaseContacts::getName() const
{
    return this->name;
}

void BaseContacts::setName(const QString &name)
{
    this->name = name;
}

QString BaseContacts::getPhoneNumber() const
{
    return this->phoneNumber;
}

void BaseContacts::setPhoneNumber(const QString &phoneNumber)
{
    this->phoneNumber = phoneNumber;
}


