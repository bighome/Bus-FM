#include "bighome_radio_hhmmss.h"

BIGHOME_Radio_HHMMSS::BIGHOME_Radio_HHMMSS(QObject *parent)
  : QObject(parent)
{

}

BIGHOME_Radio_HHMMSS::~BIGHOME_Radio_HHMMSS()
{

}
QString BIGHOME_Radio_HHMMSS::SSHHMMInt64(qint64 value)
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
  return time;
}
