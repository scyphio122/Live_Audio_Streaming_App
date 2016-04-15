#ifndef FFTCALCULATOR_H
#define FFTCALCULATOR_H

#include <stdint-gcc.h>
#include <QVector>
#include <complex.h>

#define M_PI    3.14159265358979323846d

class FftCalculator
{
public:

    FftCalculator();

    void        setInputArray(double array[]);
    void        setOutputArray(Complex* array);
    void        setInputArraySize(uint16_t size);
    void        setOutputArraySize(uint16_t size);
    double*     getInputArray();
    Complex*    getOutputArray();
    uint16_t    getInputArraySize();
    uint16_t    getOutputArraySize();
    Complex     getOutputElement(uint32_t index);
    void        runTransform();
private:

    double*     inputArray = nullptr;
    Complex*    outputArray = nullptr;
    uint16_t    inputArraySize;
    uint16_t    outputArraySize;

    Complex*    recursiveFFT(double subarray[], uint16_t subarraySize, unsigned long step = 1);
};



#endif // FFTCALCULATOR_H
