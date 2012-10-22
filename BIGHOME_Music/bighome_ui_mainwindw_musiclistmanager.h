#ifndef BIGHOME_UI_MAINWINDW_MUSICLISTMANAGER_H
#define BIGHOME_UI_MAINWINDW_MUSICLISTMANAGER_H

#include <QWidget>
#include <QDockWidget>
#include <QStringList>
#include "ui_bighome_ui_mainwindw_musiclistmanager.h"

class BIGHOME_UI_MainWindw_MusicListManager : public QDockWidget
{
    Q_OBJECT

public:
  static BIGHOME_UI_MainWindw_MusicListManager *getInterFace();
    ~BIGHOME_UI_MainWindw_MusicListManager();
    void setMainWindowPos(int x, int y);
    bool getMusicListWindowOpen();
    void setMusicListWindowOpen(bool vlaue);
    void setMusicAdditems(QStringList value);
    void setMusicListAdditems(QStringList value);
private:
  BIGHOME_UI_MainWindw_MusicListManager(QWidget *parent = 0);
    void init();
    void setStyle();
    void paintEvent(QPaintEvent *event);
    void mousePressEvent(QMouseEvent *event);

private:
    Ui::BIGHOME_UI_MainWindw_MusicListManagerClass ui;
    static BIGHOME_UI_MainWindw_MusicListManager *s_getInterFace;
    static bool s_OpenList;
    static int s_windowX;
    static int s_windowY;
    int m_windowX;
    QStringList m_testMusicList;
    QStringList M_testMusicList1;
};

#endif // BIGHOME_UI_MAINWINDW_MUSICLISTMANAGER_H
