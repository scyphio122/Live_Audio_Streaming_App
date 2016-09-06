#ifndef FFTCALCULATOR_H
#define FFTCALCULATOR_H

#include <stdint-gcc.h>
#include <QVector>
#include <complex.h>
#include <QObject>
#include <QMutex>

#ifndef M_PI
    #define M_PI   3.14159265358979323846d
#endif

/**
 * @brief The FftCalculator class - This class is responsible for calculating the FFT for the input signal.
 */


class FftCalculator : public QObject
{
    Q_OBJECT

private:
    int         inputArrayIndex = 0;
    int16_t*    inputArray = nullptr;
    Complex*    outputArray = nullptr;
    uint16_t    inputArraySize = 0;
    uint16_t    outputArraySize = 0;
    bool        fftEnabled = true;

    /**
     * @brief recursiveFFT - This method is recursively called on smaller and smaller data inputs(subarray)
     * @param subarray[in] - the input array for each step. It decreases by half each time
     * @param subarraySize[in] - size of an subarray
     * @param step[in] - step needed for the FFT alghoritm
     * @return pointer to the calculated FFT output array
     */
    Complex*    recursiveFFT(int16_t subarray[], uint16_t subarraySize, unsigned long step = 1);

public:
    FftCalculator();
    ~FftCalculator();

    /**
     * @brief setInputArray - This function sets the input array
     * @param array[in]
     */
    void        setInputArray(int16_t *array);

    /**
     * @brief setOutputArray Setter for the buffer where the output FFT will be held
     * @param array[in]
     */
    void        setOutputArray(Complex* array);

    /**
     * @brief setInputArraySize - setter for input array size
     * @param size[in]
     */
    void        setInputArraySize(uint16_t size);

    /**
     * @brief setOutputArraySize - setter for output array size
     * @param size[in]
     */
    void        setOutputArraySize(uint16_t size);

    /**
     * @brief getInputArray - getter for an input array
     * @return pointer to the input array
     */
    int16_t*    getInputArray();

    /**
     * @brief getOutputArray - getter for an output array
     * @return pointer to the output array
     */
    Complex*    getOutputArray();

    /**
     * @brief getInputArraySize - getter for an input array's size
     * @return input array's size
     */
    uint16_t    getInputArraySize();

    /**
     * @brief getOutputArraySize - getter for an output array's size
     * @return output array's size
     */
    uint16_t    getOutputArraySize();

    /**
     * @brief getOutputElement - getter for a single element(Complex number) from the output array
     * @param index[in] - the index of the requested number
     * @return complex number
     */
    Complex     getOutputElement(uint32_t index);

    /**
     * @brief runTransform - This function starts synchroneous FFT alghoritm.
     */
    void        runTransform();

    /**
     * @brief getFftEnable - getter for FFT status
     * @return true if FFT is enabled
     */
    bool        getFftEnable();

public slots:
    /**
     * @brief fftEnable - This function enables/disables the possibility of running the FFT alghoritm. It is disabled, when GUI is currently redrawing in order to avoid overwriting the currently used buffer
     * @param value true if enabled
     */
    void        fftEnable(bool value);

signals:
    void        fftCompleted(Complex* outputArray, int outputArraySize); /*< This signal is emitted when FFT is completed */
};



#endif // FFTCALCULATOR_H
