#pragma once

/*
 *      Copyright (C) 2005-2013 Team XBMC
 *      http://xbmc.org
 *
 *  This Program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2, or (at your option)
 *  any later version.
 *
 *  This Program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with XBMC; see the file COPYING.  If not, see
 *  <http://www.gnu.org/licenses/>.
 *
 */

#include <atomic>
#include <list>
#include <vector>

#include "cores/IPlayer.h"
#include "threads/Thread.h"
#include "AudioDecoder.h"
#include "threads/CriticalSection.h"
#include "utils/Job.h"

#include "cores/AudioEngine/Interfaces/IAudioCallback.h"
#include "cores/AudioEngine/Utils/AEChannelInfo.h"

class IAEStream;
class CFileItem;
class CProcessInfo;

class PAPlayer : public IPlayer, public CThread, public IJobCallback
{
friend class CQueueNextFileJob;
public:
  PAPlayer(IPlayerCallback& callback);
  virtual ~PAPlayer();

  virtual bool OpenFile(const CFileItem& file, const CPlayerOptions &options) override;
  virtual bool QueueNextFile(const CFileItem &file) override;
  virtual void OnNothingToQueueNotify() override;
  virtual bool CloseFile(bool reopen = false) override;
  virtual bool IsPlaying() const override;
  virtual void Pause() override;
  virtual bool HasVideo() const override { return false; }
  virtual bool HasAudio() const override { return true; }
  virtual bool CanSeek() override;
  virtual void Seek(bool bPlus = true, bool bLargeStep = false, bool bChapterOverride = false) override;
  virtual void SeekPercentage(float fPercent = 0.0f) override;
  virtual float GetPercentage() override;
  virtual void SetVolume(float volume) override;
  virtual void SetDynamicRangeCompression(long drc) override;
  virtual void SetSpeed(float speed = 0) override;
  virtual float GetSpeed() override;
  virtual int GetCacheLevel() const override;
  virtual int64_t GetTotalTime() override;
  virtual void SetTotalTime(int64_t time) override;
  virtual void GetAudioStreamInfo(int index, SPlayerAudioStreamInfo &info) override;
  virtual int64_t GetTime() override;
  virtual void SetTime(int64_t time) override;
  virtual void SeekTime(int64_t iTime = 0) override;
  virtual void GetAudioCapabilities(std::vector<int> &audioCaps) override {}

  static bool HandlesType(const std::string &type);

  // implementation of IJobCallback
  virtual void OnJobComplete(unsigned int jobID, bool success, CJob *job) override;

  struct
  {
    char         m_codec[21];
    int64_t      m_time;
    int64_t      m_totalTime;
    int          m_channelCount;
    int          m_bitsPerSample;
    int          m_sampleRate;
    int          m_audioBitrate;
    int          m_cacheLevel;
    bool         m_canSeek;
  } m_playerGUIData;

protected:
  // implementation of CThread
  virtual void OnStartup() override {}
  virtual void Process() override;
  virtual void OnExit() override;

private:
  typedef struct
  {
    CAudioDecoder m_decoder;             /* the stream decoder */
    int64_t m_startOffset;               /* the stream start offset */
    int64_t m_endOffset;                 /* the stream end offset */
    AEAudioFormat m_audioFormat;
    unsigned int m_bytesPerSample;       /* number of bytes per audio sample */
    unsigned int m_bytesPerFrame;        /* number of bytes per audio frame */

    bool m_started;                      /* if playback of this stream has been started */
    bool m_finishing;                    /* if this stream is finishing */
    int m_framesSent;                    /* number of frames sent to the stream */
    int m_prepareNextAtFrame;            /* when to prepare the next stream */
    bool m_prepareTriggered;             /* if the next stream has been prepared */
    int m_playNextAtFrame;               /* when to start playing the next stream */
    bool m_playNextTriggered;            /* if this stream has started the next one */
    bool m_fadeOutTriggered;             /* if the stream has been told to fade out */
    int m_seekNextAtFrame;               /* the FF/RR sample to seek at */
    int m_seekFrame;                     /* the exact position to seek too, -1 for none */

    IAEStream* m_stream;                 /* the playback stream */
    float m_volume;                      /* the initial volume level to set the stream to on creation */

    bool m_isSlaved;                     /* true if the stream has been slaved to another */
    bool m_waitOnDrain;                  /* wait for stream being drained in AE */
  } StreamInfo;

  typedef std::list<StreamInfo*> StreamList;

  bool                m_signalSpeedChange;   /* true if OnPlaybackSpeedChange needs to be called */
  std::atomic_int m_playbackSpeed;           /* the playback speed (1 = normal) */
  bool                m_isPlaying;
  bool                m_isPaused;
  bool                m_isFinished;          /* if there are no more songs in the queue */
  unsigned int        m_defaultCrossfadeMS;  /* how long the default crossfade is in ms */
  unsigned int        m_upcomingCrossfadeMS; /* how long the upcoming crossfade is in ms */
  CEvent              m_startEvent;          /* event for playback start */
  StreamInfo*         m_currentStream;       /* the current playing stream */
  IAudioCallback*     m_audioCallback;       /* the viz audio callback */

  CFileItem*          m_FileItem;            /* our queued file or current file if no file is queued */      

  CCriticalSection    m_streamsLock;         /* lock for the stream list */
  StreamList          m_streams;             /* playing streams */  
  StreamList          m_finishing;           /* finishing streams */
  int                 m_jobCounter;
  CEvent              m_jobEvent;
  bool                m_continueStream;
  int64_t             m_newForcedPlayerTime;
  int64_t             m_newForcedTotalTime;
  std::unique_ptr<CProcessInfo> m_processInfo;

  bool QueueNextFileEx(const CFileItem &file, bool fadeIn = true, bool job = false);
  void SoftStart(bool wait = false);
  void SoftStop(bool wait = false, bool close = true);
  void CloseAllStreams(bool fade = true);
  void ProcessStreams(double &freeBufferTime);
  bool PrepareStream(StreamInfo *si);
  bool ProcessStream(StreamInfo *si, double &freeBufferTime);
  bool QueueData(StreamInfo *si);
  int64_t GetTotalTime64();
  void UpdateCrossfadeTime(const CFileItem& file);
  void UpdateStreamInfoPlayNextAtFrame(StreamInfo *si, unsigned int crossFadingTime);
  void UpdateGUIData(StreamInfo *si);
  int64_t GetTimeInternal();
  void SetTimeInternal(int64_t time);
  void SetTotalTimeInternal(int64_t time);
};

