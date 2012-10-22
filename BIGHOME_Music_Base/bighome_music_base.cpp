#include "bighome_music_base.h"
#include "QTimer"
#include "QDebug"

BIGHOME_Music_Base::BIGHOME_Music_Base(QObject *parent)
  : QObject(parent)
{
  m_audioOutput = new Phonon::AudioOutput(parent);
  m_mediaObject = new Phonon::MediaObject(parent);
   Phonon::createPath(m_mediaObject, m_audioOutput);
   m_timer = new QTimer(this);
   connect(m_timer, SIGNAL(timeout()), this, SLOT(slotsMusicTimer()));
   connect(m_mediaObject, SIGNAL(totalTimeChanged(qint64 )), this, SLOT(slotsTotalTime(qint64 )));
   connect(m_mediaObject,SIGNAL(finished()), this, SLOT(slotsMusicFlished()));
   m_timer->start(1000);
}

BIGHOME_Music_Base::~BIGHOME_Music_Base()
{

}
bool BIGHOME_Music_Base::addFiles(QStringList fileList)
{
  QString file;
  foreach(file , fileList)
  {
      m_mediaSourceList.append(file);
  }
  if (!m_mediaSourceList.isEmpty())
  {
    m_mediaObject->setQueue(m_mediaSourceList);
    return true;
  }
  return false;
}

bool BIGHOME_Music_Base::addFiles(QList<QUrl> URLlist)
{
  if (!URLlist.isEmpty())
  {
    m_mediaObject->setQueue(URLlist);
    m_mediaObject->play();
    return true;
  }
  return false;
}
void BIGHOME_Music_Base::MusicPlay()
{
      m_mediaObject->play();
}
void BIGHOME_Music_Base::MusicPush()
{
  m_mediaObject->pause();
}
void BIGHOME_Music_Base::MusicEnd()
{
  m_mediaObject->stop();
}
void BIGHOME_Music_Base::slotsMusicTimer()
{
  //emit signalMusicTotalTime(m_mediaObject->totalTime());
  emit signalMusicTime(m_mediaObject->remainingTime());
  emit signalMusicCurrentTime(m_mediaObject->currentTime());
}
void BIGHOME_Music_Base::slotsTotalTime(qint64 time)
{
  emit signalMusicTotalTime(time);
}
void BIGHOME_Music_Base::slotsMusicFlished()
{
  emit signalMusicFlished();
}
bool BIGHOME_Music_Base::getPlayBool()
{
  return true;
}
