#ifndef PINYINSEARCHDEMO_H
#define PINYINSEARCHDEMO_H

#include <QWidget>
#include <QPushButton>
#include <QTextEdit>

class PinyinSearchDemo : public QWidget
{
    Q_OBJECT

public:
    PinyinSearchDemo(QWidget *parent = 0);
    ~PinyinSearchDemo();
private slots:
    void t9Search();
    void qwertySearch();
private:
    QTextEdit *searchTextEdit;
    QPushButton *t9SearchBtn;
    QPushButton *qwertySearchBtn;
};

#endif // PINYINSEARCHDEMO_H
