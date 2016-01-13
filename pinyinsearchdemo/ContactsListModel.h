#ifndef CONTACTSLISTMODEL_H
#define CONTACTSLISTMODEL_H
#include <QAbstractListModel>
#include <QList>
#include <Contacts.h>
//http://www.java2s.com/Code/Cpp/Qt/IntmodelforQListView.htm

class  ContactsListModel : public QAbstractListModel{
public:
    ContactsListModel(QObject *parent = 0);
    ContactsListModel(const QList<Contacts> *pContacts, QObject *parent = 0);
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
    int rowCount(const QModelIndex &parent = QModelIndex()) const;
    bool setData(const QModelIndex &index, const QVariant &value, int role = Qt::EditRole);
private:
    QList<Contacts> *m_pContacts=NULL;
};
#endif // CONTACTSLISTMODEL_H
