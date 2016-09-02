#ifndef SIGNALDRAWER_H
#define SIGNALDRAWER_H

#include <abstractvisualization.h>

class SignalDrawer : public AbstractVisualization
{
private:
    const double ZERO_LEVEL_SAMPLE = INT16_MAX/2;
public:
    SignalDrawer();

    void draw(Complex *inputArray, int size, QPainter &painter, int windowHeight, int windowWidth);
};

#endif // SIGNALDRAWER_H
