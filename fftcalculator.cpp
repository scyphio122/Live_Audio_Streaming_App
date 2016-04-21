#include "fftcalculator.h"
#include <stdint-gcc.h>
#include "complex.h"
#include <cmath>


FftCalculator::FftCalculator() : QObject(nullptr)
{
    outputArray = nullptr;
}

void FftCalculator::setInputArray(double array[])
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

double* FftCalculator::getInputArray()
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
    this->inputArray[inputArrayIndex++];
    if(inputArrayIndex == inputArraySize)
    {
        inputArrayIndex = 0;

        emit updateGui();
    }
}

uint16_t FftCalculator::getInputFillLevel()
{
    return this->inputArrayIndex;
}

void FftCalculator::runTransform()
{
    outputArray = recursiveFFT(inputArray, inputArraySize);
}

Complex* FftCalculator::recursiveFFT(double subarray[], uint16_t subarraySize, unsigned long int step)
{
    Complex* resultArray = nullptr;
    if(subarraySize == 1)
        return new Complex(subarray[0], 0, Complex::CARTESIAN_COORD);
    else
    {
        Complex* evenArray = new Complex[subarraySize/2];
        Complex* oddArray = new Complex[subarraySize/2];



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

