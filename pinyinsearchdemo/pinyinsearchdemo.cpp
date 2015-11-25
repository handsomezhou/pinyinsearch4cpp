#include <QHBoxLayout>
#include <QDebug>
#include "pinyinsearchdemo.h"

PinyinSearchDemo::PinyinSearchDemo(QWidget *parent)
    : QWidget(parent)
{
    searchTextEdit=new QTextEdit();
    searchBtn=new QPushButton("search");
    connect(searchTextEdit,SIGNAL(textChanged()),this,SLOT(search()));

    QHBoxLayout *inputLayout=new QHBoxLayout;
    inputLayout->addWidget(this->searchTextEdit);
    inputLayout->addWidget(this->searchBtn);

    QVBoxLayout *mainLayout=new QVBoxLayout;
    mainLayout->addLayout(inputLayout);
    setLayout(mainLayout);
}

PinyinSearchDemo::~PinyinSearchDemo()
{

}

void PinyinSearchDemo::search()
{
    QString inputString=this->searchTextEdit->toPlainText();
    if(!inputString.isEmpty()){
       qDebug()<<"["<<inputString<<"]";
    }

}
