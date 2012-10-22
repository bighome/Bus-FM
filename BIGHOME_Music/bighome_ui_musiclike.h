#ifndef BIGHOME_UI_MUSICLIKE_H
#define BIGHOME_UI_MUSICLIKE_H

#include <QWidget>
#include "ui_bighome_ui_musiclike.h"

class BIGHOME_UI_MusicLike : public QWidget
{
    Q_OBJECT

public:
    BIGHOME_UI_MusicLike(QWidget *parent = 0);
    ~BIGHOME_UI_MusicLike();
private:
    void init();
    void setStyle();
signals:
    void signalMusicList();
private:
    Ui::BIGHOME_UI_MusicLikeClass ui;
};

#endif // BIGHOME_UI_MUSICLIKE_H
