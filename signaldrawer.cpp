#include "signaldrawer.h"

SignalDrawer::SignalDrawer()
{

}



void SignalDrawer::draw(Complex *inputArray, int size, QPainter &painter, int windowHeight, int windowWidth)
{
    /// Calculate the offset of samples in the axis of time
    int sampleOffset = size/windowWidth;
    int sampleIndex = 0;
    double sampleHeightOffset = 0.01*(windowHeight/2) / ZERO_LEVEL_SAMPLE;

    for(int px=0; px<windowWidth; ++px)
    {
        double y = (ZERO_LEVEL_SAMPLE - (inputArray[sampleIndex].getMagnitude() - ZERO_LEVEL_SAMPLE))*sampleHeightOffset;
        painter.drawPoint(px, y);
        sampleIndex += sampleOffset;
        if(sampleIndex >= size)
        {
            break;
        }
    }
}
