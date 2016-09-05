#ifndef FFTBARS_H
#define FFTBARS_H

#include "abstractvisualization.h"
#include "complex.h"
#include <QPainter>
#include "audio_config.h"

/**
 * @brief The FFTBars class - This class is an implementation of FFT bars visualization
 */
class FFTBars : public AbstractVisualization
{
private:
    const int barSizeX = 50;
    const int barSizeY = 5;
    const int numOfFreqs = sizeof(freqDisplayed)/sizeof(int);
    int       xOffset;

    /**
     * @brief drawScale - This function draws a frequency scale on the bottom of the window
     * @param painter[in] - painter which is used to draw the scale
     * @param x - x offset (in px) for text
     * @param y - y offset (in px) for text
     * @param freq - frequency which is to be drawned on scale
     */
    void drawScale(QPainter& painter, int x, int y, int freq);


    /**
     * @brief drawBar - this function is called to draw a single bar (for single frequency)
     * @param inputArray[in] - pointer to the fft out array
     * @param size[in] - size of the FFT out array
     * @param frequency[in] - frequency for which the bar is drawn
     * @param x[in] - x offset (in px) for bar
     * @param y[in] - y offset (in px) for bar
     * @param painter[in] - painter which is used to draw the scale
     * @param windowHeight[in]
     */
    void drawBar(Complex* inputArray, int size, int frequency, int x, int y, QPainter& painter, int windowHeight);
public:
    FFTBars();
    ~FFTBars();

    /**
     * @brief calcOffset - This function is called to calculate offset between two adjacent bars
     */
    void calcOffset();

    /**
     * @brief draw - OVERLOADED FUNCTION. This is the interface function which is called in order to draw the single visualization frame. It uses fft output array.
     * @param inputArray[in] - input array
     * @param size[in] - number of elements of input array
     * @param painter[in] - painter which is to be used to draw visualization
     * @param windowHeight[in] - window height
     * @param windowWidth[in] - window width
     */
    void draw(Complex* inputArray, int size, QPainter& painter, int windowHeight, int windowWidth);


    /**
     * @brief draw - OVERLOADED FUNCTION. This is the interface function which is called in order to draw the single visualization frame. It uses input data samples array.
     * @param inputArray[in] - input array
     * @param size[in] - number of elements of input array
     * @param painter[in] - painter which is to be used to draw visualization
     * @param windowHeight[in] - window height
     * @param windowWidth[in] - window width
     */
    void draw(uint16_t *inputArray, int size, QPainter& painter, int windowHeight, int windowWidth);
};

#endif // FFTBARS_H
