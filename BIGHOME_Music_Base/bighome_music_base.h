#ifndef BIGHOME_MUSIC_BASE_H
#define BIGHOME_MUSIC_BASE_H

#include "bighome_music_base_global.h"
#include <phonon/MediaObject>
#include <phonon/MediaSource>
#include <phonon/AudioOutput>
#include <phonon/SeekSlider>
#include <QString>
#include <QList>
#include <QStringList>
#include <QObject>
#include <QUrl>
#include <QTimer>

class BIGHOME_MUSIC_BASE_EXPORT BIGHOME_Music_Base:public QObject
{
   Q_OBJECT
public:
  BIGHOME_Music_Base(QObject *parent);
    ~BIGHOME_Music_Base();
    bool addFiles(QStringList fileList);
    bool addFiles(QList<QUrl> URLlist);
    void MusicPlay();
    void MusicPush();
    void MusicEnd();
    bool getPlayBool();
private:
  Phonon::MediaObject* m_mediaObject;
  Phonon::AudioOutput* m_audioOutput;
  Phonon::SeekSlider* m_seekSlider;
  QList<Phonon::MediaSource> m_mediaSourceList;
  QTimer *m_timer;
  bool m_playBool;
 private slots:
    void slotsMusicTimer();
    void slotsTotalTime(qint64 time);
    void slotsMusicFlished();
signals:
  void signalMusicTime(qint64 time);
  void signalMusicTotalTime(qint64 time);
  void signalMusicCurrentTime(qint64 time);
  void signalMusicFlished();

};

#endif // BIGHOME_MUSIC_BASE_H
