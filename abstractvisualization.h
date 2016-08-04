#ifndef ABSTRACTVISUALIZATION_H
#define ABSTRACTVISUALIZATION_H

#include <QRgb>
#include "complex.h"
#include <QPainter>

class AbstractVisualization
{
public:
    QRgb color;

    AbstractVisualization();

    void setColor(QRgb color);

    virtual void draw(Complex* inputArray, int size, QPainter& painter, int windowHeight, int windowWidth) = 0;

    uint32_t getFreqIndex(Complex* inputArray, int inputArraySize, int frequency);
};

#endif // ABSTRACTVISUALIZATION_H
