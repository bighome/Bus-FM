#ifndef BIGHOME_MUSIC_MAINWINDW_H
#define BIGHOME_MUSIC_MAINWINDW_H

#include <QWidget>
#include <QMouseEvent>
#include <QMoveEvent>
#include <QPoint>
#include "ui_bighome_music_mainwindw.h"

class BIGHOME_UI_MainWindw_PlayManager;
class BIGHOME_UI_MainWindw_messageManager;
class BIGHOME_UI_MainWindow_titleBar;

class BIGHOME_Music_mainWindw : public QWidget
{
    Q_OBJECT

public:
  static BIGHOME_Music_mainWindw *getInterFace();
    ~BIGHOME_Music_mainWindw();
    QPoint getMainWindwPos();
private:
  BIGHOME_Music_mainWindw(QWidget *parent = 0);
  void init();
  void paintEvent(QPaintEvent *event);
  void mousePressEvent(QMouseEvent *event);
  void mouseMoveEvent(QMouseEvent *event);
  void changeEvent(QEvent *e);
  void moveEvent ( QMoveEvent * event );

private:
    Ui::BIGHOME_Music_mainWindwClass ui;
    static BIGHOME_Music_mainWindw *s_getInterFace;
     BIGHOME_UI_MainWindw_PlayManager *m_palyManagerMainwindw;
     BIGHOME_UI_MainWindw_messageManager *m_messageManager;
      BIGHOME_UI_MainWindow_titleBar *m_mainwindowTitlebar;
    static QPoint s_mainWindowPoint;
    QPoint m_windwPos;
    QPoint m_mousePos;
    QPoint m_pos;
};

#endif // BIGHOME_MUSIC_MAINWINDW_H
