#include "gioco.h"

Gioco::Gioco(string pNome, int pAnnoRilascio, int pMeseRilascio, string pGenere, int pClassificazionePegi, string pSviluppatore, bool pMultiplayer, bool s4k, bool pOnline, double pPrezzo)
    :nome(pNome), annoRilascio(pAnnoRilascio), meseRilascio(pMeseRilascio), genere(pGenere), classificazionePegi(pClassificazionePegi), sviluppatore(pSviluppatore), multiplayer(pMultiplayer), supporto_4k(s4k), online(pOnline), prezzo(pPrezzo){}

std::string Gioco::getNome() const
{
    return nome;
}

int Gioco::getAnnoRilascio() const
{
    return annoRilascio;
}

string Gioco::getGenere() const
{
    return genere;
}

int Gioco::getClassificazionePegi() const
{
    return classificazionePegi;
}

void Gioco::setNome(std::string pNome)
{
    nome = pNome;
}

void Gioco::setAnnoRilascio(int pAnnoRilascio)
{
    annoRilascio = pAnnoRilascio;
}

void Gioco::setGenere(char pGenere)
{
    genere = pGenere;
}

void Gioco::setClassificazionePegi(int pClassificazionePegi)
{
    classificazionePegi = pClassificazionePegi;
}
