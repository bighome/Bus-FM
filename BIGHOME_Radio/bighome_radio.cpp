#include <QPainter>
#include "bighome_radio_hhmmss.h"
#include "bighome_radio.h"

QPoint BIGHOME_Radio::s_mainWindowPoint;
bool BIGHOME_Radio::s_playORstop = true;
BIGHOME_Radio::BIGHOME_Radio(QWidget *parent, Qt::WFlags flags)
    : QWidget(parent, flags)
    ,m_musicBase(NULL)
    ,m_musicNetwork(NULL)
    ,m_networkLoadResources(NULL)
{
  ui.setupUi(this);
  init();
  this->setWindowFlags(Qt::FramelessWindowHint|Qt::WindowStaysOnTopHint);
  this->setAttribute(Qt::WA_TranslucentBackground);
  if (m_musicBase == NULL)
  {
    m_musicBase = new BIGHOME_Music_Base(this);
  }
  if (m_musicNetwork == NULL)
  {
    m_musicNetwork = new BIGHOME_Music_netWork(this);
  }
  if (m_networkLoadResources == NULL)
  {
    m_networkLoadResources = new BIGHOME_NetWork_loadResources(this);
  }
  m_musicNetwork->setMusicDate(QString("1"), QString(""));
  connect(ui.x, SIGNAL(clicked()), qApp, SLOT(quit()));
  connect(ui.play, SIGNAL(clicked()), this, SLOT(playMusic()));
  connect(ui.next, SIGNAL(clicked()), this, SLOT(nextMusic()));
  connect(m_musicNetwork, SIGNAL(signalsGetMusicMessage(bool, QList<QMap<QString, QString>>)), this, SLOT(slotsMusicListUrl(bool, QList<QMap<QString, QString>>)));
  connect(m_musicBase, SIGNAL(signalMusicTotalTime(qint64 )), this, SLOT(slotsMusicTotalTime(qint64 )));
  connect(m_musicBase, SIGNAL(signalMusicCurrentTime(qint64 )), this, SLOT(slotsMusicCurrentTime(qint64 )));
}

BIGHOME_Radio::~BIGHOME_Radio()
{
  delete m_musicBase;
  delete m_musicNetwork;
  delete m_networkLoadResources;
}
void BIGHOME_Radio::init()
{
  ui.c->setText("");
  ui.x->setText("");
  ui.s->setText("");
  ui.play->setText("");
  ui.next->setText("");
  ui.like->setText("");
  ui.deletes->setText("");
  ui.photoLb->setText("");
  ui.photoLb->setPixmap(QPixmap(".//Resources//load.png"));
  ui.c->setStyleSheet("QPushButton {border: none; border-image:url(.//Resources//skin.png);}");
  ui.s->setStyleSheet("QPushButton {border: none; border-image:url(.//Resources//user.png);}");
  ui.x->setStyleSheet("QPushButton {border: none; border-image:url(.//Resources//closed.png);}");
  ui.timerSlider->setStyleSheet("QSlider::groove:horizontal {border: 1px solid rgb(0, 0, 60); background: rgb(0, 0, 60); background: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 rgb(16, 61, 99), stop:1 rgb(16, 61, 99)); height: 5px; left: 1px; right: 1px;border-radius: 3px;}  width: 9px; Height: 23px; margin: -9px -9px -9px -9px;} QSlider::sub-page:horizontal{background: rgb(255, 255, 255); border-radius: 3px;}");
  if (s_playORstop)
  {
  ui.play->setStyleSheet("QPushButton {border: none; border-image:url(.//Resources//Pause.png);}");
  }else
    ui.play->setStyleSheet("QPushButton {border: none; border-image:url(.//Resources//play.png);}");

  ui.next->setStyleSheet("QPushButton {border: none; border-image:url(.//Resources//next.png);}");
  ui.like->setStyleSheet("QPushButton {border: none; border-image:url(.//Resources//like.png);}");
  ui.deletes->setStyleSheet("QPushButton {border: none; border-image:url(.//Resources//delete.png);}");
}
void BIGHOME_Radio::playMusic()
{
  if (!s_playORstop)
  {
    m_musicBase->MusicPlay();
    ui.play->setStyleSheet("QPushButton {border: none; border-image:url(.//Resources//Pause.png);}");
    s_playORstop = true;
  }else
  {
    m_musicBase->MusicPush();
    ui.play->setStyleSheet("QPushButton {border: none; border-image:url(.//Resources//play.png);}");
    s_playORstop = false;
  }
}
void BIGHOME_Radio::nextMusic()
{

}
void BIGHOME_Radio::slotsMusicTotalTime(qint64 value)
{
  ui.time1->setText(BIGHOME_Radio_HHMMSS::SSHHMMInt64(value));
}
void BIGHOME_Radio::slotsMusicCurrentTime(qint64 value)
{
  ui.time2->setText(BIGHOME_Radio_HHMMSS::SSHHMMInt64(value));
  ui.timerSlider->setValue(value / 1000);
}
void BIGHOME_Radio::slotsMusicListUrl(bool ok, QList<QMap<QString, QString>> value)
{

  QList<QUrl> tempUrl;
  if (ok)
  {
    m_musicMap = value;
    if (!tempUrl.isEmpty())
    {
      tempUrl.clear();
    }
    for (int i =0; i< value.size(); i++)
    {
      tempUrl << QUrl(value.at(i).value("url"));
    }
    s_playORstop = m_musicBase->addFiles(tempUrl);
    //m_musicNameORSinger = QString("%1--%2").arg(m_musicMap.at(0).value("title")).arg(m_musicMap.at(0).value("artist"));
    m_musicNameORSinger = QString("%1").arg(m_musicMap.at(0).value("title"));
    ui.name->setText(m_musicNameORSinger);
    m_networkLoadResources->loadNetWorkImg(QUrl(m_musicMap.at(0).value("picture")));
    connect(m_networkLoadResources, SIGNAL(signalsGetLoadImg(QPixmap )), this, SLOT(slotsLoadIMG(QPixmap )));
  }
}
void BIGHOME_Radio::slotsLoadIMG(QPixmap photo)
{
  if (!photo.isNull())
  {
    ui.photoLb->setScaledContents(true);
    ui.photoLb->setPixmap(photo);
  }
}


void BIGHOME_Radio::paintEvent(QPaintEvent *event)
{
  QPainter p(this);  
  QPixmap pix(".//Resources//bg.png");
  if (!pix.isNull())
  {
    p.drawPixmap(0, 0, width(), height(), pix);
  }
}
void BIGHOME_Radio::mousePressEvent(QMouseEvent *event)
{
  m_windwPos = this->pos();
  m_mousePos = event->globalPos();
  m_pos = m_mousePos - m_windwPos;
}
void BIGHOME_Radio::mouseMoveEvent(QMouseEvent *event)
{
  this->move(event->globalPos() - m_pos);
}
void BIGHOME_Radio::changeEvent(QEvent *e)
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
void BIGHOME_Radio::moveEvent ( QMoveEvent * event )
{
  s_mainWindowPoint = event->pos();
}