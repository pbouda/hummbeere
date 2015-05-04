#include <QAudioRecorder>
#include <QUrl>

#include "audiorecorder.h"

AudioRecorder::AudioRecorder(QObject *parent) : QObject(parent)
{
    audioRecorder = new QAudioRecorder(this);

    foreach (const QString &device, audioRecorder->audioInputs()) {
        QString description = audioRecorder->audioInputDescription(device);
        qDebug() << description;
    }

    foreach (const QString &codecName, audioRecorder->supportedAudioCodecs()) {
        qDebug() << codecName;
    }

    foreach (const QString &containerName, audioRecorder->supportedContainers()) {
        qDebug() << containerName;
    }
}

QStringList AudioRecorder::inputs() const
{
    QStringList inputs;
    inputs.append("Default");
    foreach (const QString &device, audioRecorder->audioInputs()) {
        inputs.append(device);
    }
    return inputs;
}

QStringList AudioRecorder::codecs() const
{

}

QStringList AudioRecorder::containers() const
{

}

QStringList AudioRecorder::sampleRates() const
{

}

QStringList AudioRecorder::channels() const
{

}

QString AudioRecorder::input() const
{

}

void AudioRecorder::setInput(QString input)
{

}

QString AudioRecorder::codec() const
{

}

void AudioRecorder::setCodec(QString codec)
{

}

QString AudioRecorder::container() const
{

}

void AudioRecorder::setContainer(QString container)
{

}

QString AudioRecorder::sampleRate() const
{

}

void AudioRecorder::setSampleRate(QString sampleRate)
{

}

QString AudioRecorder::channel() const
{

}

void AudioRecorder::setChannel(QString channel)
{

}

void AudioRecorder::record()
{
    if (audioRecorder->state() != QMediaRecorder::StoppedState) {
        stop();
    }

    qDebug() << "Start recording";

    QAudioEncoderSettings audioSettings;
    audioSettings.setCodec("audio/speex");
    audioSettings.setSampleRate(32000);
    audioSettings.setBitRate(16);
    audioSettings.setChannelCount(1);
    audioSettings.setQuality(QMultimedia::VeryHighQuality);
    audioSettings.setEncodingMode(QMultimedia::ConstantQualityEncoding);

    audioRecorder->setEncodingSettings(audioSettings);

    audioRecorder->setOutputLocation(QUrl::fromLocalFile("test.speex"));
    audioRecorder->record();
}

void AudioRecorder::stop()
{
    qDebug() << "Stop recording";
    audioRecorder->stop();
}

void AudioRecorder::pause()
{

}

AudioRecorder::~AudioRecorder()
{
    delete audioRecorder;
}
