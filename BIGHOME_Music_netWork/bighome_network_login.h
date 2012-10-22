#ifndef BIGHOME_NETWORK_LOGIN_H
#define BIGHOME_NETWORK_LOGIN_H

#include <QObject>
#include <QtNetwork/QNetworkAccessManager>
#include <QString>
#include <QMap>
#include "bighome_music_network_global.h"

class BIGHOME_MUSIC_NETWORK_EXPORT BIGHOME_NetWork_logIn:public QObject
{
  Q_OBJECT
public:
    BIGHOME_NetWork_logIn(QObject *parent);
    ~BIGHOME_NetWork_logIn();
    void setUser(QString username, QString Pwd);
    QMap<QString, QString> getLogin();

private:
  void init();
  QMap<QString, QString> setJson(QByteArray jsonDoc);

private:
   QNetworkAccessManager *m_netWorkManager;
   QMap<QString, QString> m_jsonMap;
private slots:
    void slotsfinished();

signals:
    void signalsLogin(bool , QMap<QString , QString>);


};

#endif // BIGHOME_NETWORK_LOGIN_H
