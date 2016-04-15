#ifndef COMPLEX_H
#define COMPLEX_H

#include <cmath>


class Complex
{
public:
    enum coordsType
    {
        CARTESIAN_COORD,
        POLAR_COORDS
    };
    Complex();
    Complex(double realOrMag, double imagOrArg, coordsType typeOfArgs);
    Complex(const Complex& number);

    void    changeRealPart(double value);
    void    changeImagPart(double value);
    void    changeMagnitude(double value);
    void    changeArgument(double value);
    double  getRealPart();
    double  getImagPart();
    double  getMagnitude();
    double  getArg();

    Complex operator+(const Complex& number)
    {
        Complex _number;
        _number.realPart = this->realPart + number.realPart;
        _number.imagPart = this->imagPart +  number.imagPart;

        _number.magnitude = sqrt(_number.realPart*_number.realPart + _number.imagPart*_number.imagPart);
        _number.argument = atan2(_number.imagPart, _number.realPart);

        return _number;
    }

    Complex& operator+=(const Complex& number)
    {
        this->realPart = this->realPart + number.realPart;
        this->imagPart = this->imagPart +  number.imagPart;

        this->magnitude = sqrt(realPart*realPart + imagPart*imagPart);
        this->argument = atan2(imagPart, realPart);
        return *this;
    }

    Complex operator-(const Complex& number)
    {
        Complex _number;
        _number.realPart = this->realPart - number.realPart;
        _number.imagPart = this->imagPart -  number.imagPart;
        _number.magnitude = sqrt(_number.realPart*_number.realPart + _number.imagPart*_number.imagPart);
        _number.argument = atan2(_number.imagPart, _number.realPart);
        return _number;
    }

    Complex& operator-=(const Complex& number)
    {
        this->realPart = this->realPart - number.realPart;
        this->imagPart = this->imagPart -  number.imagPart;
        this->magnitude = sqrt(realPart*realPart + imagPart*imagPart);
        this->argument = atan2(imagPart, realPart);

        return *this;
    }

    Complex operator*(const Complex& number)
    {
        Complex _number;

        _number.realPart = this->realPart*number.realPart - this->imagPart*number.imagPart;
        _number.imagPart = this->imagPart*number.realPart + this->realPart*number.imagPart;
        _number.magnitude = sqrt(_number.realPart*_number.realPart + _number.imagPart*_number.imagPart);
        _number.argument = atan2(_number.imagPart, _number.realPart);

        return _number;
    }

    Complex& operator*=(const Complex& number)
    {
        this->realPart = this->realPart*number.realPart - this->imagPart*number.imagPart;
        this->imagPart = this->imagPart*number.realPart + this->realPart*number.imagPart;
        this->magnitude = sqrt(realPart*realPart + imagPart*imagPart);
        this->argument = atan2(imagPart, realPart);

        return *this;
    }

    Complex operator/(const Complex& number)
    {
        Complex _number;

        _number.realPart = (this->realPart*number.realPart + this->imagPart*number.imagPart)/(number.realPart*number.realPart + number.imagPart*number.imagPart);
        _number.imagPart = (this->imagPart*number.realPart - this->realPart*number.imagPart)/(number.realPart*number.realPart + number.imagPart*number.imagPart);
        _number.magnitude = sqrt(_number.realPart*_number.realPart + _number.imagPart*_number.imagPart);
        _number.argument = atan2(_number.imagPart, _number.realPart);
        return _number;
    }

    Complex& operator/=(const Complex& number)
    {
        this->realPart = (this->realPart*number.realPart + this->imagPart*number.imagPart)/(number.realPart*number.realPart + number.imagPart*number.imagPart);
        this->imagPart = (this->imagPart*number.realPart - this->realPart*number.imagPart)/(number.realPart*number.realPart + number.imagPart*number.imagPart);
        this->magnitude = sqrt(realPart*realPart + imagPart*imagPart);
        this->argument = atan2(imagPart, realPart);
        return *this;
    }


    bool operator==(const Complex& number)
    {
        return ((this->realPart == number.realPart) && (this->imagPart == number.imagPart));
    }



private:
    double realPart;    /*< The real part of the complex number */
    double imagPart;    /*< The imaginary part of the complex number */
    double magnitude;
    double argument;

};

#endif // COMPLEX_H
