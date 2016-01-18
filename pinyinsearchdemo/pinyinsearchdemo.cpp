#include <QHBoxLayout>
#include <QDebug>
#include "pinyinsearchdemo.h"
#include "ContactsHelper.h"
#include "T9KeyboardWidget.h"

#include <QListView>
#include <QStringListModel>

PinyinSearchDemo::PinyinSearchDemo(QWidget *parent)
    : QWidget(parent)
{
    ContactsHelper::getInstance()->loadContacts();

    this->m_pBaseData=new QString();
    this->m_pSearchData=new QString();

    this->m_pT9KeyboardWidget=new T9KeyboardWidget(this);
    this->m_pQwertySearchTextEdit=new QTextEdit();
    this->m_pBaseDataLabel=new QLabel();
    this->m_pSearchDataLabel=new QLabel();

    int baseDataCount=ContactsHelper::getInstance()->getBaseContacts()->count();

    for(int i=0; i<baseDataCount; i++){
         this->m_pBaseData->append(ContactsHelper::getInstance()->getBaseContacts()->at(i)->getName()).append("\n");
         this->m_pBaseData->append(ContactsHelper::getInstance()->getBaseContacts()->at(i)->getPhoneNumber()).append("\n\n");
    }
    this->m_pBaseDataLabel->setText((*this->m_pBaseData));
    connect(m_pQwertySearchTextEdit,SIGNAL(textChanged()),this,SLOT(qwertySearch()));
    connect(this->m_pT9KeyboardWidget, SIGNAL(signals_InputTextEditText(const QString &)), this, SLOT(t9Search(const QString &)));



    QHBoxLayout *inputLayout=new QHBoxLayout;
    inputLayout->addWidget(this->m_pT9KeyboardWidget);
    inputLayout->addWidget(this->m_pQwertySearchTextEdit);

    QHBoxLayout *dataListLayout=new QHBoxLayout;
    dataListLayout->addWidget(this->m_pBaseDataLabel);
    dataListLayout->addWidget(this->m_pSearchDataLabel);

    QVBoxLayout *mainLayout=new QVBoxLayout;
    mainLayout->addLayout(inputLayout);
    mainLayout->addLayout(dataListLayout);


    setLayout(mainLayout);
}

PinyinSearchDemo::~PinyinSearchDemo()
{

}

void PinyinSearchDemo::t9Search(const QString &keyword)
{
    qDebug()<<"t9Search["<<keyword<<"]";
    ContactsHelper::getInstance()->t9Search(keyword);
    this->refreshSearchData();
}

void PinyinSearchDemo::qwertySearch()
{
    QString inputString=this->m_pQwertySearchTextEdit->toPlainText();
    if(!inputString.isEmpty()){
       qDebug()<<"["<<inputString<<"]";
    }

    ContactsHelper::getInstance()->qwertySearch(inputString);
    this->refreshSearchData();

}


void PinyinSearchDemo::slot_inputTextEditText(const QString &inputText)
{
    qDebug()<<"..........inputText:"<<inputText;
}

void PinyinSearchDemo::refreshSearchData()
{
    if(NULL==this->m_pSearchData){
        this->m_pSearchData=new QString();
    }else{
        this->m_pSearchData->clear();
    }

    int searchDataCount=ContactsHelper::getInstance()->getSearchContacts()->size();
    for(int i=0; i<searchDataCount; i++){
         this->m_pSearchData->append(ContactsHelper::getInstance()->getSearchContacts()->at(i)->getName()).append("\n");
         this->m_pSearchData->append(ContactsHelper::getInstance()->getSearchContacts()->at(i)->getPhoneNumber()).append("\n");

        this->m_pSearchData->append("match keyword[");
        this->m_pSearchData->append(ContactsHelper::getInstance()->getSearchContacts()->at(i)->getMatchKeywords());
        this->m_pSearchData->append("]");

        this->m_pSearchData->append("SearchByType[");
        QString searchByType=NULL;
        if(ContactsHelper::getInstance()->getSearchContacts()->at(i)->getSearchByType()==SearchByName){
            searchByType="SearchByName";
        }else if(ContactsHelper::getInstance()->getSearchContacts()->at(i)->getSearchByType()==SearchByPhoneNumber){
             searchByType="SearchByPhoneNumber";
        }else{
            searchByType="SearchByNull";
        }
        this->m_pSearchData->append(searchByType);
        this->m_pSearchData->append("][");

        QString matchStartIndex=QString::number(ContactsHelper::getInstance()->getSearchContacts()->at(i)->getMatchStartIndex(),10);
        this->m_pSearchData->append(matchStartIndex);
        this->m_pSearchData->append("][");
        QString matchLength=QString::number(ContactsHelper::getInstance()->getSearchContacts()->at(i)->getMatchLength(),10);
        this->m_pSearchData->append(matchLength);
        this->m_pSearchData->append("]");


        this->m_pSearchData->append("\n\n");

//         this->m_pSearchData->append(ContactsHelper::getInstance()->getSearchContacts()->at(i).getNamePinyinSearchUnit()->)
    }

    this->m_pSearchDataLabel->setText(*this->m_pSearchData);
}

