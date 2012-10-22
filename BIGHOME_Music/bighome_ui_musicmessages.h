#ifndef BIGHOME_UI_MUSICMESSAGES_H
#define BIGHOME_UI_MUSICMESSAGES_H

#include <QWidget>
#include <QTime>
#include "ui_bighome_ui_musicmessages.h"

class BIGHOME_UI_Musicmessages : public QWidget
{
    Q_OBJECT

public:
    BIGHOME_UI_Musicmessages(QWidget *parent = 0);
    ~BIGHOME_UI_Musicmessages();
    void setMusicName(QString name);
    void setMusicTime(qint64 time);
    void setSliderMusicTime(qint64 value);
    void setSliderMaxMusicTime(qint64 value);
private:
    void init();
    void setStyle();
    QString SSHHMMInt64(qint64 value);

private:
    Ui::BIGHOME_UI_MusicmessagesClass ui;
    int m_musicTime;
    QString m_SSHHMMStr;
};

#endif // BIGHOME_UI_MUSICMESSAGES_H
