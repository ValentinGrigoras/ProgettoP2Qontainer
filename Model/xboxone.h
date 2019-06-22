#ifndef XBOXONE_H
#define XBOXONE_H
#include "gioco.h"

class XboxOne: public Gioco
{
public:
    XboxOne(string="", string = "2019", string ="FPS", string ="18", string ="EaSports", bool =true, bool =false, bool =true, string="vuoto");
    virtual unsigned short int getAnnoRilascioMinimo()const; //	22 novembre 2013
    double PrezzoConsigliato()const;
        string getTipo()const override;
        XboxOne(const XboxOne&); // costruttore di copia
};

#endif // XBOXONE_H
