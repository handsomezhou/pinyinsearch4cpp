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
    void t9Search(QString keyword);
    void qwertySearch(QString keyword);

private:
    static ContactsHelper* instance;
    QList <Contacts>* baseContacts=NULL;
    void initContactsHelper();
    void freeContactsHelper();

};
#endif // CONTACTSHELPER_H
