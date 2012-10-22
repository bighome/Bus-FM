#ifndef BIGHOME_UI_LIKEMANAGER_H
#define BIGHOME_UI_LIKEMANAGER_H

#include <QWidget>
#include "ui_bighome_ui_likemanager.h"

class BIGHOME_UI_likeManager : public QWidget
{
    Q_OBJECT

public:
    BIGHOME_UI_likeManager(QWidget *parent = 0);
    ~BIGHOME_UI_likeManager();
    void setLikeMusic(int valueBool);

private:
  void init();
  void setStyle();
  private slots:
    void slotsLike();

signals:
    void signalLikeMusic(int valueBool); //0 : like, 1: unlike
    void signalAddMusic();

private:
    Ui::BIGHOME_UI_likeManagerClass ui;
  static int s_like;
};

#endif // BIGHOME_UI_LIKEMANAGER_H
