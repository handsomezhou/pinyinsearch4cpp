#include "Contacts.h"


PinyinSearchUnit *Contacts::getNamePinyinSearchUnit() const
{
    return this->namePinyinSearchUnit;
}

void Contacts::setNamePinyinSearchUnit(PinyinSearchUnit *namePinyinSearchUnit)
{
    this->namePinyinSearchUnit = namePinyinSearchUnit;
}
