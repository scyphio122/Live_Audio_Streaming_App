#include "audiodevicelister.h"
#include <QMessageBox>
AudioDeviceLister::AudioDeviceLister()
{

}

QAudioDeviceInfo AudioDeviceLister::listAudioDevices(std::string deviceName, QAudio::Mode mode)
{
    bool audioMixerFound = false;
    QList<QAudioDeviceInfo> devices = QAudioDeviceInfo::availableDevices(mode);
    QAudioDeviceInfo audioDeviceInfo;

    for(int i=0; i<devices.size(); i++)
    {
        if(devices[i].deviceName().toStdString() == deviceName)
        {
            audioDeviceInfo = devices[i];
            audioMixerFound = true;
            break;
        }
    }

    return audioDeviceInfo;
}

QAudioFormat AudioDeviceLister::getFormat(QAudioDeviceInfo audioDeviceInfo, std::string codec = "audio/pcm")
{
    QAudioFormat desiredFormat;
    desiredFormat.setChannelCount(2);
    desiredFormat.setCodec("audio/pcm");
    desiredFormat.setSampleType(QAudioFormat::SignedInt);
    desiredFormat.setSampleRate(48000);
    desiredFormat.setSampleSize(16);
    desiredFormat = audioDeviceInfo.nearestFormat(desiredFormat);
    bool isSupported = audioDeviceInfo.isFormatSupported(desiredFormat);
    return desiredFormat;
}

QList<QAudioDeviceInfo> AudioDeviceLister::listAvailableDevicesIn()
{
    return QAudioDeviceInfo::availableDevices(QAudio::AudioInput);
}

QList<QAudioDeviceInfo> AudioDeviceLister::listAvailableDevicesOut()
{
    return QAudioDeviceInfo::availableDevices(QAudio::AudioOutput);
}
