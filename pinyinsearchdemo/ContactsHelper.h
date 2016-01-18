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

    QList<Contacts*> *getBaseContacts();
    void setBaseContacts(QList<Contacts*> *pBaseContacts);

    QList<Contacts*> *getSearchContacts() const;
    void setSearchContacts(QList<Contacts*> *pSearchContacts);

    QString *getFirstNoSearchResultInput() ;
    void setFirstNoSearchResultInput(QString *pFirstNoSearchResultInput);

    void t9Search(QString keyword);
    void qwertySearch(QString keyword);


private:
    static ContactsHelper* instance;
    QList <Contacts*> *m_pBaseContacts=NULL;
    QList <Contacts*> *m_pSearchContacts=NULL;
    QString *m_pFirstNoSearchResultInput=NULL;
    void initContactsHelper();
    void freeContactsHelper();

};
#endif // CONTACTSHELPER_H
