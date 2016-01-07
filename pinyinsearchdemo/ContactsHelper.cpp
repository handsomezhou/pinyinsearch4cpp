#include <QString>
#include <QDebug>
#include "Contacts.h"
#include "ContactsHelper.h"


ContactsHelper* ContactsHelper::instance=NULL;

ContactsHelper::ContactsHelper()
{
    initContactsHelper();
}

ContactsHelper::~ContactsHelper()
{
    if(NULL!=ContactsHelper::instance){
            freeContactsHelper();
           delete ContactsHelper::instance;
    }
}

ContactsHelper *ContactsHelper::getInstance()
{
    if(NULL==ContactsHelper::instance){
           ContactsHelper::instance=new ContactsHelper();
    }

    return ContactsHelper::instance;
}

void ContactsHelper::loadContacts()
{
    Contacts *cs;
    for(int i=0;i<10; i++){
       // cs=new Contacts();
      // Contacts cs;
        /*
        cs.setName("周英俊");
        cs.setPhoneNumber("1234567890");
        */
      //  baseContacts->append(cs);

    }
}
QList<Contacts> *ContactsHelper::getBaseContacts() const
{
    return baseContacts;
}

void ContactsHelper::setBaseContacts(QList<Contacts> *baseContacts)
{
    this->baseContacts = baseContacts;
}


void ContactsHelper::initContactsHelper()
{
    if(NULL==baseContacts){
        baseContacts=new QList<Contacts>;
    }
    // qDebug()<<"["<<"initContactsHelper"<<"]";
}

void ContactsHelper::freeContactsHelper()
{
    if(NULL!=baseContacts){
        baseContacts->clear();
        //qDeleteAll(baseContacts)
        baseContacts=NULL;
    }
    //qDebug()<<"["<<"freeContactsHelper"<<"]";
}
