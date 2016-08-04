#ifndef GRAPHICSVISUALIZER_H
#define GRAPHICSVISUALIZER_H

#include <stdint-gcc.h>
#include <complex.h>

class GraphicsVisualizer
{
public:
    GraphicsVisualizer();
    static uint32_t getFreqIndex(Complex* inputArray, int inputArraySize, int frequency);
};

#endif // GRAPHICSVISUALIZER_H
