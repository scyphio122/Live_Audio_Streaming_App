#include "graphicsvisualizer.h"
#include <stdint-gcc.h>
#include <complex.h>
#include "audio_config.h"

GraphicsVisualizer::GraphicsVisualizer()
{
    currentVisualization = new fftBars();
}

GraphicsVisualizer::~GraphicsVisualizer()
{
    if(currentVisualization != nullptr)
    {
        delete currentVisualization;
        currentVisualization = nullptr;
    }
}


void GraphicsVisualizer::draw(Complex *inputArray, int size, QPainter &painter, int windowHeight, int windowWidth)
{
    currentVisualization->draw(inputArray, size, painter, windowHeight, windowWidth);
//    signalDrawer.draw(inputArray, size, painter, windowHeight, windowWidth);
}


void GraphicsVisualizer::switchVisualization(AbstractVisualization* newVisualization)
{
    if(currentVisualization != nullptr)
    {
        delete currentVisualization;
        currentVisualization = nullptr;
    }

    currentVisualization = newVisualization;
}
