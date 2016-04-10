#ifndef ABSTRACTVISUALIZATION_H
#define ABSTRACTVISUALIZATION_H

#include <QRgb>

class AbstractVisualization
{
public:
    QRgb color;

    AbstractVisualization();

    void setColor(QRgb color);


    virtual void drawFrame() = 0;
};

#endif // ABSTRACTVISUALIZATION_H
