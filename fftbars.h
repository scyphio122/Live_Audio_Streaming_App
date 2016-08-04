#ifndef FFTBARS_H
#define FFTBARS_H

#include "abstractvisualization.h"
#include "complex.h"
#include <QPainter>


class FFTBars : public AbstractVisualization
{
private:
    const int barSizeX = 200;
    const int barSizeY = 100;
public:
    FFTBars();
    void drawBar(Complex* inputArray, int size, int frequency, int x, int y, QPainter& painter);
    void draw(Complex* inputArray, int size, QPainter& painter, int windowHeight, int windowWidth);
};

#endif // FFTBARS_H
