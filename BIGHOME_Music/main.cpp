#include <QtGui/QApplication>
#include <QTextCodec>
#include <QDesktopWidget>
#include "bighome_music_mainwindw.h"
#include "bighome_ui_mainwindw_musiclistmanager.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QTextCodec::setCodecForTr(QTextCodec::codecForName("system"));
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("system"));
    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("system"));
    QDesktopWidget *post = QApplication::desktop();

    int mainWindowWidth = post->width() - BIGHOME_Music_mainWindw::getInterFace()->width() - 100;
    BIGHOME_Music_mainWindw::getInterFace()->show();
    BIGHOME_Music_mainWindw::getInterFace()->move(mainWindowWidth, 100);

    return a.exec();
}
