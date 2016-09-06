#ifndef ABSTRACTVISUALIZATION_H
#define ABSTRACTVISUALIZATION_H

#include <QRgb>
#include "complex.h"
#include <QPainter>
#include <QMutex>

/**
 * @brief The AbstractVisualization class - This class is an interface for visualization
 */
class AbstractVisualization
{
protected:
    QMutex mutex;
public:
    QRgb color;
    int       windowHeight;
    int       windowWidth;

    enum InputType
    {
        INPUT_SAMPLES,
        INPUT_FFT
    };

    InputType inputType = INPUT_FFT;

    AbstractVisualization();

    /**
     * @brief ~AbstractVisualization virtual destructor (needed in order to destroy child objects)
     */
    virtual ~AbstractVisualization();

    /**
     * @brief setColor - This method changes the color of the visualization
     * @param color[in] - color to be set
     */

    void setColor(QRgb color);

    /**
     * @brief setWindowHeight - This method sets the height of the window for visualization class
     * @param h[in] - the real height of the window
     */
    void setWindowHeight(int h);

    /**
     * @brief setWindowWidth - This method sets the width of the windof, for visualization class
     * @param w[in] - the real width of the window
     */
    void setWindowWidth(int w);

    uint32_t getFreqIndex(Complex<double>* inputArray, int inputArraySize, int frequency);

    /**
     * @brief draw - This is the interface function which is called in order to draw the single visualization frame. It uses FFT out array.
     * @param inputArray[in] - input array
     * @param size[in] - number of elements of input array
     * @param painter[in] - painter which is to be used to draw visualization
     * @param windowHeight[in] - window height
     * @param windowWidth[in] - window width
     */
    virtual void draw(Complex<double>* inputArray, int size, QPainter& painter, int windowHeight, int windowWidth) = 0;

    /**
     * @brief draw - This is the interface function which is called in order to draw the single visualization frame. It uses input data samples array.
     * @param inputArray[in] - input array
     * @param size[in] - number of elements of input array
     * @param painter[in] - painter which is to be used to draw visualization
     * @param windowHeight[in] - window height
     * @param windowWidth[in] - window width
     */
    virtual void draw(uint16_t* inputArray, int size, QPainter& painter, int windowHeight, int windowWidth) = 0;
};

#endif // ABSTRACTVISUALIZATION_H
