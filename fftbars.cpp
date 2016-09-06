#include "fftbars.h"
#include <QPainter>
#include <Qt>
#include <graphicsvisualizer.h>
#include "audio_config.h"


FFTBars::FFTBars()
{
    inputType = INPUT_FFT;
}

FFTBars::~FFTBars()
{

}

void FFTBars::calcOffset()
{
    this->xOffset = (windowWidth - barSizeX*numOfFreqs)/numOfFreqs;
}

void FFTBars::drawBar(Complex<double>* inputArray, int size, int frequency, int x, int y, QPainter& painter, int windowHeight)
{
    int freqIndex = getFreqIndex(inputArray, size, frequency)/2;
    int numOfRects = inputArray[freqIndex].getMagnitude()/(barSizeY*25000);

    for(int i=0; i<numOfRects; ++i)
    {
        int _y = y+i*(5+barSizeY);
        if(_y <= windowHeight - 50)
            painter.drawRect(x, _y, this->barSizeX, this->barSizeY);
        else if(_y <= windowHeight - 40)
            painter.fillRect(x, _y, this->barSizeX, this->barSizeY, QColor(255,127, 39));
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
        painter.drawText(x + barSizeX/2 - 10, y, frequency);
}

void FFTBars::draw(Complex<double>* inputArray, int size, QPainter& painter, int windowHeight, int windowWidth)
{
    for(int i=0; i<numOfFreqs; ++i)
    {
        int x = i*(xOffset + barSizeX);
        drawBar(inputArray, size, freqDisplayed[i], x, 0, painter, windowHeight);
        drawScale(painter, x, windowHeight - 10, freqDisplayed[i]);
    }
}
void FFTBars::draw(uint16_t* inputArray, int size, QPainter& painter, int windowHeight, int windowWidth)
{

}
