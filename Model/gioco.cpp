#include "gioco.h"

using namespace std;
Gioco::Gioco(string pNome, string pAnnoRilascio, string pGenere, string  pClassificazionePegi, string pSviluppatore, bool pMultiplayer, bool s4k, bool pOnline, string pDescrizione)
    :nome(pNome),
      annoRilascio(pAnnoRilascio),
      genere(pGenere),
      classificazionePegi(pClassificazionePegi),
      sviluppatore(pSviluppatore),
      multiplayer(pMultiplayer),
      supporto_4k(s4k),
      online(pOnline),
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
    descrizione(g.getDescrizione())
{}

bool Gioco::operator==(const Gioco& g) const {
    return nome == g.nome &&
        annoRilascio == g.annoRilascio &&
        genere == g.genere &&
        classificazionePegi == g.classificazionePegi &&
        sviluppatore == g.sviluppatore &&
        multiplayer == g.multiplayer &&
        supporto_4k == g.supporto_4k &&
        online == g.online;
}

bool Gioco::operator!=(const Gioco & g) const
{
    return nome != g.nome ||
        annoRilascio != g.annoRilascio ||
        genere != g.genere ||
        classificazionePegi != g.classificazionePegi ||
        sviluppatore != g.sviluppatore ||
        multiplayer != g.multiplayer ||
        supporto_4k != g.supporto_4k ||
        online != g.online;
}

std::string Gioco::getNome() const
{
    return nome;
}

string Gioco::getAnnoRilascio() const
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

void Gioco::setClassificazionePegi(string pClassificazionePegi)
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
    string print_multiplayer =  std::string(getMultiplayer() ? "Si" : "No");
    string print_online =  std::string(getOnline() ? "Si" : "No");
    string print_s4k =  std::string(get4k() ? "Si" : "No");
    string str= "";
    return str.append("\nTipo:  " +getTipo())
             .append("\nNome:  " +getNome())
            .append("\nAnno di rilascio:  "+ getAnnoRilascio())
            .append("\nSviluppatore:  " + getSviluppatore())
            .append("\nMultiplayer:  " +  print_multiplayer)
            .append("\nOnline: " + print_online)
            .append("\n4k: "+  print_s4k)
            .append("\nPegi: " + getClassificazionePegi())
            .append("\nGenere: " + getGenere())
             .append("\nDescrizione: " + getDescrizione());
}

std::ostream &operator<<(std::ostream & os, const Gioco & g)
{
    return os << "Nome: " << g.getNome() << "\nAnno rilascio: " << g.getAnnoRilascio() << "\n Genere; " << g.getGenere() << "\n Classificazione pegi: " << g.getClassificazionePegi()
                << "\n Sviluppatore: " << g.getSviluppatore() << "\n Multiplayer: " << g.getMultiplayer() << "\n Supporto 4k: " << g.get4k() << "\n Online: " << g.getOnline() << "\n Descrizione: " << g.getDescrizione();
}
