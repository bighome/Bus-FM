#ifndef BIGHOME_RADIO_HHMMSS_H
#define BIGHOME_RADIO_HHMMSS_H

#include <QObject>
#include <QString>

class BIGHOME_Radio_HHMMSS : public QObject
{
  Q_OBJECT

public:
  BIGHOME_Radio_HHMMSS(QObject *parent);
  ~BIGHOME_Radio_HHMMSS();
  static QString SSHHMMInt64(qint64 value);
  
};

#endif // BIGHOME_RADIO_HHMMSS_H
