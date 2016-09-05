#ifndef COMPLEX_H
#define COMPLEX_H

#include <cmath>

/**
 * @brief The Complex class - This is implementation of a complex number
 */
class Complex
{
public:
    enum coordsType
    {
        CARTESIAN_COORD,
        POLAR_COORDS
    };
    Complex();

    /**
     * @brief Complex - constructor of complex number
     * @param realOrMag[in] -  real part(cartesian) or magnitude(polar)
     * @param imagOrArg[in] - imaginary part(cartesian)  or argument(polar)
     * @param typeOfArgs[in] - tupe of arguments - as cartesian coordinates or poalr coordinates
     */
    Complex(double realOrMag, double imagOrArg, coordsType typeOfArgs);

    /**
     * @brief Complex - copying constructor for complex number
     * @param number
     */
    Complex(const Complex& number);

    /**
     * @brief changeRealPart - setter for real part
     * @param value
     */
    void    changeRealPart(double value);
    /**
     * @brief changeImagPart - setter for imagninary part
     * @param value
     */
    void    changeImagPart(double value);

    /**
     * @brief changeMagnitude - setter for magnitude
     * @param value
     */
    void    changeMagnitude(double value);

    /**
     * @brief changeArgument - setter for argument
     * @param value
     */
    void    changeArgument(double value);

    /**
     * @brief getRealPart - getter for real part
     * @return
     */
    double  getRealPart();

    /**
     * @brief getImagPart - getter for imaginary part
     * @return
     */
    double  getImagPart();

    /**
     * @brief getMagnitude - getter for magnitude
     * @return
     */
    double  getMagnitude();

    /**
     * @brief getArg - getter for argument
     * @return
     */
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
