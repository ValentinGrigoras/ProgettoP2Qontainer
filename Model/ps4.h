#ifndef PS4_H
#define PS4_H

#include <QObject>
#include "gioco.h"
class Ps4: public Gioco
{
public:
  Ps4(string="", string = "2019", string ="FPS", string ="18", string ="EaSports", bool =true, bool =false, bool =true, string="vuoto");

    string getTipo()const override;
    Ps4(const Ps4&); // costruttore di copia
};

#endif // PS4_H
