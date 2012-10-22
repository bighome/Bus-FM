#include "bighome_music_ui_soundmanager.h"

bool BIGHOME_Music_UI_SoundManager::s_soundManagerBOOL = true;
int BIGHOME_Music_UI_SoundManager::s_soundSizeInt = 100;
BIGHOME_Music_UI_SoundManager* BIGHOME_Music_UI_SoundManager::s_interface = NULL;
BIGHOME_Music_UI_SoundManager &BIGHOME_Music_UI_SoundManager::getInterFace()
 {
    if (s_interface == NULL)
    {
      s_interface = new BIGHOME_Music_UI_SoundManager;
    }
    return *s_interface;
 }
BIGHOME_Music_UI_SoundManager::BIGHOME_Music_UI_SoundManager(QWidget *parent)
    : QWidget(parent)
{
  ui.setupUi(this);
  connect(ui.sound, SIGNAL(pressed()), this, SLOT(slotSoundManagerBTN()));
  connect(ui.Slider, SIGNAL(valueChanged(int )), this, SLOT(slotSoundSize(int )));
  init();
  setStyle();
}

BIGHOME_Music_UI_SoundManager::~BIGHOME_Music_UI_SoundManager()
{

}
void BIGHOME_Music_UI_SoundManager::init()
{
  ui.sound->setMaximumSize(QSize(8, 16));
  ui.sound->setMinimumSize(QSize(8, 16));
  ui.sound->setText("");

  ui.Slider->setMaximumHeight(23);
  ui.Slider->setMinimumHeight(23);
  ui.Slider->setRange(0, 100);
  ui.Slider->setPageStep(1);
  ui.Slider->setValue(100);
}
void BIGHOME_Music_UI_SoundManager::setStyle()
{
   ui.Slider->setStyleSheet("QSlider::groove:horizontal {border: 1px solid #999999; background: #535353; background: qlineargradient(x1:0.4, y1:0, x2:0.4, y2:0.4, stop:0 #000000, stop:1 #e0e0e0); height: 5px; left: 10px; right: 10px;border-radius: 3px;} QSlider::handle:horizontal{border: 1px solid #5c5c5c; border-image:url(.//Resources//sliderHandle.png); width: 9px; Height: 23px; margin: -9px -9px -9px -9px;} QSlider::sub-page:horizontal{background: #ccc; border-radius: 3px;}");
   ui.sound->setStyleSheet("QPushButton {border: none; border-image:url(.//Resources//sound.png);}");
}
void BIGHOME_Music_UI_SoundManager::slotSoundManagerBTN()
{
  if (s_soundManagerBOOL == true)
  {
    emit signalSoundManager(false); 
    ui.sound->setText("N");
  } else{
    emit signalSoundManager(true);
     ui.sound->setText("Y");
  }
}
void BIGHOME_Music_UI_SoundManager::slotSoundSize(int value)
{
   emit signalSoundSize(value);
}