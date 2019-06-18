#include "gioco.h"
using namespace std;
Gioco::Gioco(string pNome, int pAnnoRilascio, string pGenere, string  pClassificazionePegi, string pSviluppatore, bool pMultiplayer, bool s4k, bool pOnline, double pPrezzo, string pDescrizione)
    :nome(pNome),
      annoRilascio(pAnnoRilascio),
      classificazionePegi(pClassificazionePegi),
      sviluppatore(pSviluppatore),
      multiplayer(pMultiplayer),
      supporto_4k(s4k),
      online(pOnline),
      prezzo(pPrezzo),
      descrizione(pDescrizione){}

Gioco::Gioco(const Gioco &g):
    nome(g.getNome()),
    annoRilascio(g.getAnnoRilascio()),
    genere(g.getGenere()),
    classificazionePegi(g.getClassificazionePegi()),
    sviluppatore(g.getSviluppatore()),
    multiplayer(g.getMultiplayer()),
    supporto_4k(g.get4k()),
    online(g.getOnline()),
    prezzo(g.PrezzoConsigliato()),
    descrizione(g.getDescrizione())
{}

bool Gioco::operator==(const Gioco& g) const {
    return nome == g.nome &&
        annoRilascio == g.annoRilascio &&
        meseRilascio == g.meseRilascio &&
        genere == g.genere &&
        classificazionePegi == g.classificazionePegi &&
        sviluppatore == g.sviluppatore &&
        multiplayer == g.multiplayer &&
        supporto_4k == g.supporto_4k &&
        online == g.online &&
        prezzo == g.prezzo;
}

bool Gioco::operator!=(const Gioco & g) const
{
    return nome != g.nome ||
        annoRilascio != g.annoRilascio ||
        meseRilascio != g.meseRilascio ||
        genere != g.genere ||
        classificazionePegi != g.classificazionePegi ||
        sviluppatore != g.sviluppatore ||
        multiplayer != g.multiplayer ||
        supporto_4k != g.supporto_4k ||
        online != g.online ||
        prezzo != g.prezzo;
}

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

string  Gioco::getClassificazionePegi() const
{
    return classificazionePegi;
}

string  Gioco::getSviluppatore() const
{
    return sviluppatore;
}

bool  Gioco::getMultiplayer() const
{
    return multiplayer;
}

bool  Gioco::get4k() const
{
    return supporto_4k;
}

bool  Gioco::getOnline() const
{
    return online;
}

double  Gioco::getPrezzo() const
{
    return prezzo;
}

string  Gioco::getDescrizione() const
{
    return descrizione;
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

void Gioco::setDescrizione(const string &value)
{
    descrizione = value;
}

void Gioco::setMultiplayer(const bool pMultiplayer)
{
    multiplayer = pMultiplayer;
}

void Gioco::set4k(const bool p4k)
{
    supporto_4k = p4k;
}

void Gioco::setOnline(const bool pOnline)
{
    online = pOnline;
}

std::string Gioco::getInfo() const
{
    stringstream stream;
    stream << fixed << setprecision(2) <<getPrezzo();
    string str= getTipo()+":";
    return str.append("\nNome: " +getNome())
            .append("\nAnno di rilascio: "+ std::to_string(getAnnoRilascio()))
            .append("\nSviluppatore: " + getSviluppatore())
            .append("\nMultiplayer: " + getMultiplayer()? "Si":"No")
            .append("\nOnline: " + getOnline()?"Si":"No")
            .append("\n4k:  "+ get4k())
            .append("\nPegi:" + getClassificazionePegi())
            .append("\nGenere" + getGenere());
}

std::ostream &operator<<(std::ostream & os, const Gioco & g)
{
    return os << g.getNome();
}
