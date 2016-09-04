#include "signaldrawer.h"

SignalDrawer::SignalDrawer()
{
    inputType = INPUT_SAMPLES;
}


#include <QDebug>
void SignalDrawer::draw(uint16_t *inputArray, int size, QPainter &painter, int windowHeight, int windowWidth)
{
    mutex.lock();
    /// Number of samples (each sample has 2 bytes)
    size /= 2;
    qDebug() << "SignalDrawer size: " << size;
    QPoint prevPoint(0, windowHeight/2);
    /// Calculate the offset of samples in the axis of time
    int sampleOffset = size/windowWidth;
    int sampleIndex = 0;
    double sampleHeightOffset = (double)(windowHeight/2) / ZERO_LEVEL_SAMPLE;
    int windowHalfHeight = windowHeight/2;

    if(inputArray != nullptr)
    {
        for(int px=0; px<windowWidth; ++px)
        {
            if(sampleIndex >= size)
            {
                break;
            }

            int result = ((inputArray[sampleIndex] - ZERO_LEVEL_SAMPLE)) / (ZERO_LEVEL_SAMPLE/windowHalfHeight + 1);
            double y = windowHalfHeight - result;

            painter.drawLine(prevPoint, QPoint(px, y));

            prevPoint.setX(px);
            prevPoint.setY(y);

            if(y >= windowHeight)
            {
                qDebug() << "Blad obliczen";
            }

            sampleIndex += sampleOffset;

        }
    }
    mutex.unlock();
    return;
}

void SignalDrawer::draw(Complex *inputArray, int size, QPainter &painter, int windowHeight, int windowWidth)
{

}
