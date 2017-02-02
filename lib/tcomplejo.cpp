/* TComplejo.h
 *
 *  Created on: 1 feb. 2017
 *      Author: plakaplaka
 */
 #include"tcomplejo.h"
//Constructor de copia
 TComplejo::TComplejo(const TComplejo& num)
 {   
     this->re=num.re;
     this->im=num.im;
 }
 TComplejo::~TComplejo()
 {
     this->re=0;
     this->im=0;
 }
 void TComplejo::negativo(double &re,double &im)
 {
     if(re==(-0.0) && im==(-0.0))
     {
         re=0.0;
     }else if(im==(-0.0))
     {
         im=0.0;
     }else if(re==(-0.0))
     {
         re=0.0;
     }
 }
// Sobrecarga del operador asignación
TComplejo& TComplejo::operator = (const TComplejo& num)
{
    //negativo(num.re,num.im);
    this->re=num.re;
    this->im=num.im;
    return *this;
}
// SOBRECARGA DE OPERADORES ARITMÉTICOS;
TComplejo TComplejo::operator+(const TComplejo& num)
{
    //negativo(num.re,num.im);
    double re = this->re + num.re;
    double im = this->im + num.im;
    TComplejo nuevo = TComplejo(re,im);
    return nuevo;
}
TComplejo TComplejo::operator-(const TComplejo& num)
{
    //negativo(num.re,num.im);
    double re = this->re - num.re;
    double im = this->im - num.im;
    TComplejo nuevo = TComplejo(re,im);
    return nuevo;
}
TComplejo TComplejo::operator*(const TComplejo& num)
{
    //negativo(num.re,num.im);
    double re = this->re * num.re;
    double im = this->im * num.im;
    TComplejo nuevo = TComplejo(re,im);
    return nuevo;
}
TComplejo TComplejo::operator+(double num)
{
    if(num==(-0.0))
    {
        num=0.0;
    }
    double re = this->re + num;
    double im = this->im + 0;
    TComplejo nuevo = TComplejo(re,im);
    return nuevo;
}
TComplejo TComplejo::operator-(double num)
{
    if(num==(-0.0))
    {
        num=0.0;
    }
    double re = this->re - num;
    double im = this->im - 0;
    TComplejo nuevo = TComplejo(re,im);
    return nuevo;
}
TComplejo TComplejo::operator*(double num)
{
    if(num==(-0.0))
    {
        num=0.0;
    }
    double re = this->re * num;
    double im = this->im * 0;
    TComplejo nuevo = TComplejo(re,im);
    return nuevo;
}