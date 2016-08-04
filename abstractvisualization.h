#ifndef ABSTRACTVISUALIZATION_H
#define ABSTRACTVISUALIZATION_H

#include <QRgb>
#include "complex.h"
#include <QPainter>

class AbstractVisualization
{
public:
    QRgb color;
    int       windowHeight;
    int       windowWidth;

    AbstractVisualization();

    void setColor(QRgb color);

    void setWindowHeight(int h);

    void setWindowWidth(int w);

    uint32_t getFreqIndex(Complex* inputArray, int inputArraySize, int frequency);

    virtual void draw(Complex* inputArray, int size, QPainter& painter, int windowHeight, int windowWidth) = 0;
};

#endif // ABSTRACTVISUALIZATION_H
