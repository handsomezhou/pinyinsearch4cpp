#include "ContactsItemDelegate.h"
#include <QApplication>
#include <QStyle>
#include <QTextOption>
#include <QPainter>
#include <QRect>

ContactsItemDelegate::ContactsItemDelegate(QObject *parent)
{

}


void ContactsItemDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    QStyle* style = QApplication::style();
  QRect textRect = style->subElementRect(QStyle::SE_ItemViewItemText, &option);
//     QString text= index.data().toString();
//     QTextOption o(Qt::AlignRight | Qt::AlignVCenter);
//      painter->drawText(option.rect, text, o);
    QString text=QString("TEST");
    painter->drawText(textRect, option.displayAlignment, text);
//    if (index.column() == durationColumn) {
//         int secs = index.model()->data(index, Qt::DisplayRole).toInt();
//         QString text = QString("%1:%2").arg(secs / 60, 2, 10, QChar('0')).arg(secs % 60, 2, 10, QChar('0'));
//         QTextOption o(Qt::AlignRight | Qt::AlignVCenter);
//         painter->drawText(option.rect, text, o);
//     } else {
    //     QStyledItemDelegate::paint(painter, option, index);
   //  }
}


QSize ContactsItemDelegate::sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const
{

}

QWidget *ContactsItemDelegate::createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    return QStyledItemDelegate::createEditor(parent, option, index);
}

void ContactsItemDelegate::setEditorData(QWidget *editor, const QModelIndex &index) const
{
   QStyledItemDelegate::setEditorData(editor, index);
}


void ContactsItemDelegate::setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const
{
     QStyledItemDelegate::setModelData(editor, model, index);
}
