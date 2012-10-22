#ifndef BIGHOME_NETWORK_CHANNELLIST_H
#define BIGHOME_NETWORK_CHANNELLIST_H

#include <QObject>
#include <QList>
#include <QMap>
#include <QtNetwork/QNetworkAccessManager>
#include "bighome_music_network_global.h"

class BIGHOME_MUSIC_NETWORK_EXPORT BIGHOME_Network_channelList : public QObject
{
  Q_OBJECT

public:
    BIGHOME_Network_channelList(QObject *parent);
    ~BIGHOME_Network_channelList();
    QList<QMap<QString, QString>> getChannelList();

private:
  void init();
  QList<QMap<QString, QString>> setJson(QByteArray jsonDoc);

private:
  QNetworkAccessManager *m_netWorkManager;
  QList<QMap<QString, QString>> m_jsonMap;

private slots:
  void slotsfinished();

signals:
    void signalsChannelList(bool,   QList<QMap<QString, QString>>);
};

#endif // BIGHOME_NETWORK_CHANNELLIST_H
