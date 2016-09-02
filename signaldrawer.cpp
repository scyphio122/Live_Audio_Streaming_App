#include "signaldrawer.h"

SignalDrawer::SignalDrawer()
{
    inputType = INPUT_SAMPLES;
}



void SignalDrawer::draw(int16_t *inputArray, int size, QPainter &painter, int windowHeight, int windowWidth)
{
    /// Calculate the offset of samples in the axis of time
    int sampleOffset = size/windowWidth;
    int sampleIndex = 0;
    double sampleHeightOffset = (windowHeight/2) / ZERO_LEVEL_SAMPLE;
    size /= 2;
    if(inputArray != nullptr)
    {
        for(int px=0; px<windowWidth; ++px)
        {
            if(sampleIndex >= size)
            {
                break;
            }
            double y = (ZERO_LEVEL_SAMPLE - (inputArray[sampleIndex]- ZERO_LEVEL_SAMPLE))*sampleHeightOffset;
            painter.drawPoint(px, y);
            sampleIndex += sampleOffset;

        }
    }
}

void SignalDrawer::draw(Complex *inputArray, int size, QPainter &painter, int windowHeight, int windowWidth)
{

}
