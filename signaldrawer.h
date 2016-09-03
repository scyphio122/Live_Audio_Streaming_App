#ifndef SIGNALDRAWER_H
#define SIGNALDRAWER_H

#include <abstractvisualization.h>
#include <stdint-gcc.h>

class SignalDrawer : public AbstractVisualization
{
private:
    const uint16_t ZERO_LEVEL_SAMPLE = UINT16_MAX/2;
public:
    SignalDrawer();

    void draw(Complex *inputArray, int size, QPainter &painter, int windowHeight, int windowWidth);
    void draw(uint16_t *inputArray, int size, QPainter &painter, int windowHeight, int windowWidth);
};

#endif // SIGNALDRAWER_H
