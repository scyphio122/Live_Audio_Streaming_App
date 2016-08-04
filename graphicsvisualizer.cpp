#include "graphicsvisualizer.h"
#include <stdint-gcc.h>
#include <complex.h>
#include "audio_config.h"

GraphicsVisualizer::GraphicsVisualizer()
{

}


void GraphicsVisualizer::draw(Complex *inputArray, int size, QPainter &painter, int windowHeight, int windowWidth)
{
    fftBars.draw(inputArray, size, painter, windowHeight, windowWidth);
}
