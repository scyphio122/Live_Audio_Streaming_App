#include "fftbars.h"
#include <QPainter>
#include <Qt>
#include <graphicsvisualizer.h>
#include "audio_config.h"


FFTBars::FFTBars()
{

}


void FFTBars::drawBar(Complex* inputArray, int size, int frequency, int x, int y, QPainter& painter, int windowHeight)
{
    int freqIndex = getFreqIndex(inputArray, size, frequency);
    int numOfRects = inputArray[freqIndex].getMagnitude()/(barSizeY*300);

    for(int i=0; i<numOfRects; ++i)
    {
        int _y = y+i*(5+barSizeY);
        if(_y <= windowHeight - 50)
            painter.drawRect(x, _y, this->barSizeX, this->barSizeY);
        else if(_y <= windowHeight - 40)
            painter.fillRect(x, _y, this->barSizeX, this->barSizeY, Qt::GlobalColor::red);
        else
            break;
    }

}

void FFTBars::drawScale(QPainter& painter, int x, int y)
{
    for(int i=0; i<numOfFreqs; ++i)
    {
        QString frequency;
        if(freqDisplayed[i] < 1000)
        {
            frequency = QString::number(freqDisplayed[i]);
            frequency += "Hz";
        }
        else
        {
            frequency = QString::number(freqDisplayed[i]/1000);
            frequency += "kHz";
        }
        painter.drawText(x + barSizeX/2, y, frequency);
        x += barSizeX + 5;
    }
}

void FFTBars::draw(Complex* inputArray, int size, QPainter& painter, int windowHeight, int windowWidth)
{
    for(int i=0; i<numOfFreqs; ++i)
    {
        int x = i*(10 + barSizeX);
        drawBar(inputArray, size, freqDisplayed[i], x, 0, painter, windowHeight);

    }
     drawScale(painter, 0, windowHeight - 10);
}

