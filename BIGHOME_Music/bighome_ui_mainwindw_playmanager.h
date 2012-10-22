#ifndef BIGHOME_UI_MAINWINDW_PLAYMANAGER_H
#define BIGHOME_UI_MAINWINDW_PLAYMANAGER_H

#include <QWidget>
#include <QPainter>
#include <QMap>
#include <QPixmap>
#include "ui_bighome_ui_mainwindw_playmanager.h"
#include "bighome_ui_palymanager.h"
#include "bighome_ui_soundmanager.h"
#include "bighome_ui_likemanager.h"
#include "bighome_ui_mainwindw_messagemanager.h"

#include "bighome_music_base.h"
#include "bighome_music_network.h"
#include "bighome_network_loadresources.h"
#include "bighome_ui_musicphoto.h"


class BIGHOME_UI_MainWindw_PlayManager : public QWidget
{
    Q_OBJECT

public:
    BIGHOME_UI_MainWindw_PlayManager(QWidget *parent = 0);
    ~BIGHOME_UI_MainWindw_PlayManager();
private:
    void init();
    void setStyle();
    void paintEvent(QPaintEvent *event);

private:
    Ui::BIGHOME_UI_MainWindw_PlayManagerClass ui;
    BIGHOME_UI_palyManager *m_palyManager;
    BIGHOME_UI_soundManager *m_soundManager;
    BIGHOME_UI_likeManager *m_likeManager ;
    BIGHOME_Music_Base* m_musicBase;
    BIGHOME_Music_netWork* m_musicNetWork;
    BIGHOME_UI_MainWindw_messageManager *m_messageManager;
    BIGHOME_NetWork_loadResources* m_loadResources;

    qint64 m_musicTime;
    qint64 m_MusicTotalTime;
    QList<QMap<QString, QString>> m_musicMap;
    static int s_i;
    static bool s_playStatrBool;
    QString m_musicNameORSinger;



private slots:
  void slotsPlayMusicManager(bool );
  void slotsPlayNext();
  void slotsMusicTimer(qint64 value);
  void slotsMusicTotalTime(qint64 value);
  void slotsMusicCurrentTime(qint64 value);
  void slotsMusicListUrl(bool, QList<QMap<QString, QString>>);
  void slotsLoadIMG(QPixmap );
  void slotsMusicFlished();
};

#endif // BIGHOME_UI_MAINWINDW_PLAYMANAGER_H
