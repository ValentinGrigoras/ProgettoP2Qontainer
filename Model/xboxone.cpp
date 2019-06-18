#include "xboxone.h"

XboxOne::XboxOne()
{

}

unsigned short XboxOne::getAnnoRilascioMinimo() const //	22 novembre 2013
{
    return 2013;
}

double XboxOne::PrezzoConsigliato() const
{

    if(getGenere()=="Sportivo") return ((getAnnoRilascio() % 2006)+(2.1*10))*1.7;

    if(getGenere()=="FPS") return (getAnnoRilascio() % 2006)+(2.0*10);

    return 0;

}

std::string XboxOne::getTipo() const
{
    return "XboxOne";
}
