#ifndef PS3_H
#define PS3_H

#include <QObject>
#include "gioco.h"
class Ps3 : public Gioco
{
private:

public:
  Ps3(string="", string = "2019", string ="FPS", string ="18", string ="EaSports", bool =true, bool =false, bool =true, string="vuoto");//costruttore a 5 parametri con valori di default


      virtual ~Ps3() override=default;
    Ps3(const Ps3&); // costruttore di copia
   string getTipo()const override; // metodo virtuale

    bool  operator==(const Ps3&) const;
    bool  operator!=(const Ps3&) const;

};
std::ostream& operator<<(std::ostream&, const Ps3&);

#endif // PS3_H
