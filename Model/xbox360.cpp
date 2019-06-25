#include "xbox360.h"

Xbox360::Xbox360(std::string pNome, string pAnno, std::string pGenere, string pPegi , std::string pSviluppatore, bool pMultiplayer, bool p4k, bool pOnline, std::string pDescrizione)

    :Gioco(pNome, pAnno, pGenere, pPegi, pSviluppatore, pMultiplayer, p4k, pOnline, pDescrizione)
{

}


std::string Xbox360::getTipo() const
{
    return "Xbox360";
}

Xbox360::Xbox360(const Xbox360 & g) :Gioco(g)
{

}
