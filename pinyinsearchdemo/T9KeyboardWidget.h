#ifndef T9KEYBOARDWIDGET_H
#define T9KEYBOARDWIDGET_H

#include <QWidget>

#include <QPushButton>
#include <QTextEdit>
#include <QChar>
#include <QtGui>

class T9KeyboardWidget : public QWidget
{
    Q_OBJECT
public:
    explicit T9KeyboardWidget(QWidget *parent);
    QTextEdit mInputTextEdit;

    QPushButton mDeleteBtn;
    QPushButton mDialNum1;
    QPushButton mDialNum2;
    QPushButton mDialNum3;
    QPushButton mDialNum4;
    QPushButton mDialNum5;
    QPushButton mDialNum6;
    QPushButton mDialNum7;
    QPushButton mDialNum8;
    QPushButton mDialNum9;
    QPushButton mDialNum0;
    QPushButton mDialx;
    QPushButton mDialj;
private:
    void addChar(QChar ch);
signals:
    void signals_InputTextEditText(const QString &);
public slots:
    void slot_InputTextEditTextChanged();
    void slot_deleteBtnClicked();
    void slot_dialNum1Clicked();
    void slot_dialNum2Clicked();
    void slot_dialNum3Clicked();
    void slot_dialNum4Clicked();
    void slot_dialNum5Clicked();
    void slot_dialNum6Clicked();
    void slot_dialNum7Clicked();
    void slot_dialNum8Clicked();
    void slot_dialNum9Clicked();
    void slot_dialNum0Clicked();
    void slot_dialNum0Pressed();
    void slot_dialxClicked();
    void slot_dialxPressed();
    void slot_dialjClicked();
    void slot_dialjPressed();
    //void slot_numberBtnClicked();

};

#endif // T9KEYBOARDWIDGET_H
