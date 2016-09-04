#include "abstractvisualization.h"
#include "audio_config.h"


AbstractVisualization::AbstractVisualization()
{
    inputType = INPUT_FFT;
}
AbstractVisualization::~AbstractVisualization()
{

}

uint32_t AbstractVisualization::getFreqIndex(Complex* inputArray, int inputArraySize, int frequency)
{
    return (double)(frequency*inputArraySize)/samplingFrequency;
}

void AbstractVisualization::setWindowHeight(int h)
{
    this->windowHeight = h;
}

void AbstractVisualization::setWindowWidth(int w)
{
    this->windowWidth = w;
}
