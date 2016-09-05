#ifndef AUDIODEVICELISTER_H
#define AUDIODEVICELISTER_H

#include <QList>
#include <QAudioDeviceInfo>
#include <string>
#include <QAudio>

/**
 * @brief The AudioDeviceLister class - This class is utilized in order to list input and output audio devices
 */
class AudioDeviceLister
{
public:
    AudioDeviceLister();

    /**
     * @brief listAudioDevices - This function gets device information, based on its name and mode. It is used to create QAudioInput and QAudioOutput objects
     * @param deviceName[in] - The name of the device as std::string
     * @param mode[in] - the type of the device. { AudioInput, AudioOutput };
     * @return QAudioDeviceInfo of the chosen device
     */
    static QAudioDeviceInfo         listAudioDevices(std::string deviceName, QAudio::Mode mode);

    /**
     * @brief getFormat - This function returns the most accurate format for the device with the given audioDeviceInfo and codec
     * @param audioDeviceInfo[in] - Info about the device for which the format is searched
     * @param codec[in] - the codec which is to be used
     * @return QAudioFormat
     */
    static QAudioFormat             getFormat(QAudioDeviceInfo audioDeviceInfo, std::string codec);

    /**
     * @brief listAvailableDevicesIn - Lists all the available audio input devices
     * @return
     */
    static QList<QAudioDeviceInfo>  listAvailableDevicesIn();

    /**
     * @brief listAvailableDevicesOut - Lists all the available audio output devices
     * @return
     */
    static QList<QAudioDeviceInfo>  listAvailableDevicesOut();
};

#endif // AUDIODEVICELISTER_H
