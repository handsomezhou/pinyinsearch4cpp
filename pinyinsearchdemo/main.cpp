#include "pinyinsearchdemo.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    PinyinSearchDemo w;
    w.show();

    return a.exec();
}
