#ifndef AUDIORECORDER_H
#define AUDIORECORDER_H

#include <QStringList>

class QAudioRecorder;

class AudioRecorder : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QStringList inputs READ inputs)
    Q_PROPERTY(QStringList codecs READ codecs)
    Q_PROPERTY(QStringList containers READ containers)
    Q_PROPERTY(QStringList sampleRates READ sampleRates)
    Q_PROPERTY(QStringList channels READ channels)

    Q_PROPERTY(QString input READ input WRITE setInput)
    Q_PROPERTY(QString codec READ codec WRITE setCodec)
    Q_PROPERTY(QString container READ container WRITE setContainer)
    Q_PROPERTY(QString sampleRate READ sampleRate WRITE setSampleRate)
    Q_PROPERTY(QString channel READ channel WRITE setChannel)

public:
    explicit AudioRecorder(QObject *parent = 0);
    ~AudioRecorder();

    QStringList inputs() const;
    QStringList codecs() const;
    QStringList containers() const;
    QStringList sampleRates() const;
    QStringList channels() const;

    QString input() const;
    void setInput(QString input);
    QString codec() const;
    void setCodec(QString codec);
    QString container() const;
    void setContainer(QString container);
    QString sampleRate() const;
    void setSampleRate(QString sampleRate);
    QString channel() const;
    void setChannel(QString channel);

signals:

public slots:
    void record();
    void stop();
    void pause();

private:
    QAudioRecorder *audioRecorder;

};

#endif // AUDIORECORDER_H
