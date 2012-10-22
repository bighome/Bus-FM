#include "bighome_ui_mainwindw_playmanager.h"
#include <QHBoxLayout>
#include <QUrl>
#include <QDebug>


int BIGHOME_UI_MainWindw_PlayManager::s_i = 0;
bool BIGHOME_UI_MainWindw_PlayManager::s_playStatrBool = false;
BIGHOME_UI_MainWindw_PlayManager::BIGHOME_UI_MainWindw_PlayManager(QWidget *parent)
    : QWidget(parent)
    ,m_musicBase(NULL)
    ,m_musicNetWork(NULL)
    ,m_palyManager(NULL)
    ,m_soundManager(NULL)
    ,m_likeManager(NULL)
    ,m_loadResources(NULL)
{
  ui.setupUi(this);
  init();
}

BIGHOME_UI_MainWindw_PlayManager::~BIGHOME_UI_MainWindw_PlayManager()
{
    delete m_palyManager;
    delete m_soundManager;
    delete m_likeManager;
}
void BIGHOME_UI_MainWindw_PlayManager::init()
{
    this->setMinimumSize(QSize(354, 42));
    this->setMaximumSize(QSize(354, 42));

    m_messageManager = BIGHOME_UI_MainWindw_messageManager::getInterface();

    m_palyManager = new BIGHOME_UI_palyManager;
    m_soundManager = new BIGHOME_UI_soundManager;
    m_likeManager = new BIGHOME_UI_likeManager;
    QHBoxLayout *playLayout = new QHBoxLayout(this);
    playLayout->addWidget(m_palyManager);
    QHBoxLayout *soundLayout = new QHBoxLayout(this);
    soundLayout->addWidget(m_soundManager);
    QHBoxLayout *likeLayout = new QHBoxLayout(this);
    likeLayout->addWidget(m_likeManager);
    ui.play->setLayout(playLayout);
    ui.sound->setLayout(soundLayout);
    ui.like->setLayout(likeLayout);

    //²âÊÔ
    if (m_loadResources == NULL)
    {
      m_loadResources = new BIGHOME_NetWork_loadResources(this);
    }
    if (m_musicBase == NULL)
    {
      m_musicBase = new BIGHOME_Music_Base(this);
    }
    if (m_musicNetWork == NULL)
    {
      m_musicNetWork = new BIGHOME_Music_netWork(this);
    }
    m_musicNetWork->setMusicDate(QString("7"), QString(""));
    //QList<QUrl> tempUrl;
    //tempUrl << QUrl("http://zhangmenshiting2.baidu.com/data2/music/500896/500896.mp3?xcode=f135947b3e1599c28218ad8d69e657ae&r=1343895963");
    //m_palyManager->setBoolPlayMusic(m_musicBase->addFiles(tempUrl));
    connect(m_palyManager, SIGNAL(signalPlayMusic(bool )), this, SLOT(slotsPlayMusicManager(bool )));
    connect(m_palyManager,  SIGNAL(signalNextMusic()), this, SLOT(slotsPlayNext()));
    connect(m_musicNetWork, SIGNAL(signalsGetMusicMessage(bool, QList<QMap<QString, QString>>)), this, SLOT(slotsMusicListUrl(bool, QList<QMap<QString, QString>>)));

     connect(m_musicBase, SIGNAL(signalMusicTime(qint64 )), this, SLOT(slotsMusicTimer(qint64 )));
     connect(m_musicBase, SIGNAL(signalMusicTotalTime(qint64 )), this, SLOT(slotsMusicTotalTime(qint64 )));
     connect(m_musicBase, SIGNAL(signalMusicCurrentTime(qint64 )), this, SLOT(slotsMusicCurrentTime(qint64 )));
     connect(m_musicBase, SIGNAL(signalMusicFlished()), this, SLOT(slotsMusicFlished()));

}
void BIGHOME_UI_MainWindw_PlayManager::setStyle()
{

}
void BIGHOME_UI_MainWindw_PlayManager::paintEvent(QPaintEvent *event)
{
  QPainter p(this);  
  QPixmap pix(".//Resources//footBg.png");
  if (!pix.isNull())
  {
    p.drawPixmap(0, 0, width(), height(), pix);
  }
  update();
}
void BIGHOME_UI_MainWindw_PlayManager::slotsPlayMusicManager(bool value)
{
    if (value)
    {
      m_musicBase->MusicPlay();
    }else
    {
        m_musicBase->MusicPush();
    }
}
void BIGHOME_UI_MainWindw_PlayManager::slotsPlayNext()
{

}
void BIGHOME_UI_MainWindw_PlayManager::slotsMusicTimer(qint64 value)
{
    m_messageManager->getMusicMessage()->setMusicTime(value);
    m_musicTime = value;
}
void BIGHOME_UI_MainWindw_PlayManager::slotsMusicTotalTime(qint64 value)
{
    m_messageManager->getMusicMessage()->setSliderMaxMusicTime(value);
    m_MusicTotalTime = value;

}
void BIGHOME_UI_MainWindw_PlayManager::slotsMusicCurrentTime(qint64 value)
{
  m_messageManager->getMusicMessage()->setSliderMusicTime(value);
}
void BIGHOME_UI_MainWindw_PlayManager::slotsMusicListUrl(bool ok, QList<QMap<QString, QString>> value)
{   
  QList<QUrl> tempUrl;
  if (ok)
  {
    m_musicMap = value;
    if (!tempUrl.isEmpty())
    {
      tempUrl.clear();
    }
    for (int i =0; i< value.size(); i++)
    {
      tempUrl << QUrl(value.at(i).value("url"));
    }
    qDebug()<< "music URL:"<<tempUrl;
  m_palyManager->setBoolPlayMusic(m_musicBase->addFiles(tempUrl));
  m_musicNameORSinger = QString("%1--%2").arg(m_musicMap.at(0).value("title")).arg(m_musicMap.at(0).value("artist"));
  m_loadResources->loadNetWorkImg(QUrl(m_musicMap.at(0).value("picture")));
  connect(m_loadResources, SIGNAL(signalsGetLoadImg(QPixmap )), this, SLOT(slotsLoadIMG(QPixmap )));
  }
}
void BIGHOME_UI_MainWindw_PlayManager::slotsLoadIMG(QPixmap pixmap)
{
     m_messageManager->getMusicMessage()->setMusicName(m_musicNameORSinger);
     if (!pixmap.isNull())
     {
       m_messageManager->getMusicPhoto()->setMusicPhotos(pixmap);
     }
}
void BIGHOME_UI_MainWindw_PlayManager::slotsMusicFlished()
{
        s_i = s_i+1;
        if (s_i == m_musicMap.size())
        {
          s_i = 0;
        }
        m_musicNameORSinger = QString("%1---%2").arg(m_musicMap.at(s_i).value("title")).arg(m_musicMap.at(s_i).value("artist"));
        m_loadResources->loadNetWorkImg(QUrl(m_musicMap.at(s_i).value("picture")));
        connect(m_loadResources, SIGNAL(signalsGetLoadImg(QPixmap )), this, SLOT(slotsLoadIMG(QPixmap )));
}