#include "complex.h"
#include <cmath>


template <typename T>
Complex<T>::Complex()
{

}

template <typename T>
Complex<T>::Complex(T realOrMag, T imagOrArg, coordsType typeOfArgs)
{
    if(typeOfArgs == CARTESIAN_COORD)
    {
        this->realPart  = realOrMag;
        this->imagPart  = imagOrArg;
        this->magnitude = sqrt(realPart*realPart + imagPart*imagPart);;
        this->argument  = atan2(imagPart, realPart);
    }
    else
    if(typeOfArgs == POLAR_COORDS)
    {
        this->magnitude = realOrMag;
        this->argument = imagOrArg;
        this->realPart = magnitude*cos(argument);
        this->imagPart = magnitude*sin(argument);
    }
}

template <typename T>
Complex<T>::Complex(const Complex<T>& number)
{
    this->realPart = number.realPart;
    this->imagPart = number.imagPart;
    this->magnitude = number.magnitude;
    this->argument = number.argument;
}

template <typename T>
void Complex<T>::changeRealPart(T value)
{
    this->realPart = value;
    this->magnitude = sqrt(realPart*realPart + imagPart*imagPart);;
    this->argument  = atan2(imagPart, realPart);
}

template <typename T>
void Complex<T>::changeImagPart(T value)
{
    this->imagPart = value;
    this->magnitude = sqrt(realPart*realPart + imagPart*imagPart);;
    this->argument  = atan2(imagPart, realPart);
}

template <typename T>
void Complex<T>::changeMagnitude(T value)
{
    this->magnitude = value;
    this->realPart = magnitude*cos(argument);
    this->imagPart = magnitude*sin(argument);
}

template <typename T>
void Complex<T>::changeArgument(T value)
{
    this->argument = value;
    this->realPart = magnitude*cos(argument);
    this->imagPart = magnitude*sin(argument);
}

template <typename T>
T Complex<T>::getRealPart()
{
    return this->realPart;
}

template <typename T>
T Complex<T>::getImagPart()
{
    return this->imagPart;
}

template <typename T>
T Complex<T>::getMagnitude()
{
    return this->magnitude;
}

template <typename T>
T Complex<T>::getArg()
{
    return this->argument;
}

template class Complex<double>;
