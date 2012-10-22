#include "bighome_ui_palymanager.h"

bool BIGHOME_UI_palyManager::s_playBool = true;
BIGHOME_UI_palyManager::BIGHOME_UI_palyManager(QWidget *parent)
    : QWidget(parent)
{
  ui.setupUi(this);
  connect(ui.playAndPush, SIGNAL(pressed()), SLOT(slotsPlayAndPush()));
  connect(ui.next, SIGNAL(pressed()), SLOT(slotsNextMusic()));
  init();
  setStyle();
}

BIGHOME_UI_palyManager::~BIGHOME_UI_palyManager()
{

}
void BIGHOME_UI_palyManager::init()
{
  this->setMinimumSize(QSize(40, 30));
  this->setMaximumSize(QSize(40, 30));
  ui.playAndPush->setText("");
  ui.playAndPush->setMaximumSize(QSize(12, 15));
  ui.playAndPush->setMinimumSize(QSize(12, 15));
  ui.next->setText("");
  ui.next->setMaximumSize(QSize(17, 15));
  ui.next->setMinimumSize(QSize(17, 15));
}
void BIGHOME_UI_palyManager::setStyle()
{
  ui.playAndPush->setStyleSheet("QPushButton {border: none; border-image:url(.//Resources//playButton.png);}");
  ui.next->setStyleSheet("QPushButton {border: none; border-image:url(.//Resources//unnext.png);} QPushButton::hover {border: none; border-image:url(.//Resources//next.png);}");
}
void BIGHOME_UI_palyManager::slotsPlayAndPush()
{
    if (s_playBool == true)
    {
      ui.playAndPush->setStyleSheet("QPushButton {border: none; border-image:url(.//Resources//pushButton.png);}");
      emit signalPlayMusic(s_playBool);
      s_playBool = false;
    }else{
      ui.playAndPush->setStyleSheet("QPushButton {border: none; border-image:url(.//Resources//playButton.png);}");
      emit signalPlayMusic(s_playBool);
      s_playBool = true;
    }
}
void BIGHOME_UI_palyManager::setBoolPlayMusic(bool palyBool)
{
  s_playBool = palyBool;
  emit slotsPlayAndPush();
}
void BIGHOME_UI_palyManager::slotsNextMusic()
{
    emit signalNextMusic();
}