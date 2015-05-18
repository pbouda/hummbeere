#include <QAudioRecorder>
#include <QUrl>

#include "audiorecorder.h"

AudioRecorder::AudioRecorder(QObject *parent) : QObject(parent)
{
    audioRecorder = new QAudioRecorder(this);

    QStringList inputs = audioRecorder->audioInputs();
    foreach (const QString &device, inputs) {
        QString description = audioRecorder->audioInputDescription(device);
        qDebug() << description;
    }
    int useInput = 0;
    audioRecorder->setAudioInput(inputs[useInput]);
    qDebug() << "Using index " << useInput << ", name " << audioRecorder->audioInputDescription(inputs[useInput]);
}

QStringList AudioRecorder::inputs() const
{
    QStringList inputs;
    foreach (const QString &device, audioRecorder->audioInputs()) {
        inputs.append(device);
    }
    return inputs;
}

QStringList AudioRecorder::codecs() const
{
    QStringList codecs;
    foreach (const QString &codecName, audioRecorder->supportedAudioCodecs()) {
        codecs.append(codecName);
    }
    return codecs;
}

QStringList AudioRecorder::containers() const
{
    QStringList containers;
    foreach (const QString &containerName, audioRecorder->supportedContainers()) {
        containers.append(containerName);
    }
    return containers;
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
    audioSettings.setCodec("audio/PCM");
    audioSettings.setSampleRate(48000);
    audioSettings.setBitRate(16);
    audioSettings.setChannelCount(2);
    //audioSettings.setQuality(QMultimedia::VeryHighQuality);
    //audioSettings.setEncodingMode(QMultimedia::ConstantQualityEncoding);

    audioRecorder->setEncodingSettings(audioSettings);
    audioRecorder->setContainerFormat("wav");

    audioRecorder->setOutputLocation(QUrl::fromLocalFile("test.wav"));
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
