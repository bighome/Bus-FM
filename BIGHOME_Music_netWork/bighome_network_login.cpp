#include "bighome_network_login.h"
#include "parser.h"
#include <QtNetwork/QNetworkReply>
#include <QtNetwork/QNetworkRequest>
#include <QVariantMap>
#include <QDebug>


BIGHOME_NetWork_logIn::BIGHOME_NetWork_logIn(QObject *parent)
:QObject(parent)
{
  init();
  m_netWorkManager = new QNetworkAccessManager;
}

BIGHOME_NetWork_logIn::~BIGHOME_NetWork_logIn()
{
  
}
void BIGHOME_NetWork_logIn::init()
{

}
void BIGHOME_NetWork_logIn::setUser(QString username, QString Pwd)
{

  QNetworkRequest request;
  QString URL = QString("http://api.bus.fm/pt/login?usermail=%1&userpwd=%2").arg(username).arg(Pwd);
  request.setUrl(QUrl(URL));
  QNetworkReply *reply = m_netWorkManager->get(request);
  connect(reply, SIGNAL(finished()), this, SLOT(slotsfinished()));
}
void BIGHOME_NetWork_logIn::slotsfinished()
{
   QNetworkReply* reply = (QNetworkReply*)sender();
   QByteArray login = reply->readAll();
   m_jsonMap = setJson(login);
   reply->deleteLater();
}
  QMap<QString, QString>  BIGHOME_NetWork_logIn::setJson(QByteArray jsonDoc)
{
  QJson::Parser parser;
  bool OK;
  QVariantMap jsonMap = parser.parse(jsonDoc, &OK).toMap();
  QMap<QString, QString> jsonDocMap;
  if (!jsonDocMap.isEmpty())
  {
    jsonDocMap.clear();
  }
  if (OK)
  {
    QVariantList tempVariant = jsonMap["userinfo"].toList();
    QVariantMap tempMap = tempVariant[0].toMap();
    for (QVariantMap::iterator i = tempMap.begin(); i != tempMap.end(); i++)
    {
      jsonDocMap[i.key()] = i.value().toString();
    }
    emit signalsLogin(OK, jsonDocMap);
    return jsonDocMap;
  }
  emit signalsLogin(OK, jsonDocMap);
  return jsonDocMap;
}
  QMap<QString, QString> BIGHOME_NetWork_logIn::getLogin()
  {
    return m_jsonMap;
  }