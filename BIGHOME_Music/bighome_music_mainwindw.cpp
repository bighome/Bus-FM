#include "bighome_music_mainwindw.h"
#include <QVBoxLayout>
#include "bighome_ui_mainwindw_playmanager.h"
#include "bighome_ui_mainwindw_messagemanager.h"
#include "bighome_ui_mainwindow_titlebar.h"
#include "bighome_ui_mainwindw_musiclistmanager.h"

BIGHOME_Music_mainWindw *BIGHOME_Music_mainWindw::s_getInterFace = NULL;
 QPoint BIGHOME_Music_mainWindw::s_mainWindowPoint ;
 BIGHOME_Music_mainWindw *BIGHOME_Music_mainWindw::getInterFace()
 {
    if (s_getInterFace == NULL)
    {
      s_getInterFace = new BIGHOME_Music_mainWindw;
    }
    return s_getInterFace;
 }
BIGHOME_Music_mainWindw::BIGHOME_Music_mainWindw(QWidget *parent)
    : QWidget(parent)
    ,m_palyManagerMainwindw(NULL)
    ,m_messageManager(NULL)
    ,m_mainwindowTitlebar(NULL)
{
  ui.setupUi(this);
  init();
}

BIGHOME_Music_mainWindw::~BIGHOME_Music_mainWindw()
{
    if (m_palyManagerMainwindw != NULL && m_messageManager != NULL && m_mainwindowTitlebar != NULL)
    {
      delete m_palyManagerMainwindw;
      delete m_messageManager;
      delete m_mainwindowTitlebar;
    }
}
void BIGHOME_Music_mainWindw::init()
{
  this->setWindowFlags(Qt::FramelessWindowHint|Qt::WindowStaysOnTopHint);
  this->setAttribute(Qt::WA_TranslucentBackground);
  this->setMaximumSize(QSize(417, 260));
  this->setMinimumSize(QSize(417, 260));
  if (m_palyManagerMainwindw == NULL && m_messageManager == NULL && m_mainwindowTitlebar == NULL)
  {
    //m_palyManagerMainwindw = new BIGHOME_UI_MainWindw_PlayManager;
    //m_messageManager = BIGHOME_UI_MainWindw_messageManager::getInterface();
    m_mainwindowTitlebar = new BIGHOME_UI_MainWindow_titleBar;
  }
  m_mainwindowTitlebar->setGeometry(0,0,width(),15);
  QVBoxLayout *layout = new QVBoxLayout;
  layout->addWidget(m_mainwindowTitlebar);
  //layout->addWidget(m_messageManager);
  //layout->addWidget(m_palyManagerMainwindw);
  layout->setContentsMargins(35, 1,0, 20);
  this->setLayout(layout);
}
void BIGHOME_Music_mainWindw::paintEvent(QPaintEvent *event)
{
  QPainter p(this);  
  //p.drawRoundedRect(0, 0, width() - 1, height() - 3, 5, 5);  
  QPixmap pix(".//Resources//BgPix.png");
  if (!pix.isNull())
  {
    p.drawPixmap(0, 0, width() + 2, height(), pix);
  }
}
void BIGHOME_Music_mainWindw::mousePressEvent(QMouseEvent *event)
{
  m_windwPos = this->pos();
  m_mousePos = event->globalPos();
  m_pos = m_mousePos - m_windwPos;
}
void BIGHOME_Music_mainWindw::mouseMoveEvent(QMouseEvent *event)
{ 
  this->move(event->globalPos() - m_pos);
  BIGHOME_UI_MainWindw_MusicListManager::getInterFace()->setMainWindowPos((event->globalPos() - m_pos).x() - 6, (event->globalPos() - m_pos).y() + 1);
  BIGHOME_UI_MainWindw_MusicListManager::getInterFace()->setMusicListWindowOpen(false);
}
void BIGHOME_Music_mainWindw::changeEvent(QEvent *e)
{       
  QWidget::changeEvent(e);
  switch (e->type())
  {
      case QEvent::LanguageChange:
        ui.retranslateUi(this);
        break;
      default:
        break;
  }
}
void BIGHOME_Music_mainWindw::moveEvent ( QMoveEvent * event )
{
  s_mainWindowPoint = event->pos();
}
QPoint BIGHOME_Music_mainWindw::getMainWindwPos()
{
  return s_mainWindowPoint;
}