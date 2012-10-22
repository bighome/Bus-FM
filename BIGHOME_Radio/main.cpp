#include <QtGui/QApplication>
#include <QTextCodec>
#include <QDesktopWidget>
#include "bighome_radio.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QTextCodec::setCodecForTr(QTextCodec::codecForName("system"));
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("system"));
    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("system"));
    QDesktopWidget *post = QApplication::desktop();

    BIGHOME_Radio w;
    w.show();
    w.move(post->width() - w.width()- 30, 30);
    return a.exec();
}