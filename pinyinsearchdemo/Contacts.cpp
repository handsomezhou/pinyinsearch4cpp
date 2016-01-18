#include "Contacts.h"


QString *Contacts::getSortKey() const
{
    return this->m_pSortKey;
}

void Contacts::setSortKey(QString *pSortKey)
{
    this->m_pSortKey=pSortKey;
}

PinyinSearchUnit *Contacts::getNamePinyinSearchUnit() const
{
    return this->m_pNamePinyinSearchUnit;
}

void Contacts::setNamePinyinSearchUnit(PinyinSearchUnit *namePinyinSearchUnit)
{
    this->m_pNamePinyinSearchUnit = namePinyinSearchUnit;
}

SearchByType Contacts::getSearchByType()
{
    return this->mSearchByType;
}

void Contacts::setSearchByType(SearchByType searchByType)
{
    this->mSearchByType=searchByType;
}

QString *Contacts::getMatchKeywords() const
{
    return  this->m_pMatchKeywords;
}

void Contacts::setMatchKeywords(QString *pMatchKeywords)
{
    this->m_pMatchKeywords=pMatchKeywords;
}

int Contacts::getMatchStartIndex() const
{
    return this->mMatchStartIndex;
}

void Contacts::setMatchStartIndex(int matchStartIndex)
{
    this->mMatchStartIndex=matchStartIndex;
}

int Contacts::getMatchLength() const
{
    return this->mMatchLength;
}

void Contacts::setMatchLength(int matchLength)
{
    this->mMatchLength=matchLength;
}

void Contacts::initContacts()
{
    m_pSortKey=new QString();
    m_pNamePinyinSearchUnit=new PinyinSearchUnit();
    mSearchByType=SearchByNull;
    m_pMatchKeywords=new QString();
    mMatchStartIndex=-1;
    mMatchLength=0;
}
