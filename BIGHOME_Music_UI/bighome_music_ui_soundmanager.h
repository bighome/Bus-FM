#ifndef BIGHOME_MUSIC_UI_SOUNDMANAGER_H
#define BIGHOME_MUSIC_UI_SOUNDMANAGER_H

#include <QWidget>
#include "ui_bighome_music_ui_soundmanager.h"
#include "bighome_music_ui_global.h"

class BIGHOME_MUSIC_UI_EXPORT BIGHOME_Music_UI_SoundManager : public QWidget
{
    Q_OBJECT

public:
  static BIGHOME_Music_UI_SoundManager &getInterFace();
    ~BIGHOME_Music_UI_SoundManager();
private:
  BIGHOME_Music_UI_SoundManager(QWidget *parent = 0);
  void setStyle();
  void init();
private:
    Ui::BIGHOME_Music_UI_SoundManagerClass ui;
    static bool s_soundManagerBOOL;
    static int s_soundSizeInt;
    static BIGHOME_Music_UI_SoundManager* s_interface;

private slots:
    void slotSoundManagerBTN();
    void slotSoundSize(int value);
signals:
    void signalSoundSize(int value);
    void signalSoundManager(bool value);
};

#endif // BIGHOME_MUSIC_UI_SOUNDMANAGER_H
