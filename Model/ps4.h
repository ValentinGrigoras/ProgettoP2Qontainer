#ifndef PS4_H
#define PS4_H

#include <QObject>
#include "playstation.h"
class Ps4: public Playstation
{
public:
    Ps4();
    virtual unsigned short int getAnnoRilascioMinimo()const; //15 novembre 2013
};

#endif // PS4_H
