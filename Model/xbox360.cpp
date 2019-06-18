#include "xbox360.h"

Xbox360::Xbox360()
{

}
unsigned short Xbox360::getAnnoRilascioMinimo() const //22 novembre 2005
{
    return 2005;
}

double Xbox360::PrezzoConsigliato() const
{

    if(getGenere()=="Sportivo") return ((getAnnoRilascio() % 2006)+(2.1*10))*1.7;

    if(getGenere()=="FPS") return (getAnnoRilascio() % 2006)+(2.0*10);
    return 0;

}

std::string Xbox360::getTipo() const
{
    return "Xbox360";
}
