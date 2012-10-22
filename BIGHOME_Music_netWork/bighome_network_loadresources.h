#ifndef BIGHOME_NETWORK_LOADRESOURCES_H
#define BIGHOME_NETWORK_LOADRESOURCES_H

#include <QObject>
#include <QPixmap>
#include <QUrl>
#include <QtNetwork/QNetworkAccessManager>
#include "bighome_music_network_global.h"

class BIGHOME_MUSIC_NETWORK_EXPORT BIGHOME_NetWork_loadResources : public QObject
{
  Q_OBJECT

public:
    BIGHOME_NetWork_loadResources(QObject *parent);
    ~BIGHOME_NetWork_loadResources();

    //set NetWork IMG url
    void loadNetWorkImg(QUrl url);

private:
     QNetworkAccessManager *m_netWorkManager;

private slots:
  void slotsFilished();

signals:
  void signalsGetLoadImg(QPixmap);
    
};

#endif // BIGHOME_NETWORK_LOADRESOURCES_H
