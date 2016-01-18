#ifndef CONTACTS_H
#define CONTACTS_H
#include "BaseContacts.h"
#include "../pinyinsearch/PinyinSearchUnit.h"

enum SearchByType{SearchByNull, SearchByName, SearchByPhoneNumber,};
class Contacts : public BaseContacts
{
public:
    Contacts():BaseContacts(){
        initContacts();
    }
    Contacts(QString id,QString name,QString phoneNumber):BaseContacts(id,name,phoneNumber){
        initContacts();
    }
    QString *getSortKey() const;
    void setSortKey(QString *pSortKey);

    PinyinSearchUnit *getNamePinyinSearchUnit() const;
    void setNamePinyinSearchUnit(PinyinSearchUnit *namePinyinSearchUnit);

    SearchByType getSearchByType();
    void setSearchByType(SearchByType searchByType);

    QString *getMatchKeywords() const;
    void setMatchKeywords(QString *pMatchKeywords);


    int getMatchStartIndex() const;
    void setMatchStartIndex(int matchStartIndex);

    int getMatchLength() const;
    void setMatchLength(int matchLength);

private:
    QString *m_pSortKey;
    PinyinSearchUnit *m_pNamePinyinSearchUnit;// save the name converted to Pinyin characters.
    SearchByType mSearchByType;
    QString *m_pMatchKeywords;  // Used to save the type of Match Keywords.(name or phoneNumber)
    int mMatchStartIndex;       //the match start  position of mMatchKeywords in original string(name or phoneNumber).
    int mMatchLength;           //the match length of mMatchKeywords in original string(name or phoneNumber).
    void initContacts();
};
#endif // CONTACTS_H
