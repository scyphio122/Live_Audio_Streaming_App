#ifndef FFTBARS_H
#define FFTBARS_H

#include "abstractvisualization.h"
#include "complex.h"
#include <QPainter>
#include "audio_config.h"

class FFTBars : public AbstractVisualization
{
private:
    const int barSizeX = 50;
    const int barSizeY = 5;
    const int numOfFreqs = sizeof(freqDisplayed)/sizeof(int);
    int       xOffset;

    void drawScale(QPainter& painter, int x, int y, int freq);
    void drawBar(Complex* inputArray, int size, int frequency, int x, int y, QPainter& painter, int windowHeight);
public:
    FFTBars();
    ~FFTBars();

    void calcOffset();
    void draw(Complex* inputArray, int size, QPainter& painter, int windowHeight, int windowWidth);
    void draw(uint16_t *inputArray, int size, QPainter& painter, int windowHeight, int windowWidth);
};

#endif // FFTBARS_H
