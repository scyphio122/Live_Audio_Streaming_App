#include "complex.h"
#include <cmath>

Complex::Complex()
{

}

Complex::Complex(double realOrMag, double imagOrArg, coordsType typeOfArgs)
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

Complex::Complex(const Complex& number)
{
    this->realPart = number.realPart;
    this->imagPart = number.imagPart;
    this->magnitude = number.magnitude;
    this->argument = number.argument;
}

void Complex::changeRealPart(double value)
{
    this->realPart = value;
    this->magnitude = sqrt(realPart*realPart + imagPart*imagPart);;
    this->argument  = atan2(imagPart, realPart);
}

void Complex::changeImagPart(double value)
{
    this->imagPart = value;
    this->magnitude = sqrt(realPart*realPart + imagPart*imagPart);;
    this->argument  = atan2(imagPart, realPart);
}

void Complex::changeMagnitude(double value)
{
    this->magnitude = value;
    this->realPart = magnitude*cos(argument);
    this->imagPart = magnitude*sin(argument);
}

void Complex::changeArgument(double value)
{
    this->argument = value;
    this->realPart = magnitude*cos(argument);
    this->imagPart = magnitude*sin(argument);
}

double Complex::getRealPart()
{
    return this->realPart;
}

double Complex::getImagPart()
{
    return this->imagPart;
}

double Complex::getMagnitude()
{
    return this->magnitude;
}

double Complex::getArg()
{
    return this->argument;
}
