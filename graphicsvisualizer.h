#ifndef GRAPHICSVISUALIZER_H
#define GRAPHICSVISUALIZER_H

#include <stdint-gcc.h>
#include <complex.h>
#include "fftbars.h"
#include "signaldrawer.h"


/**
 * @brief The GraphicsVisualizer class - This class manages the visualization types
 */
class GraphicsVisualizer : public  QObject
{
    Q_OBJECT
private:

public:
    GraphicsVisualizer();
    ~GraphicsVisualizer();

    AbstractVisualization* currentVisualization;

    /**
     * @brief draw - This is the function which is called from mainwindow in order to draw the single visualization frame. It uses FFT output array.
     * @param inputArray[in] - input array
     * @param size[in] - number of elements of input array
     * @param painter[in] - painter which is to be used to draw visualization
     * @param windowHeight[in] - window height
     * @param windowWidth[in] - window width
     */
    void draw(Complex<double>* inputArray, int size, QPainter& painter, int windowHeight, int windowWidth);

    /**
     * @brief draw - This is the function which is called from mainwindow in order to draw the single visualization frame. It uses input data samples array.
     * @param inputArray[in] - input array
     * @param size[in] - number of elements of input array
     * @param painter[in] - painter which is to be used to draw visualization
     * @param windowHeight[in] - window height
     * @param windowWidth[in] - window width
     */
    void draw(int16_t *inputArray, int size, QPainter &painter, int windowHeight, int windowWidth);

    /**
     * @brief switchVisualization - this function is called when the user requests the visualization change
     * @param newVisualization - pointer to the new visualization object
     */
    void switchVisualization(AbstractVisualization* newVisualization);

    /**
     * @brief GetInputType - This function returns whether the current visualization uses FFT array or input samples
     * @return
     */
    AbstractVisualization::InputType GetInputType();

signals:
    void on_VisualizationSwitch(int);   /*< This signal is emitted when the visualization is changed **/
};

#endif // GRAPHICSVISUALIZER_H
