#include <QAudioRecorder>
#include "audiorecorder.h"

AudioRecorder::AudioRecorder(QObject *parent) : QObject(parent)
{
    audioRecorder = new QAudioRecorder(this);
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

}

void AudioRecorder::stop()
{

}

void AudioRecorder::pause()
{

}

AudioRecorder::~AudioRecorder()
{
    delete audioRecorder;
}
