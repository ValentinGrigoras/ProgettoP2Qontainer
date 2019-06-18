#include "ps4.h"

Ps4::Ps4()
{

}

unsigned short Ps4::getAnnoRilascioMinimo() const //	15 novembre 2013
{
    return 2013;
}

double Ps4::PrezzoConsigliato() const
{

    if(getGenere()=="Sportivo") return ((getAnnoRilascio() % 2006)+(2.1*10))*1.7;

    if(getGenere()=="FPS") return (getAnnoRilascio() % 2006)+(2.0*10);

    return 0;

}

std::string Ps4::getTipo() const
{
    return "Ps4";
}
