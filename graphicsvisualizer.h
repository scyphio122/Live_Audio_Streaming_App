#ifndef GRAPHICSVISUALIZER_H
#define GRAPHICSVISUALIZER_H

#include <stdint-gcc.h>
#include <complex.h>
#include "fftbars.h"
#include "signaldrawer.h"

class GraphicsVisualizer : public  QObject
{
    Q_OBJECT
private:

public:
    GraphicsVisualizer();
    ~GraphicsVisualizer();

    AbstractVisualization* currentVisualization;

    void draw(Complex* inputArray, int size, QPainter& painter, int windowHeight, int windowWidth);
    void draw(int16_t *inputArray, int size, QPainter &painter, int windowHeight, int windowWidth);
    void switchVisualization(AbstractVisualization* newVisualization);
    AbstractVisualization::InputType GetInputType();

signals:
    void on_VisualizationSwitch(int);
};

#endif // GRAPHICSVISUALIZER_H
