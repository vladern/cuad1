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
    //IUALDAD de números complejos
	bool TComplejo::operator==(const TComplejo& num)
    {
        if(this->re==num.re && this->im==num.im)
        {
            return true;
        }
        return false;
    }
    //DESIGUALDAD de números complejos
	bool TComplejo::operator!=(const TComplejo& num)
    {
        if(this->re==num.re && this->im==num.im)
        {
            return false;
        }
        return true;
    }
    // Calcula el Argumento (en Radianes)
	double TComplejo::Arg(void)
    {
        const double PI = std::atan(1.0)*4;
        double div = (this->im / this->re);
        double alfa = atan(div);
        if(this->im>0 && this->re<0)// b/-a
        {
            return PI-alfa;
        }else if(this->im<0 && this->re<0) // -b/-a
        {
            return PI+alfa;
        }else if(this->im<0 && this->re>0) // -b/a
        {
            return (2*PI)-alfa;
        }else // a/b
        {
            return alfa;
        }
    } 
    // Calcula el Módulo 
	double TComplejo::Mod(void)
    {
       return sqrt(pow(this->re,2)+pow(im,2));
    }
    
    ostream & operator<<(ostream &os,const TComplejo &num)
    {

        os<<"("<<num.Re()<<" "<<num.Im()<<")";
        return os;
    }