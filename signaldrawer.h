#ifndef SIGNALDRAWER_H
#define SIGNALDRAWER_H

#include <abstractvisualization.h>
#include <stdint-gcc.h>

/**
 * @brief The SignalDrawer class - this class is used to draw visualization of raw samples
 */
class SignalDrawer : public AbstractVisualization
{
private:
    const uint16_t ZERO_LEVEL_SAMPLE = UINT16_MAX/2;
public:
    SignalDrawer();

    /**
     * @brief draw - OVERLOADED FUNCTION. This is the interface function which is called in order to draw the single visualization frame. It uses fft output array.
     * @param inputArray[in] - input array
     * @param size[in] - number of elements of input array
     * @param painter[in] - painter which is to be used to draw visualization
     * @param windowHeight[in] - window height
     * @param windowWidth[in] - window width
     */
    void draw(Complex<double> *inputArray, int size, QPainter &painter, int windowHeight, int windowWidth);

    /**
     * @brief draw - OVERLOADED FUNCTION. This is the interface function which is called in order to draw the single visualization frame. It uses input data samples array.
     * @param inputArray[in] - input array
     * @param size[in] - number of elements of input array
     * @param painter[in] - painter which is to be used to draw visualization
     * @param windowHeight[in] - window height
     * @param windowWidth[in] - window width
     */
    void draw(uint16_t *inputArray, int size, QPainter &painter, int windowHeight, int windowWidth);
};

#endif // SIGNALDRAWER_H
