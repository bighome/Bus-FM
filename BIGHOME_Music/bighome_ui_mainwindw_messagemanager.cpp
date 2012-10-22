#include "bighome_ui_mainwindw_messagemanager.h"
#include <QHBoxLayout>
#include <QPainter>
BIGHOME_UI_MainWindw_messageManager *BIGHOME_UI_MainWindw_messageManager::s_interFace = NULL ;

BIGHOME_UI_MainWindw_messageManager *BIGHOME_UI_MainWindw_messageManager::getInterface()
{
  if (s_interFace == NULL)
  {
    s_interFace = new BIGHOME_UI_MainWindw_messageManager;
  }
  return s_interFace;
}
BIGHOME_UI_MainWindw_messageManager::BIGHOME_UI_MainWindw_messageManager(QWidget *parent)
    : QWidget(parent)
{
  ui.setupUi(this);
  init();
}

BIGHOME_UI_MainWindw_messageManager::~BIGHOME_UI_MainWindw_messageManager()
{

}
void BIGHOME_UI_MainWindw_messageManager::init()
{
     m_commentsManager = new BIGHOME_UI_commentsManager;
    QHBoxLayout *commentsManagerLayout = new QHBoxLayout(this);
    commentsManagerLayout->addWidget(m_commentsManager);
    m_musicList = new BIGHOME_UI_MusicLike;
    QHBoxLayout *musicListLayout = new QHBoxLayout(this);
    musicListLayout->addWidget(m_musicList);
    m_musicMessages = new BIGHOME_UI_Musicmessages;
    QHBoxLayout *musicMessagesLayout = new QHBoxLayout(this);
    musicMessagesLayout->addWidget(m_musicMessages);
    m_musicPhoto = new BIGHOME_UI_MusicPhoto;
    QHBoxLayout *musicPhotoLayout = new QHBoxLayout(this);
    musicPhotoLayout->addWidget(m_musicPhoto);
    ui.photo->setLayout(musicPhotoLayout);
    ui.musicMessage->setLayout(musicMessagesLayout);
    ui.commentsManager->setLayout(commentsManagerLayout);
}
void BIGHOME_UI_MainWindw_messageManager::setStyle()
{

}
void BIGHOME_UI_MainWindw_messageManager::paintEvent(QPaintEvent *event)
{
  QPainter p(this);  
  QPixmap pix(".//Resources//topBg.png");
  if (!pix.isNull())
  {
    p.drawPixmap(0, 0, width(), height(), pix);
  }
  update();
}
BIGHOME_UI_Musicmessages *BIGHOME_UI_MainWindw_messageManager::getMusicMessage()
{
    return m_musicMessages;
}
BIGHOME_UI_commentsManager *BIGHOME_UI_MainWindw_messageManager::getCommentsManager()
{
  return m_commentsManager;
}
BIGHOME_UI_MusicLike *BIGHOME_UI_MainWindw_messageManager::getMusicList()
{
  return m_musicList;
}
BIGHOME_UI_MusicPhoto *BIGHOME_UI_MainWindw_messageManager::getMusicPhoto()
{
  return m_musicPhoto;
}