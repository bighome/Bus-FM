#include "bighome_ui_mainwindw_musiclistmanager.h"
#include "bighome_music_mainwindw.h"
#include <QPainter>
#include <QPixmap>

BIGHOME_UI_MainWindw_MusicListManager *BIGHOME_UI_MainWindw_MusicListManager::s_getInterFace = NULL;
bool BIGHOME_UI_MainWindw_MusicListManager::s_OpenList = false;
int BIGHOME_UI_MainWindw_MusicListManager::s_windowX = 0;
int BIGHOME_UI_MainWindw_MusicListManager::s_windowY = 0;

BIGHOME_UI_MainWindw_MusicListManager *BIGHOME_UI_MainWindw_MusicListManager::getInterFace()
{
  if (s_getInterFace == NULL)
  {
    s_getInterFace = new BIGHOME_UI_MainWindw_MusicListManager;
  }
  return s_getInterFace;
}
BIGHOME_UI_MainWindw_MusicListManager::BIGHOME_UI_MainWindw_MusicListManager(QWidget *parent)
    : QDockWidget(parent)
{
  ui.setupUi(this);
  init();
  setStyle();
}

BIGHOME_UI_MainWindw_MusicListManager::~BIGHOME_UI_MainWindw_MusicListManager()
{

}
void BIGHOME_UI_MainWindw_MusicListManager::init()
{
   this->setWindowFlags(Qt::FramelessWindowHint);
  this->setAttribute(Qt::WA_TranslucentBackground);
  m_testMusicList<< tr("Ë½ÈËµçÌ¨")<< tr("¹«¹²µçÌ¨") << tr ("DJµçÌ¨") << tr("¸ü¶àµçÌ¨");
  M_testMusicList1<<tr("ÐÂ¸è") <<tr("»ªÓï") <<tr("¿§·ÈÌü") <<tr("Å·ÃÀ") <<tr("ÇáÒôÀÖ") <<tr("ÔÁÓï") <<tr("°ËÁã");
  ui.listWidget->addItems(m_testMusicList);
  ui.sublistWidget->addItems(M_testMusicList1);
  ui.listWidget->setUniformItemSizes(true);
  ui.sublistWidget->setUniformItemSizes(true);
}
void BIGHOME_UI_MainWindw_MusicListManager::setStyle()
{
   ui.listWidget->setStyleSheet("QListView {background-color: rgb(255, 255, 255, 0); border: none; font: 10pt 'Î¢ÈíÑÅºÚ'; color: rgb(255, 255, 255);}  QListView::item:alternate {background: #EEEEEE;}QListView::item:selected {font: 10pt 'Î¢ÈíÑÅºÚ'; color: #45b97c; border-image:url(.//Resources//list.png);}");
   ui.sublistWidget->setStyleSheet(" QListView {background-color: rgb(255, 255, 255, 0); border: none; font: 10pt 'Î¢ÈíÑÅºÚ'; color: rgb(255, 255, 255);}  QListView::item:alternate {background: #EEEEEE;}QListView::item:selected {border: 1px solid #6a6ea9;} QListView::item:selected:!active {background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 #ABAFE5, stop: 1 #8588B2);}QListView::item:selected:active {background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 #6a6ea9, stop: 1 #888dd9);} ListView:item {background-color: rgb(105, 105, 105);}");
}
void BIGHOME_UI_MainWindw_MusicListManager::paintEvent(QPaintEvent *event)
{
  QPainter p(this);  
  QPixmap pix(".//Resources//BgmusicManager.png");
  if (!pix.isNull())
  {
    p.drawPixmap(0, 0, width(), height(), pix);
  }
}
void BIGHOME_UI_MainWindw_MusicListManager::mousePressEvent(QMouseEvent *event)
{
  
  if (s_OpenList)
  {
    for (int i = 1; i <= width() -10; i++)
    {
       move(m_windowX + i, s_windowY);
       s_OpenList = false;
    }
  }else
  {
    for (int i = 1; i<=width() - 10;i++)
    {
      move(s_windowX-i, s_windowY);
      s_OpenList = true;
      m_windowX = s_windowX - i;
    }
  }
}
void BIGHOME_UI_MainWindw_MusicListManager::setMainWindowPos(int x, int y)
{
  s_windowX = x;
  s_windowY = y;
  move(s_windowX, s_windowY);
}
bool BIGHOME_UI_MainWindw_MusicListManager::getMusicListWindowOpen()
{
  return s_OpenList;
}
void BIGHOME_UI_MainWindw_MusicListManager::setMusicListWindowOpen(bool vlaue)
{
  s_OpenList = vlaue;
}
void BIGHOME_UI_MainWindw_MusicListManager::setMusicAdditems(QStringList value)
{
  ui.listWidget->addItems(value);
}
void BIGHOME_UI_MainWindw_MusicListManager::setMusicListAdditems(QStringList value)
{
  ui.sublistWidget->addItems(value);
}