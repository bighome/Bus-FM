#include "bighome_ui_musicphoto.h"
#include <QPalette>

BIGHOME_UI_MusicPhoto::BIGHOME_UI_MusicPhoto(QWidget *parent)
    : QWidget(parent)
{
  ui.setupUi(this);
  init();
  setStyle();
}

BIGHOME_UI_MusicPhoto::~BIGHOME_UI_MusicPhoto()
{

}
void BIGHOME_UI_MusicPhoto::init()
{
  this->setAutoFillBackground(true);
  this->setFixedSize(QSize(102, 102));
  QPalette bgPhotoPale;
  bgPhotoPale.setBrush(QPalette::Background, QBrush(QPixmap(".//Resources//bgPhoto.png")));
  this->setPalette(bgPhotoPale);
  ui.photo->setText("");
  //ui.photo->setGeometry(15, 15, 76, 76);
}
void BIGHOME_UI_MusicPhoto::setStyle()
{

}
void BIGHOME_UI_MusicPhoto::setMusicPhoto(QString URL)
{
    QPixmap musicPhotoPix;
    bool pixBool;
    pixBool = musicPhotoPix.load(URL);
    if (pixBool)
    {
      ui.photo->setScaledContents(pixBool);
      ui.photo->setPixmap(musicPhotoPix);
    }
}
void BIGHOME_UI_MusicPhoto::setMusicPhotos(QPixmap pix)
{
  ui.photo->setScaledContents(!pix.isNull());
  ui.photo->setPixmap(pix);
}