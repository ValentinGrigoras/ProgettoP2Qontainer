#ifndef XBOXONE_H
#define XBOXONE_H
#include "gioco.h"

class XboxOne: public Gioco
{
public:
    XboxOne();
    virtual unsigned short int getAnnoRilascioMinimo()const; //	22 novembre 2013
    double PrezzoConsigliato()const;
        string getTipo()const override;
};

#endif // XBOXONE_H
