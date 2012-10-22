#include "bighome_music_network.h"

BIGHOME_Music_netWork::BIGHOME_Music_netWork(QObject *object)
:QObject(object)
,m_login(NULL)
,m_channelList(NULL)
,m_musicManager(NULL)
{
  MusicList();
}

BIGHOME_Music_netWork::~BIGHOME_Music_netWork()
{

}
void BIGHOME_Music_netWork::setUser( QString userMail,  QString userPwd)
{
  if (m_login == NULL)
  {
    m_login = new  BIGHOME_NetWork_logIn(this);
  }
  m_login->setUser(userMail, userPwd);
  connect(m_login, SIGNAL(signalsLogin(bool , QMap<QString , QString>)), this, SLOT(slotsLogin(bool , QMap<QString , QString>)));
}
void BIGHOME_Music_netWork::slotsLogin(bool LoginOK , QMap<QString , QString> user)
{
  emit signalsGetLoginDate(LoginOK, user);
}

int BIGHOME_Music_netWork::setRegistered( QString userMail,  QString userPwd,  QString nickName)
{
  return temp;
}
int BIGHOME_Music_netWork::setFindPwd( QString userMail)
{
  return temp;
}
int BIGHOME_Music_netWork::setModifyPwd( QString userid,  QString oldPwd,  QString newPwd)
{
  return temp;
}
int BIGHOME_Music_netWork::setUserName( QString userMail)
{
  return temp;
}
int BIGHOME_Music_netWork::setNickName( QString nickName)
{
  return temp;
}
QList<QMap<QString, QString>> BIGHOME_Music_netWork::getMusicList()
{
  return m_musciList;
}
void BIGHOME_Music_netWork::MusicList()
{
  if (m_channelList == NULL)
  {
    m_channelList = new BIGHOME_Network_channelList(this);
  }
  connect(m_channelList, SIGNAL(signalsChannelList(bool,   QList<QMap<QString, QString>>)), this, SLOT(slotsChannelList(bool, QList<QMap<QString, QString>>)));
}
void BIGHOME_Music_netWork::slotsChannelList(bool ok, QList<QMap<QString, QString>> value)
{
  m_musciList = value;
  emit signalsGetMusicList(ok, value);
}
void BIGHOME_Music_netWork::setMusicDate(QString channelid, QString appKEY)
{
  if (m_musicManager == NULL)
  {
    m_musicManager = new BIGHOME_NetWork_MusicManager(this);
  }
  m_musicManager->setMusciMessaget(channelid, appKEY);
  connect(m_musicManager, SIGNAL(signalsMusicMessage(bool,   QList<QMap<QString, QString>>)), this, SLOT(slotsMusicMessage(bool,   QList<QMap<QString, QString>>)));
}
void BIGHOME_Music_netWork::slotsMusicMessage(bool OK, QList<QMap<QString, QString>> value)
{
    emit signalsGetMusicMessage(OK, value);
}
QMap<int, QMap<QString, QString>> BIGHOME_Music_netWork::getMusicCollection()
{
  return m_temp1Map;
}
int BIGHOME_Music_netWork::setMusicCollection(int userID, int musicID)
{
  return temp;
}
int BIGHOME_Music_netWork::setMusicCollectionYorN(int userID, int musicID, int appkeyID, const QString *act)
{
  return temp;
}