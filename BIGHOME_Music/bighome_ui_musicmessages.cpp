#include "bighome_ui_musicmessages.h"
#include <QDebug>

BIGHOME_UI_Musicmessages::BIGHOME_UI_Musicmessages(QWidget *parent)
    : QWidget(parent)
{
  ui.setupUi(this);
  init();
  setStyle();
}

BIGHOME_UI_Musicmessages::~BIGHOME_UI_Musicmessages()
{

}
void BIGHOME_UI_Musicmessages::init()
{
  this->setMaximumHeight(92);
  this->setMinimumHeight(92);
  ui.nowPlayMusic->setText(tr("正在播放："));
  ui.nowPlayMusicName->setText(tr("海阔天空——Beyond"));
}
void BIGHOME_UI_Musicmessages::setStyle()
{ 
  ui.time->setStyleSheet("QSlider::groove:horizontal {border: 1px solid #999999; background: #535353; background: qlineargradient(x1:0.4, y1:0, x2:0.4, y2:0.4, stop:0 #000000, stop:1 #e0e0e0); height: 5px; left: 1px; right: 1px;border-radius: 3px;}  width: 9px; Height: 23px; margin: -9px -9px -9px -9px;} QSlider::sub-page:horizontal{background: #ccc; border-radius: 3px;}");
}
void BIGHOME_UI_Musicmessages::setMusicName(QString name)
{
  ui.nowPlayMusicName->setText(name);
}
void BIGHOME_UI_Musicmessages::setMusicTime(qint64 time)
{
  QString temp  =SSHHMMInt64(time);
  ui.nowPlayMusicTime->setText(temp);
}
void BIGHOME_UI_Musicmessages::setSliderMusicTime(qint64 value)
{
  ui.time->setValue(value);
}
void BIGHOME_UI_Musicmessages::setSliderMaxMusicTime(qint64 value)
{
  //ui.time->setMaximum(value);
}
QString BIGHOME_UI_Musicmessages::SSHHMMInt64(qint64 value)
{
  int hour = 0;
  int minute = 0;
  int second = 0;
  
  second = value / 1000;
  if (second > 60)
  {
    minute = second / 60;
    second = second % 60;
  }
  if (minute > 60)
  {
    hour = minute / 60;
    minute = minute % 60;
  }
  QString time = tr("%1 : %2 ").arg(minute).arg(second);
  qDebug() << "musicTime"<<time;
  return time;
}