#include "bighome_network_channellist.h"
#include "parser.h"
#include <QtNetwork/QNetworkReply>
#include <QtNetwork/QNetworkRequest>
#include <QVariantMap>
#include <QDebug>

BIGHOME_Network_channelList::BIGHOME_Network_channelList(QObject *parent)
  : QObject(parent)
{
  m_netWorkManager = new QNetworkAccessManager;
  init();
}

BIGHOME_Network_channelList::~BIGHOME_Network_channelList()
{

}
void BIGHOME_Network_channelList::init()
{
  QNetworkRequest request;
  QString URL = QString("http://api.bus.fm/pt/getchannellist");
  request.setUrl(QUrl(URL));
  QNetworkReply *reply = m_netWorkManager->get(request);
  connect(reply, SIGNAL(finished()), this, SLOT(slotsfinished()));
}
void BIGHOME_Network_channelList::slotsfinished()
{
  QNetworkReply* reply = (QNetworkReply*)sender();
  QByteArray login = reply->readAll();
  m_jsonMap = setJson(login);
  reply->deleteLater();
}
QList<QMap<QString, QString>> BIGHOME_Network_channelList::setJson(QByteArray jsonDoc)
{
  QJson::Parser parser;
  bool OK;
  QVariantMap jsonMap = parser.parse(jsonDoc, &OK).toMap();
  QList<QMap<QString, QString>> jsonDocMap;
  QMap<QString, QString> tempMap;
  if (!jsonDocMap.isEmpty())
  {
    jsonDocMap.clear();
  }
  if (OK)
  {
    QVariantList tempVariantList = jsonMap["Channels"].toList();
    for (int i = 0; i < tempVariantList.size(); i++)
    {
      QVariantMap tempVariantMap = tempVariantList.at(i).toMap();
      for (QVariantMap::iterator j = tempVariantMap.begin(); j != tempVariantMap.end(); j++)
      {
        tempMap[j.key()] = j.value().toString();
      }
      jsonDocMap << tempMap;
    }
    emit signalsChannelList(OK, jsonDocMap);
    return jsonDocMap;
  }
  emit signalsChannelList(OK, jsonDocMap);
  return jsonDocMap;
}
QList<QMap<QString, QString>> BIGHOME_Network_channelList::getChannelList()
{
  return m_jsonMap;
}

