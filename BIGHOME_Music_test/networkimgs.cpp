#include "networkimgs.h"
#include <QUrl>
#include <QDebug>
#include <QPixmap>

netWorkImgs::netWorkImgs(QWidget *parent)
    : QWidget(parent)
    ,m_loadResources(NULL)
    ,m_musicNetwork(NULL)
{
  ui.setupUi(this);
  if (m_loadResources == NULL)
  {
    m_loadResources = new BIGHOME_NetWork_loadResources(this);
  }
  m_loadResources->loadNetWorkImg(QUrl("http://www.luoo.net/wp-content/uploads/ds.jpg"));
  connect(m_loadResources, SIGNAL(signalsGetLoadImg(QPixmap )), this, SLOT(slotsLoadIMG(QPixmap )));
  if (m_musicNetwork == NULL)
  {
    m_musicNetwork = new BIGHOME_Music_netWork(this);
  }
  m_musicNetwork->setMusicDate(QString("1"), QString("0"));
  connect(m_musicNetwork, SIGNAL(signalsGetMusicMessage(bool , QList<QMap<QString, QString>> )), this, SLOT(slotsMusicMessager(bool , QList<QMap<QString, QString>> )));
  connect(m_musicNetwork, SIGNAL(signalsGetMusicList(bool, QList<QMap<QString, QString>> )), this, SLOT(slotsMusicList(bool, QList<QMap<QString, QString>> )));
}

netWorkImgs::~netWorkImgs()
{

}
void netWorkImgs::slotsLoadIMG(QPixmap value)
{
  ui.label->setPixmap(value);
  QPixmap musicPhotoPix;
  bool pixBool;
  pixBool = musicPhotoPix.load("D:\\test.png");
  if (pixBool)
  {
   ui.label->setScaledContents(pixBool);
   ui.label->setPixmap(musicPhotoPix);
  }
}
void netWorkImgs::slotsMusicMessager(bool OK, QList<QMap<QString, QString>> messager)
{
  if (OK)
  {
    qDebug() << "musicMessager" << messager;
  }
}
void netWorkImgs::slotsMusicList(bool OK, QList<QMap<QString, QString>> musicList)
{
  if (OK)
  {
    qDebug() << "MusicList" << musicList;
  }
}
