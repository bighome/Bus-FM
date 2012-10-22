#ifndef BIGHOME_UI_PALYMANAGER_H
#define BIGHOME_UI_PALYMANAGER_H

#include <QWidget>
#include "ui_bighome_ui_palymanager.h"

class BIGHOME_UI_palyManager : public QWidget
{
    Q_OBJECT

public:
    BIGHOME_UI_palyManager(QWidget *parent = 0);
    ~BIGHOME_UI_palyManager();
    void setBoolPlayMusic(bool palyBool);
private:
  void init();
  void setStyle();
private slots:
  void slotsPlayAndPush();
  void slotsNextMusic();
private:
    Ui::BIGHOME_UI_palyManagerClass ui;
    static bool s_playBool;

signals:
    void signalPlayMusic(bool value);
    void signalNextMusic();
};

#endif // BIGHOME_UI_PALYMANAGER_H
