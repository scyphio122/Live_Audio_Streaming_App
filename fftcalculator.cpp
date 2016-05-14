#include "fftcalculator.h"
#include <stdint-gcc.h>
#include "complex.h"
#include <cmath>
#include <iostream>

FftCalculator::FftCalculator() : QObject(nullptr)
{

}

FftCalculator::~FftCalculator()
{
    delete[] inputArray;
}

void FftCalculator::setInputArray(int16_t *array)
{
    inputArray = array;
}

void FftCalculator::setOutputArray(Complex *array)
{
    outputArray = array;
}

void FftCalculator::setInputArraySize(uint16_t size)
{
    inputArraySize = size;
}
void FftCalculator::setOutputArraySize(uint16_t size)
{
    outputArraySize = size;
}

int16_t* FftCalculator::getInputArray()
{
    return inputArray;
}
Complex* FftCalculator::getOutputArray()
{
    return outputArray;
}

uint16_t FftCalculator::getInputArraySize()
{
    return inputArraySize;
}

uint16_t FftCalculator::getOutputArraySize()
{
    return outputArraySize;
}

Complex FftCalculator::getOutputElement(uint32_t index)
{
    return outputArray[index];
}

void FftCalculator::appendSample(uint16_t c)
{
    this->inputArray[inputArrayIndex++] = c;
    if(inputArrayIndex == inputArraySize)
    {
        inputArrayIndex = 0;
    }
}

uint16_t FftCalculator::getInputFillLevel()
{
    return this->inputArrayIndex;
}

void FftCalculator::fftEnable(bool value)
{
    this->fftEnabled = value;
}

bool FftCalculator::getFftEnable()
{
    return fftEnabled;
}

void FftCalculator::runTransform()
{
    if(!fftEnabled)
        return;
    /// Release the previous resources
    if(outputArray != nullptr)
    {
       delete[] outputArray;
       outputArray = nullptr;
    }

    /// Calculate the new FFT
    outputArray = recursiveFFT(inputArray, inputArraySize);
    emit fftCompleted(outputArray, outputArraySize);

    /// Clear the fftEnabled flag in order not to calculate FFT if not necessary
    fftEnabled = false;
}

Complex* FftCalculator::recursiveFFT(int16_t subarray[], uint16_t subarraySize, unsigned long int step)
{
    Complex* resultArray = nullptr;
    if(subarraySize == 1)
        return new Complex(subarray[0], 0, Complex::CARTESIAN_COORD);
    else
    {
        Complex* evenArray = nullptr;
        Complex* oddArray = nullptr;

        evenArray   = recursiveFFT(subarray, subarraySize/2, step*2);
        oddArray    = recursiveFFT(subarray + step, subarraySize/2, step*2);

        double complexConstArgPart = -2*M_PI/subarraySize;

        resultArray = new Complex[subarraySize];
        int halfSubArraySize = subarraySize/2;
        for(uint16_t k=0; k<halfSubArraySize; k++)
        {
           resultArray[k] = evenArray[k] + Complex(1.0, -complexConstArgPart*k, Complex::POLAR_COORDS)*oddArray[k];
           resultArray[k + subarraySize/2]  = evenArray[k] - Complex(1.0, -complexConstArgPart*k, Complex::POLAR_COORDS)*oddArray[k];
        }

        delete[] evenArray;
        delete[] oddArray;
    }


    return resultArray;
}

