#include "ps3.h"



Ps3::Ps3(std::string pNome, int pAnno, std::string pGenere, string pPegi , std::string pSviluppatore, bool pMultiplayer, bool p4k, bool pOnline, double pPrezzo, std::string pDescrizione)

    :Gioco(pNome, pAnno, pGenere, pPegi, pSviluppatore, pMultiplayer, p4k, pOnline, pPrezzo, pDescrizione)
{

}

unsigned short Ps3::getAnnoRilascioMinimo() const // 11 novembre 2006
{
    return 2006;
}

double Ps3::PrezzoConsigliato() const
{

    if(getGenere()=="Sportivo") return ((getAnnoRilascio() % 2006)+(2.1*10))*1.7;

    if(getGenere()=="FPS") return (getAnnoRilascio() % 2006)+(2.0*10);

    return 0;

}

Ps3::Ps3(const Ps3 & g): Gioco(g)
{

}

std::string Ps3::getTipo() const
{
     return "Ps3";
}

bool Ps3::operator==(const Ps3 & g) const
{
    return Gioco::operator==(g);
}

bool Ps3::operator!=(const Ps3 & g) const
{
     return Gioco::operator!=(g);
}

std::ostream &operator<<(std::ostream & os, const Ps3 & g)
{
    return operator<<(os, static_cast<const Gioco&>(g));
}
