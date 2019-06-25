#include "xboxone.h"

XboxOne::XboxOne(std::string pNome, string pAnno, std::string pGenere, string pPegi , std::string pSviluppatore, bool pMultiplayer, bool p4k, bool pOnline, std::string pDescrizione)
:Gioco(pNome, pAnno, pGenere, pPegi, pSviluppatore, pMultiplayer, p4k, pOnline, pDescrizione)
{

}

std::string XboxOne::getTipo() const
{
    return "XboxOne";
}

XboxOne::XboxOne(const XboxOne & g):Gioco(g)
{

}
