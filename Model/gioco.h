#ifndef GIOCO_H
#define GIOCO_H
#include<string>

using std::string;

class Gioco
{
private:
     string nome;
     int annoRilascio;
     int meseRilascio;
     char genere;
     int classificazionePegi;
     string sviluppatore;
     bool multiplayer;
     bool supporto_4k;
     bool online;
     double prezzo;

public:
    Gioco(string pNome="", int pAnnoRilascio=2019, int pMeseRilascio=1, char pGenere='FPS', int pClassificazionePegi=18, string pSviluppatore="EaSports", bool pMultiplayer=true, bool p4k=false, bool pOnline=true, double pPrezzo=0.0);//costruttore a 5 parametri con valori di default

    //getter
    string getNome() const;
    int getAnnoRilascio()const;
    int getMeseRilascio()const;
    char getGenere()const;
    int getClassificazionePegi()const;
    string getSviluppatore()const;
    bool getMultiplayer()const;
    bool get4k()const;
    bool getOnline()const;


    //setter
    void setNome(string pNome); /*p sta per parametro della funzione, ovvero pNome = variabile nome intesa come
 parametro di una certa funzione. Utile per distinguere i campi dati di una classe con i parametri di una funzione*/
    void setAnnoRilascio(int pAnnoRilascio);
    void setGenere(char pGenere);
    void setClassificazionePegi(int pClassificazionePegi);

    /*metodo virtuale puro*/
    virtual double PrezzoConsigliato()const =0; // mi calcola il prezzo consigliato in base alla data d'uscita, in base alla piattaforma e in base al genere. Il prezzo rispecchia opprossimamente il prezzo dei gioco al giorno d'oggi.
    virtual Gioco* Clone() const=0;

    //distruttore virtuale
    virtual ~Gioco()=default; //c++11

protected:
    //metodo virtuale puro
virtual unsigned short int getAnnoRilascioMinimo()const = 0; // questo metodo mi ritorna l'anno minimo che può avere un gioco come anno di rilascio, in quanto coincide con l'anno dell'uscita della piattaforma del gioco. Per esempio il PS3 è uscito nel 2006, quindi non ci possono essere giochi sulla PS3 usciti prima di quella data.

};

#endif // GIOCO_H
