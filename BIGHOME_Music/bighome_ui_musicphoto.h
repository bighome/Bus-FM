#ifndef BIGHOME_UI_MUSICPHOTO_H
#define BIGHOME_UI_MUSICPHOTO_H

#include <QWidget>
#include <QPixmap>
#include "ui_bighome_ui_musicphoto.h"

class BIGHOME_UI_MusicPhoto : public QWidget
{
    Q_OBJECT

public:
    BIGHOME_UI_MusicPhoto(QWidget *parent = 0);
    ~BIGHOME_UI_MusicPhoto();
    void setMusicPhoto(QString URL);
    void setMusicPhotos(QPixmap pix);
private:
    void init();
    void setStyle();
private:
    Ui::BIGHOME_UI_MusicPhotoClass ui;
};

#endif // BIGHOME_UI_MUSICPHOTO_H
