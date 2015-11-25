#ifndef CONTACTSHELPER_H
#define CONTACTSHELPER_H

class ContactsHelper
{
public:
    ~ContactsHelper();
    static ContactsHelper* getInstance();
private:
    static ContactsHelper* instance;

};
#endif // CONTACTSHELPER_H
