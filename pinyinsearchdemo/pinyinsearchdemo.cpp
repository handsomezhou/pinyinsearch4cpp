#include <QHBoxLayout>
#include <QDebug>
#include "pinyinsearchdemo.h"
#include "ContactsHelper.h"

PinyinSearchDemo::PinyinSearchDemo(QWidget *parent)
    : QWidget(parent)
{
    ContactsHelper::getInstance()->loadContacts();

    searchTextEdit=new QTextEdit();
    t9SearchBtn=new QPushButton("t9 search");
    connect(searchTextEdit,SIGNAL(textChanged()),this,SLOT(t9Search()));

    qwertySearchBtn=new QPushButton("qwerty search");
    connect(searchTextEdit,SIGNAL(textChanged()),this,SLOT(qwertySearch()));

    QHBoxLayout *inputLayout=new QHBoxLayout;
    inputLayout->addWidget(this->searchTextEdit);
    inputLayout->addWidget(this->t9SearchBtn);
    inputLayout->addWidget(this->qwertySearchBtn);

    QVBoxLayout *mainLayout=new QVBoxLayout;
    mainLayout->addLayout(inputLayout);
    setLayout(mainLayout);
}

PinyinSearchDemo::~PinyinSearchDemo()
{

}

void PinyinSearchDemo::t9Search()
{
    QString inputString=this->searchTextEdit->toPlainText();
    if(!inputString.isEmpty()){
       qDebug()<<"["<<inputString<<"]";
    }

    ContactsHelper::getInstance()->t9Search(inputString);

}

void PinyinSearchDemo::qwertySearch()
{
    QString inputString=this->searchTextEdit->toPlainText();
    if(!inputString.isEmpty()){
       qDebug()<<"["<<inputString<<"]";
    }

    ContactsHelper::getInstance()->qwertySearch(inputString);

}
