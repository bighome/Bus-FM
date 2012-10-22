#include <QtGui/QApplication>
#include <QTextCodec>
#include "networkimgs.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QTextCodec::setCodecForTr(QTextCodec::codecForName("system"));
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("system"));
    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("system"));
    netWorkImgs w;
    //BIGHOME_Music_test w;
    w.show();
    return a.exec();
}
