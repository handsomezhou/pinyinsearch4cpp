#include <QHBoxLayout>
#include <QVBoxLayout>
#include "T9KeyboardWidget.h"


static QString IMAGE_NUM0_IC1_RESOURCE_PATH = ":/pinyinsearchdemo/res/image/num0_ic1.png";
const static QChar DIAL_NUM_1='1';
const static QChar DIAL_NUM_2='2';
const static QChar DIAL_NUM_3='3';
const static QChar DIAL_NUM_4='4';
const static QChar DIAL_NUM_5='5';
const static QChar DIAL_NUM_6='6';
const static QChar DIAL_NUM_7='7';
const static QChar DIAL_NUM_8='8';
const static QChar DIAL_NUM_9='9';
const static QChar DIAL_NUM_0='0';
const static QChar DIAL_NUM_x='*';
const static QChar DIAL_NUM_j='#';
const static QChar DIAL_NUM_plus='+';
const static QChar DIAL_NUM_comma=',';
const static QChar DIAL_NUM_semicolon=';';

T9KeyboardWidget::T9KeyboardWidget(QWidget *parent): QWidget(parent)
{
    this->mDeleteBtn.setText("Delete");//delete
    this->mDialNum1.setText("1\n");
    this->mDialNum2.setText("2\nABC");
    this->mDialNum3.setText("3\nDEF");
    this->mDialNum4.setText("4\nGHI");
    this->mDialNum5.setText("5\nJKL");
    this->mDialNum6.setText("6\nMNO");
    this->mDialNum7.setText("7\nPQRS");
    this->mDialNum8.setText("8\nTUV");
    this->mDialNum9.setText("9\nWXYZ");
    this->mDialNum0.setText("0\n+");
    this->mDialx.setText("*\n,");
    this->mDialj.setText("#\n;");

    QVBoxLayout *vT9KeyboardWidget=new QVBoxLayout();

    QHBoxLayout *hInputBoxLayout=new QHBoxLayout();
    this->mInputTextEdit.setEnabled(false);


    hInputBoxLayout->addWidget(&this->mInputTextEdit);
    hInputBoxLayout->addWidget(&this->mDeleteBtn);

    QVBoxLayout *vT9KeyBoard=new QVBoxLayout();

    QHBoxLayout *hFirstBoxLayout = new QHBoxLayout();
    hFirstBoxLayout->addWidget(&this->mDialNum1);
    hFirstBoxLayout->addWidget(&this->mDialNum2);
    hFirstBoxLayout->addWidget(&this->mDialNum3);

    QHBoxLayout *hSecondBoxLayout = new QHBoxLayout();
    hSecondBoxLayout->addWidget(&this->mDialNum4);
    hSecondBoxLayout->addWidget(&this->mDialNum5);
    hSecondBoxLayout->addWidget(&this->mDialNum6);

    QHBoxLayout *hThirdBoxLayout = new QHBoxLayout();
    hThirdBoxLayout->addWidget(&this->mDialNum7);
    hThirdBoxLayout->addWidget(&this->mDialNum8);
    hThirdBoxLayout->addWidget(&this->mDialNum9);

    QHBoxLayout *hFourthBoxLayout = new QHBoxLayout();
    hFourthBoxLayout->addWidget(&this->mDialx);
    hFourthBoxLayout->addWidget(&this->mDialNum0);
    hFourthBoxLayout->addWidget(&this->mDialj);

    vT9KeyBoard->addLayout(hFirstBoxLayout);
    vT9KeyBoard->addLayout(hSecondBoxLayout);
    vT9KeyBoard->addLayout(hThirdBoxLayout);
    vT9KeyBoard->addLayout(hFourthBoxLayout);

    vT9KeyboardWidget->addLayout(hInputBoxLayout);
    vT9KeyboardWidget->addLayout(vT9KeyBoard);
    this->setLayout(vT9KeyboardWidget);

    this->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
//QLineEdit::textChanged()
    connect(&mInputTextEdit,SIGNAL(textChanged()),this,SLOT(slot_InputTextEditTextChanged()));

    connect(&mDeleteBtn,SIGNAL(clicked()), this, SLOT(slot_deleteBtnClicked()));
    connect(&mDialNum1, SIGNAL(clicked()), this, SLOT(slot_dialNum1Clicked()));
    connect(&mDialNum2, SIGNAL(clicked()), this, SLOT(slot_dialNum2Clicked()));
    connect(&mDialNum3, SIGNAL(clicked()), this, SLOT(slot_dialNum3Clicked()));
    connect(&mDialNum4, SIGNAL(clicked()), this, SLOT(slot_dialNum4Clicked()));
    connect(&mDialNum5, SIGNAL(clicked()), this, SLOT(slot_dialNum5Clicked()));
    connect(&mDialNum6, SIGNAL(clicked()), this, SLOT(slot_dialNum6Clicked()));
    connect(&mDialNum7, SIGNAL(clicked()), this, SLOT(slot_dialNum7Clicked()));
    connect(&mDialNum8, SIGNAL(clicked()), this, SLOT(slot_dialNum8Clicked()));
    connect(&mDialNum9, SIGNAL(clicked()), this, SLOT(slot_dialNum9Clicked()));
    connect(&mDialNum0, SIGNAL(clicked()), this, SLOT(slot_dialNum0Clicked()));
    //connect(&mDialNum0, SIGNAL(pressed()), this, SLOT(slot_dialNum0Pressed()));
    connect(&mDialx, SIGNAL(clicked()), this, SLOT(slot_dialxClicked()));
    //connect(&mDialx, SIGNAL(pressed()), this, SLOT(slot_dialxPressed()));
    connect(&mDialj, SIGNAL(clicked()), this, SLOT(slot_dialjClicked()));
    //connect(&mDialj, SIGNAL(pressed()), this, SLOT(slot_dialjPressed()));

}

