#ifndef BIGHOME_RADIO_H
#define BIGHOME_RADIO_H

#include <QtGui/QWidget>
#include <QMouseEvent>
#include <QMoveEvent>
#include <QPoint>
#include <QMap>
#include <QList>
#include <QUrl>
#include "bighome_music_base.h"
#include "bighome_music_network.h"
#include "bighome_network_loadresources.h"
#include "ui_bighome_radio.h"

class BIGHOME_Radio : public QWidget
{
    Q_OBJECT

public:
    BIGHOME_Radio(QWidget *parent = 0, Qt::WFlags flags = 0);
    ~BIGHOME_Radio();
private:
    void init();
    void paintEvent(QPaintEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void changeEvent(QEvent *e);
    void moveEvent ( QMoveEvent * event );

private:
    Ui::BIGHOME_RadioClass ui;
    static QPoint s_mainWindowPoint;
    QPoint m_windwPos;
    QPoint m_mousePos;
    QPoint m_pos;
    BIGHOME_Music_Base *m_musicBase;
    BIGHOME_Music_netWork *m_musicNetwork;
    BIGHOME_NetWork_loadResources *m_networkLoadResources;
    QList<QMap<QString, QString>> m_musicMap;
    QString m_musicNameORSinger;
    static bool s_playORstop;
private slots:
  void playMusic();
  void nextMusic();
  void slotsMusicTotalTime(qint64 value);
  void slotsMusicCurrentTime(qint64 value);
  void slotsMusicListUrl(bool, QList<QMap<QString, QString>>);
  void slotsLoadIMG(QPixmap );
};

#endif // BIGHOME_RADIO_H
