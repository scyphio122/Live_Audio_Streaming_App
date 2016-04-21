#ifndef AUDIODEVICELISTER_H
#define AUDIODEVICELISTER_H

#include <QList>
#include <QAudioDeviceInfo>
#include <string>
#include <QAudio>

class AudioDeviceLister
{
public:
    AudioDeviceLister();
    static QAudioDeviceInfo         listAudioDevices(std::string deviceName, QAudio::Mode mode);
    static QAudioFormat             getFormat(QAudioDeviceInfo audioDeviceInfo, std::string codec);
    static QList<QAudioDeviceInfo>  listAvailableDevicesIn();
    static QList<QAudioDeviceInfo>  listAvailableDevicesOut();
};

#endif // AUDIODEVICELISTER_H
