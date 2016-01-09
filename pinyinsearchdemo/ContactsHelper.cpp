#include <QString>
#include <QDebug>
#include "Contacts.h"
#include "ContactsHelper.h"
#include "../../pinyinsearch/T9Util.h"
#include "../../pinyinsearch/PinyinUtil.h"
#include "../../pinyinsearch/PinyinSearchUnit.h"


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
    for(int i=0;i<1; i++){
        Contacts cs;
        //QString name=QString("test周俊tO%1权").arg(i);
        QString name=QString("test周I俊tony%1").arg(i);
        QString phoneNumber=QString("0000000000%1").arg(i);
        cs.setName(name);
        cs.setPhoneNumber(phoneNumber);
        cs.getNamePinyinSearchUnit()->setBaseData(cs.getName());//must init base data before parse
        PinyinUtil::parse(*cs.getNamePinyinSearchUnit());
        cs.getNamePinyinSearchUnit()->show();
        baseContacts->append(cs);
    }

    /*
    for(int i=0;i<10; i++){
        Contacts cs;
        QString name=QString("tony%1").arg(i);
        QString phoneNumber=QString("1000000000%1").arg(i);
        cs.setName(name);
        cs.setPhoneNumber(phoneNumber);

        baseContacts->append(cs);
    }

    for(int i=0;i<10; i++){
        Contacts cs;
        QString name=QString("sam%1").arg(i);
        QString phoneNumber=QString("2000000000%1").arg(i);
        cs.setName(name);
        cs.setPhoneNumber(phoneNumber);

        baseContacts->append(cs);
    }
    */
}
QList<Contacts> *ContactsHelper::getBaseContacts() const
{
    return baseContacts;
}

void ContactsHelper::setBaseContacts(QList<Contacts> *baseContacts)
{
    this->baseContacts = baseContacts;
}

void ContactsHelper::t9Search(QString keyword)
{
    qDebug()<<"t9Search keyword["<<keyword<<"]";
    for(int i=0; i<this->baseContacts->length();i++){
        PinyinSearchUnit *namePinyinSearchUnit=this->getBaseContacts()->at(i).getNamePinyinSearchUnit();
        bool nameMatch=T9Util::match(*namePinyinSearchUnit,keyword);
        qDebug()<<"nameMatch:"<<nameMatch;
        if(true==nameMatch){

        }else{

        }
    }
    return;
}

void ContactsHelper::qwertySearch(QString keyword)
{
    qDebug()<<"qwertySearch keyword["<<keyword<<"]";
    return;
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
