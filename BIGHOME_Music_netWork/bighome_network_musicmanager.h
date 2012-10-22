#ifndef BIGHOME_NETWORK_MUSICMANAGER_H
#define BIGHOME_NETWORK_MUSICMANAGER_H

#include <QObject>
#include <QList>
#include <QMap>
#include <QtNetwork/QNetworkAccessManager>
#include "bighome_music_network_global.h"

class BIGHOME_MUSIC_NETWORK_EXPORT BIGHOME_NetWork_MusicManager : public QObject
{
  Q_OBJECT

public:
    BIGHOME_NetWork_MusicManager(QObject *parent);
    ~BIGHOME_NetWork_MusicManager();
    void setMusciMessaget(QString channelID, QString appKEY);
    QList<QMap<QString, QString>> getMusciList();

private:
  void init();
  QList<QMap<QString, QString>> setJson(QByteArray jsonDoc);
    

private:
  QNetworkAccessManager *m_netWorkManager;
  QList<QMap<QString, QString>> m_jsonMap;

private slots:
    void slotsfinished();

signals:
    void signalsMusicMessage(bool,   QList<QMap<QString, QString>>);
    
};

#endif // BIGHOME_NETWORK_MUSICMANAGER_H
