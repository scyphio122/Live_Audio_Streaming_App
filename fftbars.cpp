#include "fftbars.h"
#include <QPainter>
#include <graphicsvisualizer.h>
#include "audio_config.h"


FFTBars::FFTBars()
{

}


void FFTBars::drawBar(Complex* inputArray, int size, int frequency, int x, int y, QPainter& painter)
{
    int freqIndex = getFreqIndex(inputArray, size, frequency);
    int numOfRects = inputArray[freqIndex].getMagnitude()/barSizeY;

    for(int i=0; i<numOfRects; ++i)
    {
        painter.drawRect(x, y+i*(5+y), this->barSizeX, this->barSizeY);
    }

}

void FFTBars::draw(Complex* inputArray, int size, QPainter& painter, int windowHeight, int windowWidth)
{
    int numOfFreqs = sizeof(freqDisplayed)/sizeof(int);
    for(int i=0; i<numOfFreqs; ++i)
    {
        drawBar(inputArray, size, freqDisplayed[i], i*(10 + barSizeX), 0, painter);
    }
}
