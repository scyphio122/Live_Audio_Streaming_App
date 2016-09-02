#ifndef GRAPHICSVISUALIZER_H
#define GRAPHICSVISUALIZER_H

#include <stdint-gcc.h>
#include <complex.h>
#include "fftbars.h"
#include "signaldrawer.h"

class GraphicsVisualizer
{
private:


public:
    GraphicsVisualizer();
    ~GraphicsVisualizer();

    AbstractVisualization* currentVisualization;
    FFTBars         fftBars;
    SignalDrawer    signalDrawer;
    void draw(Complex* inputArray, int size, QPainter& painter, int windowHeight, int windowWidth);
    void switchVisualization(AbstractVisualization* newVisualization);
};

#endif // GRAPHICSVISUALIZER_H
