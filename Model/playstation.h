#ifndef PLAYSTATION_H
#define PLAYSTATION_H

#include <QObject>
#include "gioco.h"

//classe derivata virtuale pura
class Playstation: public Gioco // classe virtuale pura perchè i metodi virtuali puri non sono stati ridefiniti
{
private:


public:
    Playstation();

};

#endif // PLAYSTATION_H
