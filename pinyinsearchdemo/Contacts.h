#ifndef CONTACTS_H
#define CONTACTS_H
#include "BaseContacts.h"
#include "../pinyinsearch/PinyinSearchUnit.h"
class Contacts : public BaseContacts
{
public:
    Contacts():BaseContacts(){
        namePinyinSearchUnit=new PinyinSearchUnit();
    }
    Contacts(QString id,QString name,QString phoneNumber):BaseContacts(id,name,phoneNumber){
        namePinyinSearchUnit=new PinyinSearchUnit();
    }
private:
    PinyinSearchUnit *namePinyinSearchUnit;// save the mName converted to Pinyin characters.
};
#endif // CONTACTS_H
