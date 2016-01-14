#include "pinyinsearchdemo.h"
#include "Contacts.h"
#include <QApplication>
#include <QListView>
#include <QStringListModel>
#include <QDebug>
#include "ContactsListModel.h"
#include "../../pinyinsearch/T9Util.h"
#include "../../pinyinsearch/QwertyUtil.h"
#include "../../pinyinsearch/PinyinUtil.h"
#include "../../pinyinsearch/PinyinSearchUnit.h"
#include "ContactsItemDelegate.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//    PinyinSearchDemo w;
//    w.show();

    QListView list;

    QList<Contacts> *pContacts=new QList<Contacts>();
    for(int i=0;i<20; i++){
        Contacts cs;
        //QString name=QString("test周俊tO%1权").arg(i);
        QString name=QString("test周I俊tony%1").arg(i);
        QString phoneNumber=QString("0000000000%1").arg(i);
        cs.setName(name);
        cs.setPhoneNumber(phoneNumber);
//        cs.getNamePinyinSearchUnit()->setBaseData(cs.getName());//must init base data before parse
//        PinyinUtil::parse(*cs.getNamePinyinSearchUnit());
       // cs.getNamePinyinSearchUnit()->show();
        qDebug()<<"name["<<cs.getName()<<"]number["+cs.getPhoneNumber()<<"]";

        pContacts->append(cs);
    }

    ContactsListModel contactsListModel;
    contactsListModel.setContacts(pContacts);
    list.setModel( &contactsListModel );


    list.setItemDelegate(new ContactsItemDelegate());
    list.show();

     QStringListModel model;
    /*
    QStringListModel model;
    QStringList strings;
    strings << "foo" << "bar" << "baz";
    model.setStringList( strings );
    list.setModel( &model );
    list.show();
    */

    return a.exec();
}
