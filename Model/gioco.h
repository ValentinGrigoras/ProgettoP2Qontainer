#ifndef GIOCO_H
#define GIOCO_H
#include<string>
#include <sstream>
#include <iostream>
#include <iomanip>

using std::string;

class Gioco
{
private:
     string nome;
     string annoRilascio;
     string genere;
     string classificazionePegi;
     string sviluppatore;
     bool multiplayer;
     bool supporto_4k;
     bool online;
     string descrizione;

public:
    Gioco(string="", string = "2019", string ="FPS", string ="18", string ="EaSports", bool =true, bool =false, bool =true, string="vuoto");//costruttore a 5 parametri con valori di default
    Gioco(const Gioco&); // costruttore di copia

    //getter
    string getNome() const;
    string getAnnoRilascio()const;
    string getGenere()const;
    string getClassificazionePegi()const;
    string getSviluppatore()const;
    bool getMultiplayer()const;
    bool get4k()const;
    bool getOnline()const;
    string getDescrizione()const;


    //setter
    void setNome(string pNome); /*p sta per parametro della funzione, ovvero pNome = variabile nome intesa come
 parametro di una certa funzione. Utile per distinguere i campi dati di una classe con i parametri di una funzione*/
    void setAnnoRilascio(int pAnnoRilascio);
    void setGenere(char pGenere);
    void setClassificazionePegi(string  pClassificazionePegi);
     void setDescrizione(const string &value);
     void setMultiplayer(const bool pMultiplayer);
     void set4k(const bool p4k);
     void setOnline(const bool pOnline);

    /*metodo virtuale puro*/
    virtual string getTipo()const =0;

      string getInfo()const;

    //distruttore virtuale
    virtual ~Gioco()=default; //c++11

protected:
    //metodo virtuale puro
virtual unsigned short int getAnnoRilascioMinimo()const = 0; // questo metodo mi ritorna l'anno minimo che può avere un gioco come anno di rilascio, in quanto coincide con l'anno dell'uscita della piattaforma del gioco. Per esempio il PS3 è uscito nel 2006, quindi non ci possono essere giochi sulla PS3 usciti prima di quella data.

    //operatori
    virtual bool operator==(const Gioco&) const;
    virtual bool operator!=(const Gioco&) const;
};

 std::ostream& operator<<(std::ostream& , const Gioco& );
#endif // GIOCO_H
