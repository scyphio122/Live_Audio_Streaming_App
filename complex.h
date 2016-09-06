#ifndef COMPLEX_H
#define COMPLEX_H

#include <cmath>


/**
 * @brief The Complex class - This is implementation of a complex number
 */
template <typename T>
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
    Complex(T realOrMag, T imagOrArg, coordsType typeOfArgs);

    /**
     * @brief Complex - copying constructor for complex number
     * @param number
     */
    Complex(const Complex<T> &number);

    /**
     * @brief changeRealPart - setter for real part
     * @param value
     */
    void    changeRealPart(T value);
    /**
     * @brief changeImagPart - setter for imagninary part
     * @param value
     */
    void    changeImagPart(T value);

    /**
     * @brief changeMagnitude - setter for magnitude
     * @param value
     */
    void    changeMagnitude(T value);

    /**
     * @brief changeArgument - setter for argument
     * @param value
     */
    void    changeArgument(T value);

    /**
     * @brief getRealPart - getter for real part
     * @return
     */
    T  getRealPart();

    /**
     * @brief getImagPart - getter for imaginary part
     * @return
     */
    T  getImagPart();

    /**
     * @brief getMagnitude - getter for magnitude
     * @return
     */
    T getMagnitude();

    /**
     * @brief getArg - getter for argument
     * @return
     */
    T  getArg();

    Complex<T> operator+(const Complex<T>& number)
    {
        Complex<T> _number;
        _number.realPart = this->realPart + number.realPart;
        _number.imagPart = this->imagPart +  number.imagPart;

        _number.magnitude = sqrt(_number.realPart*_number.realPart + _number.imagPart*_number.imagPart);
        _number.argument = atan2(_number.imagPart, _number.realPart);

        return _number;
    }

    Complex<T>& operator+=(const Complex<T>& number)
    {
        this->realPart = this->realPart + number.realPart;
        this->imagPart = this->imagPart +  number.imagPart;

        this->magnitude = sqrt(realPart*realPart + imagPart*imagPart);
        this->argument = atan2(imagPart, realPart);
        return *this;
    }

    Complex<T> operator-(const Complex<T>& number)
    {
        Complex<T> _number;
        _number.realPart = this->realPart - number.realPart;
        _number.imagPart = this->imagPart -  number.imagPart;
        _number.magnitude = sqrt(_number.realPart*_number.realPart + _number.imagPart*_number.imagPart);
        _number.argument = atan2(_number.imagPart, _number.realPart);
        return _number;
    }

    Complex<T>& operator-=(const Complex<T>& number)
    {
        this->realPart = this->realPart - number.realPart;
        this->imagPart = this->imagPart -  number.imagPart;
        this->magnitude = sqrt(realPart*realPart + imagPart*imagPart);
        this->argument = atan2(imagPart, realPart);

        return *this;
    }

    Complex<T> operator*(const Complex<T>& number)
    {
        Complex<T> _number;

        _number.realPart = this->realPart*number.realPart - this->imagPart*number.imagPart;
        _number.imagPart = this->imagPart*number.realPart + this->realPart*number.imagPart;
        _number.magnitude = sqrt(_number.realPart*_number.realPart + _number.imagPart*_number.imagPart);
        _number.argument = atan2(_number.imagPart, _number.realPart);

        return _number;
    }

    Complex<T>& operator*=(const Complex<T>& number)
    {
        this->realPart = this->realPart*number.realPart - this->imagPart*number.imagPart;
        this->imagPart = this->imagPart*number.realPart + this->realPart*number.imagPart;
        this->magnitude = sqrt(realPart*realPart + imagPart*imagPart);
        this->argument = atan2(imagPart, realPart);

        return *this;
    }

    Complex<T> operator/(const Complex<T>& number)
    {
        Complex<T> _number;

        _number.realPart = (this->realPart*number.realPart + this->imagPart*number.imagPart)/(number.realPart*number.realPart + number.imagPart*number.imagPart);
        _number.imagPart = (this->imagPart*number.realPart - this->realPart*number.imagPart)/(number.realPart*number.realPart + number.imagPart*number.imagPart);
        _number.magnitude = sqrt(_number.realPart*_number.realPart + _number.imagPart*_number.imagPart);
        _number.argument = atan2(_number.imagPart, _number.realPart);
        return _number;
    }

    Complex<T>& operator/=(const Complex<T>& number)
    {
        this->realPart = (this->realPart*number.realPart + this->imagPart*number.imagPart)/(number.realPart*number.realPart + number.imagPart*number.imagPart);
        this->imagPart = (this->imagPart*number.realPart - this->realPart*number.imagPart)/(number.realPart*number.realPart + number.imagPart*number.imagPart);
        this->magnitude = sqrt(realPart*realPart + imagPart*imagPart);
        this->argument = atan2(imagPart, realPart);
        return *this;
    }


    bool operator==(const Complex<T>& number)
    {
        return ((this->realPart == number.realPart) && (this->imagPart == number.imagPart));
    }



private:
    T realPart;    /*< The real part of the complex number */
    T imagPart;    /*< The imaginary part of the complex number */
    T magnitude;
    T argument;

};

#endif // COMPLEX_H
