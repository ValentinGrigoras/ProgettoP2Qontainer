#ifndef XBOX360_H
#define XBOX360_H
#include "gioco.h"

class Xbox360:public Gioco
{
public:
    Xbox360(string="", string = "2019", string ="FPS", string ="18", string ="EaSports", bool =true, bool =false, bool =true, string="vuoto");
    virtual unsigned short int getAnnoRilascioMinimo()const; //22 novembre 2005
    double PrezzoConsigliato()const;
        string getTipo()const override;
            Xbox360(const Xbox360&); // costruttore di copia
};

#endif // XBOX360_H
