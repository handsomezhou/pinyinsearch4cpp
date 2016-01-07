#ifndef CONTACTSHELPER_H
#define CONTACTSHELPER_H
#include <QList>
#include "Contacts.h"

class ContactsHelper
{
public:
    ContactsHelper();
    ~ContactsHelper();
    static ContactsHelper* getInstance();
    void loadContacts();
    QList<Contacts> *getBaseContacts() const;
    void setBaseContacts(QList<Contacts> *baseContacts);

private:
    static ContactsHelper* instance;
    QList <Contacts>* baseContacts;
    void initContactsHelper();
    void freeContactsHelper();

};
#endif // CONTACTSHELPER_H
