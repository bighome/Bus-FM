#ifndef NETWORKIMGS_H
#define NETWORKIMGS_H

#include <QWidget>
#include <QPixmap>
#include "ui_networkimgs.h"
#include "bighome_network_musicmanager.h"
#include "bighome_network_loadresources.h"
#include "bighome_network_channellist.h"
#include "bighome_music_network.h"

class netWorkImgs : public QWidget
{
    Q_OBJECT

public:
    netWorkImgs(QWidget *parent = 0);
    ~netWorkImgs();

private:
    Ui::netWorkImgsClass ui;
    BIGHOME_NetWork_loadResources* m_loadResources;
    BIGHOME_Music_netWork *m_musicNetwork;

private slots:
  void slotsLoadIMG(QPixmap);
  void slotsMusicMessager(bool, QList<QMap<QString, QString>>);
  void slotsMusicList(bool, QList<QMap<QString, QString>>);
};

#endif // NETWORKIMGS_H
