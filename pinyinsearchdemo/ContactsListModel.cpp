#include "ContactsListModel.h"


ContactsListModel::ContactsListModel(QObject *parent)
{
    this->m_pContacts=new QList<Contacts>();
}

ContactsListModel::ContactsListModel(QList<Contacts> *pContacts, QObject *parent)
{
    this->m_pContacts=pContacts;

    // this->m_pContacts=pContacts;
    //this->m_pContacts->fromVector(pContacts);
}

QVariant ContactsListModel::data(const QModelIndex &index, int role) const
{
    if( role != Qt::DisplayRole && role != Qt::EditRole )
       return QVariant();

     if( index.column() == 0 && index.row() <  this->m_pContacts->count() )
       return &this->m_pContacts->at(index.row());
     else
       return QVariant();
}

int ContactsListModel::rowCount(const QModelIndex &parent) const
{
    return this->m_pContacts->count();
}

bool ContactsListModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if( role != Qt::EditRole || index.column() != 0 || index.row() >= this->m_pContacts->count() )
        return false;
/*
      if( value.toInt() == this->m_pContacts->at( index.row() ) )
        return false;

      this->m_pContacts->at(index.row()) = value.toInt();

      emit dataChanged( index, index );
      */
      return true;
}

QList<Contacts> *ContactsListModel::getContacts() const
{
    return this->m_pContacts;
}

void ContactsListModel::setContacts(QList<Contacts> *pContacts)
{
    this->m_pContacts=pContacts;
}

