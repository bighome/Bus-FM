#include "bighome_ui_musiclike.h"

BIGHOME_UI_MusicLike::BIGHOME_UI_MusicLike(QWidget *parent)
    : QWidget(parent)
{
  ui.setupUi(this);
  init();
  setStyle();
}

BIGHOME_UI_MusicLike::~BIGHOME_UI_MusicLike()
{

}
void BIGHOME_UI_MusicLike::init()
{
  this->setMinimumSize(QSize(15, 20));
  this->setMaximumSize(QSize(15, 20));
    ui.musicLike->setText("");
    ui.musicLike->setMaximumSize(QSize(12, 11));
    ui.musicLike->setMinimumSize(QSize(12, 11));
    connect(ui.musicLike, SIGNAL(pressed()), this, SLOT(signalMusicList()));
}
void BIGHOME_UI_MusicLike::setStyle()
{
   ui.musicLike->setStyleSheet("QPushButton {border: none; border-image:url(.//Resources//unlist.png);} QPushButton::hover {border: none; border-image:url(.//Resources//list.png);}");
}