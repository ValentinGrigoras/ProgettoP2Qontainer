#ifndef PS3_H
#define PS3_H

#include <QObject>
#include "playstation.h"
class Ps3 : public Playstation
{
private:

public:
    Ps3();
protected:
     unsigned short int getAnnoRilascioMinimo()const; // 11 novembre 2006
    double PrezzoConsigliato()const;
};


#endif // PS3_H
