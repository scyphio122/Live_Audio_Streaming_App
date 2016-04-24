#ifndef FFTCALCULATOR_H
#define FFTCALCULATOR_H

#include <stdint-gcc.h>
#include <QVector>
#include <complex.h>
#include <QObject>

#define M_PI    3.14159265358979323846d

class FftCalculator : public QObject
{
    Q_OBJECT

private:
    int         inputArrayIndex = 0;
    int16_t*    inputArray;
    Complex*    outputArray = nullptr;
    uint16_t    inputArraySize;
    uint16_t    outputArraySize;
    bool        fftArrayUsedByGui = false;

    Complex*    recursiveFFT(int16_t subarray[], uint16_t subarraySize, unsigned long step = 1);

public:
    FftCalculator();
    ~FftCalculator();

    void        setInputArray(int16_t *array);
    void        setOutputArray(Complex* array);
    void        setInputArraySize(uint16_t size);
    void        setOutputArraySize(uint16_t size);
    int16_t*    getInputArray();
    Complex*    getOutputArray();
    uint16_t    getInputArraySize();
    uint16_t    getOutputArraySize();
    Complex     getOutputElement(uint32_t index);
    void        runTransform();
    void        appendSample(uint16_t c);
    uint16_t    getInputFillLevel();
public slots:
    void        FftArrayUsedByGui(bool value);

signals:
    void        fftCompleted(Complex* outputArray, int outputArraySize);

};



#endif // FFTCALCULATOR_H
