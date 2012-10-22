#ifndef BIGHOME_MUSIC_NETWORK_H
#define BIGHOME_MUSIC_NETWORK_H

#include <QString>
#include <QMap>
#include <QObject>
#include "bighome_music_network_global.h"
#include "bighome_network_login.h"
#include "bighome_network_channellist.h"
#include "bighome_network_musicmanager.h"

class BIGHOME_MUSIC_NETWORK_EXPORT BIGHOME_Music_netWork:public QObject
{
  Q_OBJECT
public:
  BIGHOME_Music_netWork(QObject *object);
    ~BIGHOME_Music_netWork();
    //Account Manager

    //Login
    void setUser( QString userMail,  QString userPwd);

    //Registered
    int setRegistered( QString userMail,  QString userPwd,  QString nickName); // 1 yes,  0 erro:Ãû×Ö±³Õ¼ÓÃ

    //find PWD
    int setFindPwd( QString userMail);//1 yes, 0 erro

    //Modify PWD
    int setModifyPwd( QString userid,  QString oldPwd,  QString newPwd);// 1 yes, 0 erro

    //username yes?
    int setUserName( QString userMail); //1 yes, 0 no;

    //nickName yes?
    int setNickName( QString nickName); //1 yes; 0 no



    //Music Manager
    
  QList<QMap<QString, QString>> getMusicList();
    
    //music date
    void setMusicDate(QString channelid, QString appKEY);

    //music Collection
    QMap<int, QMap<QString, QString>> getMusicCollection();

    //music Collection yes?
    int setMusicCollection(int userID, int musicID);// 1 collection, 0 unCollection

    //collection yes or no?
    int setMusicCollectionYorN(int userID, int musicID, int appkeyID, const QString *act); // 1 collection yes / unCollection, 0 erro


private:
  BIGHOME_NetWork_logIn *m_login;  
  BIGHOME_Network_channelList *m_channelList;
  BIGHOME_NetWork_MusicManager *m_musicManager;
  QMap<QString, QString> m_userMap;
  QList<QMap<QString, QString>> m_musciList;
  QList<QMap<QString, QString>> m_musciDateList;
  
  //test
  int temp;
  QMap<QString, QString> m_tempMap;
  QMap<int, QMap<QString, QString>> m_temp1Map;
  QMap<int , QString> m_temp2Map;

private slots:
  void slotsLogin(bool , QMap<QString , QString>);
  void slotsChannelList(bool, QList<QMap<QString, QString>>);
  void slotsMusicMessage(bool, QList<QMap<QString, QString>>);

signals:
  void signalsGetLoginDate(bool, QMap<QString, QString>); // get user date   bool:login OK?  QMap<Qstring, QString>:LOGIN DATE
  void signalsGetMusicList(bool, QList<QMap<QString, QString>>); //  get music List bool:List OK?  QList<QMap<QString, QString>>::MUSIC LIST DATE
  void signalsGetMusicMessage(bool,   QList<QMap<QString, QString>>);// get music message   bool::date OK? QList<QMap<QString, QString>>::MUSIC MESSAGE

private:
  void MusicList();




};

#endif // BIGHOME_MUSIC_NETWORK_H
