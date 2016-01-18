#ifndef PINYINSEARCHDEMO_H
#define PINYINSEARCHDEMO_H

#include <QWidget>
#include <QPushButton>
#include <QTextEdit>
#include <QLabel>
#include "T9KeyboardWidget.h"

class PinyinSearchDemo : public QWidget
{
    Q_OBJECT

public:
    PinyinSearchDemo(QWidget *parent = 0);
    ~PinyinSearchDemo();
private slots:
    void t9Search(const QString &keyword);
    void qwertySearch();
    void slot_inputTextEditText(const QString &);
private:
    QString *m_pBaseData;
    QString *m_pSearchData;

    T9KeyboardWidget *m_pT9KeyboardWidget;
    QTextEdit *m_pQwertySearchTextEdit;
    QLabel *m_pBaseDataLabel;
    QLabel *m_pSearchDataLabel;
    void refreshSearchData();


};

#endif // PINYINSEARCHDEMO_H
