#include <QString>
#include <QDebug>
#include "Contacts.h"
#include "ContactsHelper.h"
#include "../../pinyinsearch/T9Util.h"
#include "../../pinyinsearch/QwertyUtil.h"
#include "../../pinyinsearch/PinyinUtil.h"
#include "../../pinyinsearch/PinyinSearchUnit.h"
#include <QDebug>


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
    for(int i=0;i<8; i++){
        Contacts *cs = new Contacts();
        QString name=(i%2==0)?QString("tony%1苹果香蕉栗子tony").arg(i):QString("西瓜sam%1苹果梨子sam").arg(i);
        QString phoneNumber=QString("0000000000%1").arg(i);
        cs->setName(name);
        cs->setPhoneNumber(phoneNumber);
        cs->getNamePinyinSearchUnit()->setBaseData(cs->getName());//must init base data before parse
        PinyinUtil::parse(*cs->getNamePinyinSearchUnit());
        cs->getNamePinyinSearchUnit()->show();
        m_pBaseContacts->append(cs);
        PinyinSearchUnit *psu=new PinyinSearchUnit();
//        qDebug()<<"getFirstLetter:"<<PinyinUtil::getFirstLetter(*cs->getNamePinyinSearchUnit());
//        qDebug()<<"getFirstCharacter:"<<PinyinUtil::getFirstCharacter(*cs->getNamePinyinSearchUnit());
//        qDebug()<<"getSortKey:"<<PinyinUtil::getSortKey(*cs->getNamePinyinSearchUnit());
        QString str=PinyinUtil::getFirstCharacter(*cs->getNamePinyinSearchUnit());
        QChar chr='k';
        if(NULL!=str){
            chr=str.at(0);
        }
        qDebug()<<"isKanji:"<<"chr["<<chr<<"]"<<PinyinUtil::isKanji(chr);
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
QList<Contacts*> *ContactsHelper::getBaseContacts()
{
    return  this->m_pBaseContacts;
}

void ContactsHelper::setBaseContacts(QList<Contacts*> *pBaseContacts)
{
    this->m_pBaseContacts = pBaseContacts;
}

QList<Contacts*> *ContactsHelper::getSearchContacts() const
{
    return this->m_pSearchContacts;
}

void ContactsHelper::setSearchContacts(QList<Contacts*> *pSearchContacts)
{
    this->m_pSearchContacts=pSearchContacts;
}

QString *ContactsHelper::getFirstNoSearchResultInput()
{
    return this->m_pFirstNoSearchResultInput;
}

void ContactsHelper::setFirstNoSearchResultInput(QString *pFirstNoSearchResultInput)
{
    this->m_pFirstNoSearchResultInput=pFirstNoSearchResultInput;
}




void ContactsHelper::t9Search(QString keyword)
{
    if(NULL==m_pSearchContacts){
        m_pSearchContacts=new QList<Contacts*>;
    }else{
        m_pSearchContacts->clear();
    }

    if(NULL==keyword||keyword.isEmpty()){
        for(int i=0; i<m_pBaseContacts->size(); i++){
            m_pBaseContacts->at(i)->setSearchByType(SearchByNull);
            m_pBaseContacts->at(i)->getMatchKeywords()->clear();
            m_pBaseContacts->at(i)->setMatchStartIndex(-1);
            m_pBaseContacts->at(i)->setMatchLength(0);

            m_pSearchContacts->append(m_pBaseContacts->at(i));
        }

        m_pFirstNoSearchResultInput->clear();
        return;
    }


    if ( m_pFirstNoSearchResultInput->length() > 0) {
            if (keyword.contains(*m_pFirstNoSearchResultInput)) {
                qDebug()<<"no need  to search,null!=keyword,m_pFirstNoSearchResultInput->length()="
                         <<m_pFirstNoSearchResultInput->length()<<"["
                         <<*m_pFirstNoSearchResultInput<<"]"<<";searchlen="<<keyword.length()<<"["<<keyword<<"]";
                return;
            } else {
                qDebug()<<"delete  m_pFirstNoSearchResultInput, null!=keyword,m_pFirstNoSearchResultInput->length()="
                         <<m_pFirstNoSearchResultInput->length()<<"["
                         <<*m_pFirstNoSearchResultInput<<"]"<<";searchlen="<<keyword.length()<<"["<<keyword<<"]";
               m_pFirstNoSearchResultInput->clear();
            }
     }



    /*
     search process:
        1.search by name
        2 search by phoneNumber
    */

    for(int i=0; i<this->m_pBaseContacts->length();i++){
        PinyinSearchUnit *pNamePinyinSearchUnit=ContactsHelper::getInstance()->getBaseContacts()->at(i)->getNamePinyinSearchUnit();
        bool nameMatch=T9Util::match(*pNamePinyinSearchUnit,keyword);
        if(true==nameMatch){
            m_pBaseContacts->at(i)->setSearchByType(SearchByName);
            m_pBaseContacts->at(i)->getMatchKeywords()->clear();
            m_pBaseContacts->at(i)->getMatchKeywords()->append(pNamePinyinSearchUnit->getMatchKeyWord());
            m_pBaseContacts->at(i)->setMatchStartIndex(m_pBaseContacts->at(i)->getName().indexOf(m_pBaseContacts->at(i)->getMatchKeywords()));
            m_pBaseContacts->at(i)->setMatchLength(m_pBaseContacts->at(i)->getMatchKeywords()->length());

            m_pSearchContacts->append(m_pBaseContacts->at(i));

        }else{


            if(true==m_pBaseContacts->at(i)->getPhoneNumber().contains(keyword)){
                m_pBaseContacts->at(i)->setSearchByType(SearchByPhoneNumber);
                m_pBaseContacts->at(i)->getMatchKeywords()->clear();
                m_pBaseContacts->at(i)->getMatchKeywords()->append(keyword);
                int matchStartIndex=m_pBaseContacts->at(i)->getPhoneNumber().indexOf(keyword);
                m_pBaseContacts->at(i)->setMatchStartIndex(matchStartIndex);
                m_pBaseContacts->at(i)->setMatchLength(keyword.length());
                m_pSearchContacts->append(m_pBaseContacts->at(i));
            }

        }
    }

    if(m_pSearchContacts->size()<=0){
        if (m_pSearchContacts->length() <= 0) {
            m_pFirstNoSearchResultInput->append(keyword);
            qDebug()<<"no search result,null!=search,mFirstNoSearchResultInput.length()="
                   <<m_pFirstNoSearchResultInput->length()<<"["
                   <<*m_pFirstNoSearchResultInput<<"]"<<";searchlen="<<keyword.length()<<"["<<keyword<<"]";
        }
    }else{
        //sort
    }
    return;

    return;
}

void ContactsHelper::qwertySearch(QString keyword)
{
    if(NULL==m_pSearchContacts){
        m_pSearchContacts=new QList<Contacts*>;
    }else{
        m_pSearchContacts->clear();
    }

    if(NULL==keyword||keyword.isEmpty()){
        for(int i=0; i<m_pBaseContacts->size(); i++){
            m_pBaseContacts->at(i)->setSearchByType(SearchByNull);
            m_pBaseContacts->at(i)->getMatchKeywords()->clear();
            m_pBaseContacts->at(i)->setMatchStartIndex(-1);
            m_pBaseContacts->at(i)->setMatchLength(0);

            m_pSearchContacts->append(m_pBaseContacts->at(i));
        }

        m_pFirstNoSearchResultInput->clear();
        return;
    }


    if ( m_pFirstNoSearchResultInput->length() > 0) {
            if (keyword.contains(*m_pFirstNoSearchResultInput)) {
                qDebug()<<"no need  to search,null!=keyword,m_pFirstNoSearchResultInput->length()="
                         <<m_pFirstNoSearchResultInput->length()<<"["
                         <<*m_pFirstNoSearchResultInput<<"]"<<";searchlen="<<keyword.length()<<"["<<keyword<<"]";
                return;
            } else {
                qDebug()<<"delete  m_pFirstNoSearchResultInput, null!=keyword,m_pFirstNoSearchResultInput->length()="
                         <<m_pFirstNoSearchResultInput->length()<<"["
                         <<*m_pFirstNoSearchResultInput<<"]"<<";searchlen="<<keyword.length()<<"["<<keyword<<"]";
               m_pFirstNoSearchResultInput->clear();
            }
     }



    /*
     search process:
        1.search by name
        2 search by phoneNumber
    */

    for(int i=0; i<this->m_pBaseContacts->length();i++){
        PinyinSearchUnit *pNamePinyinSearchUnit=ContactsHelper::getInstance()->getBaseContacts()->at(i)->getNamePinyinSearchUnit();
        bool nameMatch=QwertyUtil::match(*pNamePinyinSearchUnit,keyword);
        qDebug()<<"is nameMatch:"<<nameMatch;
        if(true==nameMatch){
            m_pBaseContacts->at(i)->setSearchByType(SearchByName);
            m_pBaseContacts->at(i)->getMatchKeywords()->clear();
            m_pBaseContacts->at(i)->getMatchKeywords()->append(pNamePinyinSearchUnit->getMatchKeyWord());
            m_pBaseContacts->at(i)->setMatchStartIndex(m_pBaseContacts->at(i)->getName().indexOf(m_pBaseContacts->at(i)->getMatchKeywords()));
            m_pBaseContacts->at(i)->setMatchLength(m_pBaseContacts->at(i)->getMatchKeywords()->length());

            m_pSearchContacts->append(m_pBaseContacts->at(i));

        }else{


            if(true==m_pBaseContacts->at(i)->getPhoneNumber().contains(keyword)){
                m_pBaseContacts->at(i)->setSearchByType(SearchByPhoneNumber);
                m_pBaseContacts->at(i)->getMatchKeywords()->clear();
                m_pBaseContacts->at(i)->getMatchKeywords()->append(keyword);
                int matchStartIndex=m_pBaseContacts->at(i)->getPhoneNumber().indexOf(keyword);
                qDebug()<<"matchStartIndex "<<matchStartIndex;
                m_pBaseContacts->at(i)->setMatchStartIndex(matchStartIndex);
                m_pBaseContacts->at(i)->setMatchLength(keyword.length());
                m_pSearchContacts->append(m_pBaseContacts->at(i));
            }

        }
    }

    if(m_pSearchContacts->size()<=0){
        if (m_pSearchContacts->length() <= 0) {
            m_pFirstNoSearchResultInput->append(keyword);
            qDebug()<<"no search result,null!=search,mFirstNoSearchResultInput.length()="
                   <<m_pFirstNoSearchResultInput->length()<<"["
                   <<*m_pFirstNoSearchResultInput<<"]"<<";searchlen="<<keyword.length()<<"["<<keyword<<"]";
        }
    }else{
        //sort
    }
    return;


}



void ContactsHelper::initContactsHelper()
{
    if(NULL==m_pBaseContacts){
        m_pBaseContacts=new QList<Contacts*>;
    }

    if(NULL==m_pSearchContacts){
        m_pSearchContacts=new QList<Contacts*>;
    }

    if(NULL==m_pFirstNoSearchResultInput){
        m_pFirstNoSearchResultInput=new QString();
    }
    // qDebug()<<"["<<"initContactsHelper"<<"]";
}

void ContactsHelper::freeContactsHelper()
{
    if(NULL!=m_pBaseContacts){
        m_pBaseContacts->clear();
        //qDeleteAll(baseContacts)
        m_pBaseContacts=NULL;
    }
    //qDebug()<<"["<<"freeContactsHelper"<<"]";
}
