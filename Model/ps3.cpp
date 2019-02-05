#include "ps3.h"

Ps3::Ps3()
{

}

unsigned short Ps3::getAnnoRilascioMinimo() const // 11 novembre 2006
{
    return 2006;
}

double Ps3::PrezzoConsigliato() const
{

    if(getGenere()=="Sportivo") return (getAnnoRilascio() % 2006)+(2.1*10);

    if(getGenere()=="FPS") return (getAnnoRilascio() % 2006)+(2.0*10);

    return 0;
}