void T9KeyboardWidget::addChar(QChar ch)
{
    mInputTextEdit.setText(mInputTextEdit.toPlainText()+ch);
}

void T9KeyboardWidget::slot_InputTextEditTextChanged()
{
    emit signals_InputTextEditText(mInputTextEdit.toPlainText());

}

void T9KeyboardWidget::slot_deleteBtnClicked()
{
    QString curInputStr=mInputTextEdit.toPlainText();
    if(curInputStr.length()>0){
        mInputTextEdit.setText(curInputStr.mid(0,curInputStr.length()-1));
    }
}

void T9KeyboardWidget::slot_dialNum1Clicked()
{
    this->addChar(DIAL_NUM_1);
    qDebug()<<"1";

}

void T9KeyboardWidget::slot_dialNum2Clicked()
{
    this->addChar(DIAL_NUM_2);
    qDebug()<<"2";
}

void T9KeyboardWidget::slot_dialNum3Clicked()
{
    this->addChar(DIAL_NUM_3);
    qDebug()<<"3";
}

void T9KeyboardWidget::slot_dialNum4Clicked()
{
    this->addChar(DIAL_NUM_4);
    qDebug()<<"4";
}

void T9KeyboardWidget::slot_dialNum5Clicked()
{
    this->addChar(DIAL_NUM_5);
      qDebug()<<"5";
}

void T9KeyboardWidget::slot_dialNum6Clicked()
{
    this->addChar(DIAL_NUM_6);
    qDebug()<<"6";
}

void T9KeyboardWidget::slot_dialNum7Clicked()
{
    this->addChar(DIAL_NUM_7);
    qDebug()<<"7";
}

void T9KeyboardWidget::slot_dialNum8Clicked()
{
    this->addChar(DIAL_NUM_8);
    qDebug()<<"8";
}

void T9KeyboardWidget::slot_dialNum9Clicked()
{
    this->addChar(DIAL_NUM_9);
    qDebug()<<"9";
}

void T9KeyboardWidget::slot_dialNum0Clicked()
{
    this->addChar(DIAL_NUM_0);
    qDebug()<<"0";
}

void T9KeyboardWidget::slot_dialNum0Pressed()
{
    this->addChar(DIAL_NUM_plus);
    qDebug()<<"+";
}

void T9KeyboardWidget::slot_dialxClicked()
{
    this->addChar(DIAL_NUM_x);
    qDebug()<<"x";
}

void T9KeyboardWidget::slot_dialxPressed()
{
    this->addChar(DIAL_NUM_comma);
    qDebug()<<",";
}

void T9KeyboardWidget::slot_dialjClicked()
{
    this->addChar(DIAL_NUM_j);
    qDebug()<<"#";
}

void T9KeyboardWidget::slot_dialjPressed()
{
    this->addChar(DIAL_NUM_semicolon);
     qDebug()<<";";
}
