#include "controller.h"

Controller::Controller( QObject *parent,MainView * v ) : QObject(parent), view(v)
{

}



void Controller::showAggiungiView() const
{
    AggiungiView * new_w = new AggiungiView;
    new_w->show();


}
