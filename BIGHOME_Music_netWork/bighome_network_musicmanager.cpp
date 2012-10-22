#include "bighome_network_musicmanager.h"
#include "parser.h"
#include <QtNetwork/QNetworkReply>
#include <QtNetwork/QNetworkRequest>
#include <QVariantMap>
#include <QDebug>

BIGHOME_NetWork_MusicManager::BIGHOME_NetWork_MusicManager(QObject *parent)
  : QObject(parent)
{
  m_netWorkManager = new QNetworkAccessManager;
}

BIGHOME_NetWork_MusicManager::~BIGHOME_NetWork_MusicManager()
{

}
void BIGHOME_NetWork_MusicManager::init()
{

}
void BIGHOME_NetWork_MusicManager::setMusciMessaget(QString channelID, QString appKEY)
{
  QNetworkRequest request;
  //QString URL = QString("http://api.bus.fm/pt/getlistbychannel?channelid=%1&appkey=%2");
  QString URL = QString("http://douban.fm/j/mine/playlist?type=n&channel=%1");//²âÊÔÊ¹ÓÃ¶¹°êFM
  //request.setUrl(QUrl(URL.arg(channelID).arg(appKEY)));
  request.setUrl(QUrl(URL.arg(channelID)));
  QNetworkReply *reply = m_netWorkManager->get(request);
  connect(reply, SIGNAL(finished()), this, SLOT(slotsfinished()));
}
QList<QMap<QString, QString>> BIGHOME_NetWork_MusicManager::setJson(QByteArray jsonDoc)
{
  QJson::Parser parser;
  bool OK;
  QVariantMap jsonMap = parser.parse(jsonDoc, &OK).toMap();
 QList<QMap<QString, QString>> jsonDocList;
  QMap<QString, QString> tempMap;
  if (!jsonDocList.isEmpty())
  {
    jsonDocList.clear();
  }
  if (OK)
  {
    QVariantList tempVariantList = jsonMap["song"].toList();
    for (int i = 0; i < tempVariantList.size(); i++)
    {
      QVariantMap tempVariantMap = tempVariantList.at(i).toMap();
      for (QVariantMap::iterator j = tempVariantMap.begin(); j != tempVariantMap.end(); j++)
      {
        tempMap[j.key()] = j.value().toString();
      }
      jsonDocList << tempMap;
    }
    qDebug()<< "douban.fm" << jsonDocList;
    emit signalsMusicMessage(OK, jsonDocList);
    return jsonDocList;
  }
  emit signalsMusicMessage(OK, jsonDocList);
  return jsonDocList;
}
QList<QMap<QString, QString>> BIGHOME_NetWork_MusicManager::getMusciList()
{
  return m_jsonMap;
}
void BIGHOME_NetWork_MusicManager::slotsfinished()
{
  QNetworkReply* reply = (QNetworkReply*)sender();
  QByteArray login = reply->readAll();
  m_jsonMap = setJson(login);
  reply->deleteLater();
}
