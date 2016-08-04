#include "fftbars.h"
#include <QPainter>
#include <Qt>
#include <graphicsvisualizer.h>
#include "audio_config.h"


FFTBars::FFTBars()
{

}

void FFTBars::calcOffset()
{
    this->xOffset = (windowWidth - barSizeX*numOfFreqs)/numOfFreqs;
}

void FFTBars::drawBar(Complex* inputArray, int size, int frequency, int x, int y, QPainter& painter, int windowHeight)
{
    int freqIndex = getFreqIndex(inputArray, size, frequency);
    int numOfRects = inputArray[freqIndex].getMagnitude()/(barSizeY*1000);

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

void FFTBars::drawScale(QPainter& painter, int x, int y, int freq)
{
        QString frequency;
        if(freq < 1000)
        {
            frequency = QString::number(freq);
            frequency += "Hz";
        }
        else
        {
            frequency = QString::number(freq/1000);
            frequency += "kHz";
        }
        painter.drawText(x + barSizeX/2 - 5, y, frequency);
}

void FFTBars::draw(Complex* inputArray, int size, QPainter& painter, int windowHeight, int windowWidth)
{
    for(int i=0; i<numOfFreqs; ++i)
    {
        int x = i*(xOffset + barSizeX);
        drawBar(inputArray, size, freqDisplayed[i], x, 0, painter, windowHeight);
        drawScale(painter, x, windowHeight - 10, freqDisplayed[i]);
    }
}

