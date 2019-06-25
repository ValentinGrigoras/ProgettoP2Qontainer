#include "ps4.h"

Ps4::Ps4(std::string pNome, std::string pAnno, std::string pGenere, string pPegi , std::string pSviluppatore, bool pMultiplayer, bool p4k, bool pOnline, std::string pDescrizione)
 :Gioco(pNome, pAnno, pGenere, pPegi, pSviluppatore, pMultiplayer, p4k, pOnline, pDescrizione){}



std::string Ps4::getTipo() const
{
    return "Ps4";
}

Ps4::Ps4(const Ps4 & g):Gioco(g)
{

}
