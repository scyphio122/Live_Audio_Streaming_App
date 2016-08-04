#include "abstractvisualization.h"
#include "audio_config.h"


AbstractVisualization::AbstractVisualization()
{

}

uint32_t AbstractVisualization::getFreqIndex(Complex* inputArray, int inputArraySize, int frequency)
{
    return (double)(frequency*inputArraySize)/samplingFrequency;
}
