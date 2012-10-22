#ifndef BIGHOME_UI_MAINWINDW_MESSAGEMANAGER_H
#define BIGHOME_UI_MAINWINDW_MESSAGEMANAGER_H

#include <QWidget>
#include "ui_bighome_ui_mainwindw_messagemanager.h"
#include "bighome_ui_musicmessages.h"
#include "bighome_ui_commentsmanager.h"
#include "bighome_ui_musiclike.h"
#include "bighome_ui_musicphoto.h"


class BIGHOME_UI_MainWindw_messageManager : public QWidget
{
    Q_OBJECT

public:
  static BIGHOME_UI_MainWindw_messageManager *getInterface();
    ~BIGHOME_UI_MainWindw_messageManager();
    BIGHOME_UI_Musicmessages *getMusicMessage();
    BIGHOME_UI_commentsManager *getCommentsManager();
    BIGHOME_UI_MusicLike *getMusicList();
    BIGHOME_UI_MusicPhoto *getMusicPhoto();

private:
  BIGHOME_UI_MainWindw_messageManager(QWidget *parent = 0);
    void init();
    void setStyle();
    void paintEvent(QPaintEvent *event);

private:
    Ui::BIGHOME_UI_MainWindw_messageManagerClass ui;
    BIGHOME_UI_Musicmessages* m_musicMessages;
    BIGHOME_UI_commentsManager* m_commentsManager;
    BIGHOME_UI_MusicLike* m_musicList;
    BIGHOME_UI_MusicPhoto* m_musicPhoto;

    static BIGHOME_UI_MainWindw_messageManager *s_interFace;
};

#endif // BIGHOME_UI_MAINWINDW_MESSAGEMANAGER_H
