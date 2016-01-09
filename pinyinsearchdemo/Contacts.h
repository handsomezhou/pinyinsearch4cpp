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
    PinyinSearchUnit *getNamePinyinSearchUnit() const;
    void setNamePinyinSearchUnit(PinyinSearchUnit *namePinyinSearchUnit);

private:
    PinyinSearchUnit *namePinyinSearchUnit;// save the name converted to Pinyin characters.
};
#endif // CONTACTS_H
