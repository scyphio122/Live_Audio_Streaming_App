#ifndef GRAPHICSVISUALIZER_H
#define GRAPHICSVISUALIZER_H

#include <stdint-gcc.h>
#include <complex.h>
#include "fftbars.h"


class GraphicsVisualizer
{
private:
    FFTBars fftBars;
public:
    GraphicsVisualizer();


    void draw(Complex* inputArray, int size, QPainter& painter, int windowHeight, int windowWidth);
};

#endif // GRAPHICSVISUALIZER_H
