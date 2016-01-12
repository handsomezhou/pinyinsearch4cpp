#include <QHBoxLayout>
#include <QDebug>
#include "pinyinsearchdemo.h"
#include "ContactsHelper.h"
#include "T9KeyboardWidget.h"

PinyinSearchDemo::PinyinSearchDemo(QWidget *parent)
    : QWidget(parent)
{
    ContactsHelper::getInstance()->loadContacts();

    searchTextEdit=new QTextEdit();

    qwertySearchBtn=new QPushButton("qwerty search");
    connect(searchTextEdit,SIGNAL(textChanged()),this,SLOT(qwertySearch()));

    QHBoxLayout *inputLayout=new QHBoxLayout;
    T9KeyboardWidget *t9KeyboardWidget=new T9KeyboardWidget(this);
    //connect(t9KeyboardWidget, SIGNAL(s_nameText(const QString &)), this, SLOT(slot_nameClicked(const QString &)));
    connect(t9KeyboardWidget, SIGNAL(signals_InputTextEditText(const QString &)), this, SLOT(t9Search(const QString &)));

    inputLayout->addWidget(t9KeyboardWidget);
    inputLayout->addWidget(this->searchTextEdit);
    inputLayout->addWidget(this->qwertySearchBtn);

    QVBoxLayout *mainLayout=new QVBoxLayout;
    mainLayout->addLayout(inputLayout);
    setLayout(mainLayout);
}

PinyinSearchDemo::~PinyinSearchDemo()
{

}

void PinyinSearchDemo::t9Search(const QString &keyword)
{
    qDebug()<<"t9Search["<<keyword<<"]";
    ContactsHelper::getInstance()->t9Search(keyword);

}

void PinyinSearchDemo::qwertySearch()
{
    QString inputString=this->searchTextEdit->toPlainText();
    if(!inputString.isEmpty()){
       qDebug()<<"["<<inputString<<"]";
    }

    ContactsHelper::getInstance()->qwertySearch(inputString);

}


void PinyinSearchDemo::slot_inputTextEditText(const QString &inputText)
{
     qDebug()<<"..........inputText:"<<inputText;
}

