#include "bighome_ui_soundmanager.h"

bool BIGHOME_UI_soundManager::s_soundManagerBOOL = true;
int BIGHOME_UI_soundManager::s_soundSizeInt = 100;
BIGHOME_UI_soundManager::BIGHOME_UI_soundManager(QWidget *parent)
    : QWidget(parent)
{
  ui.setupUi(this);
  connect(ui.sound, SIGNAL(pressed()), this, SLOT(slotSoundManagerBTN()));
  connect(ui.Slider, SIGNAL(valueChanged(int )), this, SLOT(slotSoundSize(int )));
  init();
  setStyle();
}

BIGHOME_UI_soundManager::~BIGHOME_UI_soundManager()
{

}
void BIGHOME_UI_soundManager::init()
{
  this->setMaximumHeight(30);
  this->setMinimumHeight(30);
  ui.sound->setMaximumSize(QSize(10, 15));
  ui.sound->setMinimumSize(QSize(10, 15));
  ui.sound->setText("");

  ui.Slider->setMaximumHeight(23);
  ui.Slider->setMinimumHeight(23);
  ui.Slider->setRange(0, 100);
  ui.Slider->setPageStep(1);
  ui.Slider->setValue(50);
}
void BIGHOME_UI_soundManager::setStyle()
{
  ui.Slider->setStyleSheet("QSlider::groove:horizontal {border: 1px solid #999999; background: #535353; background: qlineargradient(x1:0.4, y1:0, x2:0.4, y2:0.4, stop:0 #000000, stop:1 #e0e0e0); height: 5px; left: 10px; right: 10px;border-radius: 3px;} QSlider::handle:horizontal{border: 1px solid #5c5c5c; border-image:url(.//Resources//sliderHandle.png); width: 9px; Height: 23px; margin: -9px -9px -9px -9px;} QSlider::sub-page:horizontal{background: #ccc; border-radius: 3px;}");
  ui.sound->setStyleSheet("QPushButton {border: none; border-image:url(.//Resources//sound.png);}");
}
void BIGHOME_UI_soundManager::slotSoundManagerBTN()
{
  if (s_soundManagerBOOL == true)
  {
    s_soundManagerBOOL = false;
    emit signalSoundManager(s_soundManagerBOOL); 
    ui.Slider->setValue(0);
    ui.sound->setStyleSheet("QPushButton {border: none; border-image:url(.//Resources//unsound.png);}");
  } else{
    s_soundManagerBOOL = true;
    emit signalSoundManager(s_soundManagerBOOL);
     ui.sound->setText("");
     ui.Slider->setValue(100);
     ui.sound->setStyleSheet("QPushButton {border: none; border-image:url(.//Resources//sound.png);}");
  }
}
void BIGHOME_UI_soundManager::slotSoundSize(int value)
{
  if (value == 0)
  {
    ui.sound->setStyleSheet("QPushButton {border: none; border-image:url(.//Resources//unsound.png);}");
  }else{
    ui.sound->setText("");
    ui.sound->setStyleSheet("QPushButton {border: none; border-image:url(.//Resources//sound.png);}");
  }
  emit signalSoundSize(value);
}