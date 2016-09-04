#include "graphicsvisualizer.h"
#include <stdint-gcc.h>
#include <complex.h>
#include "audio_config.h"

GraphicsVisualizer::GraphicsVisualizer()
{
    currentVisualization = new FFTBars();
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
    if(inputArray != nullptr)
    {
        currentVisualization->draw(inputArray, size, painter, windowHeight, windowWidth);
    }
}

void GraphicsVisualizer::draw(int16_t *inputArray, int size, QPainter &painter, int windowHeight, int windowWidth)
{
    if(inputArray != nullptr)
    {
        currentVisualization->draw((uint16_t*)inputArray, size, painter, windowHeight, windowWidth);
    }
}


void GraphicsVisualizer::switchVisualization(AbstractVisualization* newVisualization)
{
    if(currentVisualization != nullptr)
    {
        delete currentVisualization;
        currentVisualization = nullptr;
    }

    currentVisualization = newVisualization;

    emit on_VisualizationSwitch((int)newVisualization->inputType);
}

AbstractVisualization::InputType GraphicsVisualizer::GetInputType()
{
    return currentVisualization->inputType;
}
