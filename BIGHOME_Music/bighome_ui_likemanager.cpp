#include "bighome_ui_likemanager.h"

int BIGHOME_UI_likeManager::s_like = 1;
BIGHOME_UI_likeManager::BIGHOME_UI_likeManager(QWidget *parent)
    : QWidget(parent)
{
  ui.setupUi(this);
  connect(ui.like, SIGNAL(pressed()), this, SLOT(slotsLike()));
  connect(ui.add, SIGNAL(pressed()), this, SLOT(signalAddMusic()));
  init();
  setStyle();
}

BIGHOME_UI_likeManager::~BIGHOME_UI_likeManager()
{

}
void BIGHOME_UI_likeManager::init()
{
    this->setMaximumSize(QSize(46, 30));
    this->setMinimumSize(QSize(46, 30));
    ui.like->setMaximumSize(QSize(18, 15));
    ui.like->setMinimumSize(QSize(18, 15));
    ui.like->setText("");
    ui.add->setMaximumSize(QSize(18, 15));
    ui.add->setMinimumSize(QSize(18, 15));
    ui.add->setText("");
}
void BIGHOME_UI_likeManager::setStyle()
{
  ui.like->setStyleSheet("QPushButton {border: none; border-image:url(.//Resources//unlike.png);}");
  ui.add->setStyleSheet("QPushButton {border: none; border-image:url(.//Resources//add.png);}");
}
void BIGHOME_UI_likeManager::slotsLike()
{
  if (s_like == 0)
  {
    s_like = 1;
    ui.like->setStyleSheet("QPushButton {border: none; border-image:url(.//Resources//unlike.png);}");
    emit signalLikeMusic(s_like);
  }else{
    s_like = 0;
    ui.like->setStyleSheet("QPushButton {border: none; border-image:url(.//Resources//like.png);}");
    emit signalLikeMusic(s_like);
  }
}
void BIGHOME_UI_likeManager::setLikeMusic(int valueBool)
{
  if (valueBool == 0)
  {
    s_like = 0;
    ui.like->setStyleSheet("QPushButton {border: none; border-image:url(.//Resources//like.png);}");
  }else{
    s_like = 1;
    ui.like->setStyleSheet("QPushButton {border: none; border-image:url(.//Resources//unlike.png);}");
  }
}