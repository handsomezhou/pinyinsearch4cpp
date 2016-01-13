#include "ContactsListModel.h"


ContactsListModel::ContactsListModel(QObject *parent)
{
    this->m_pContacts=new QList<Contacts>();
}

ContactsListModel::ContactsListModel(const QList<Contacts> *pContacts, QObject *parent)
{
    this->m_pContacts=new QList<Contacts>();

    // this->m_pContacts=pContacts;
    //this->m_pContacts->fromVector(pContacts);
}

QVariant ContactsListModel::data(const QModelIndex &index, int role) const
{

}

int ContactsListModel::rowCount(const QModelIndex &parent) const
{

}

bool ContactsListModel::setData(const QModelIndex &index, const QVariant &value, int role)
{

}
