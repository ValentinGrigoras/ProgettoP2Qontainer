#include "gioco.h"

Gioco::Gioco(string pNome, int pAnnoRilascio, int pMeseRilascio, char pGenere, int pClassificazionePegi, string pSviluppatore, bool pMultiplayer, bool p4k, bool pOnline, double pPrezzo)
    :nome(pNome), annoRilascio(pAnnoRilascio), genere(pGenere), classificazionePegi(pClassificazionePegi), sviluppatore(pSviluppatore), multiplayer(pMultiplayer), online(pOnline), prezzo(0.0){}

std::string Gioco::getNome() const
{
    return nome;
}

int Gioco::getAnnoRilascio() const
{
    return annoRilascio;
}

char Gioco::getGenere() const
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
