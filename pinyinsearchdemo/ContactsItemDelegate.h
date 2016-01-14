#ifndef CONTACTSITEMDELEGATE_H
#define CONTACTSITEMDELEGATE_H
#include <QStyledItemDelegate>

class ContactsItemDelegate: public QStyledItemDelegate {
    Q_OBJECT
public:
    ContactsItemDelegate(QObject *parent = 0);
    // painting
    void paint(QPainter *painter,const QStyleOptionViewItem &option, const QModelIndex &index) const;
    QSize sizeHint(const QStyleOptionViewItem &option,const QModelIndex &index) const;
    // editing
   QWidget *createEditor(QWidget *parent,const QStyleOptionViewItem &option,const QModelIndex &index) const;
   void setEditorData(QWidget *editor, const QModelIndex &index) const;
   void setModelData(QWidget *editor,QAbstractItemModel *model,const QModelIndex &index) const;
};
#endif // CONTACTSITEMDELEGATE_H
