#ifndef BIGHOME_UI_SOUNDMANAGER_H
#define BIGHOME_UI_SOUNDMANAGER_H

#include <QWidget>
#include "ui_bighome_ui_soundmanager.h"

class BIGHOME_UI_soundManager : public QWidget
{
    Q_OBJECT

public:
    BIGHOME_UI_soundManager(QWidget *parent = 0);
    ~BIGHOME_UI_soundManager();
private:
  void setStyle();
  void init();

private:
    Ui::BIGHOME_UI_soundManagerClass ui;
    static bool s_soundManagerBOOL;
    static int s_soundSizeInt;

private slots:
      void slotSoundManagerBTN();
      void slotSoundSize(int value);
signals:
      void signalSoundSize(int value);
      void signalSoundManager(bool value);
};

#endif // BIGHOME_UI_SOUNDMANAGER_H
