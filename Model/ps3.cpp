#include "ps3.h"



Ps3::Ps3(std::string pNome, string pAnno, std::string pGenere, string pPegi , std::string pSviluppatore, bool pMultiplayer, bool p4k, bool pOnline, std::string pDescrizione)

    :Gioco(pNome, pAnno, pGenere, pPegi, pSviluppatore, pMultiplayer, p4k, pOnline, pDescrizione){}



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
