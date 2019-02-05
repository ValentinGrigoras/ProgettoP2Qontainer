#ifndef CONTROLLER_H
#define CONTROLLER_H
#include <QObject>
#include "Model/gestionegiochi.h"
class InsertView;
class MainView;

class Controller : public QObject
{
    Q_OBJECT
private:
MainView* view;
InsertView* insert_view;
GestioneGiochi * container;
public:
Controller();
    explicit Controller( MainView * , InsertView * v = nullptr,  QObject *parent = nullptr);
~Controller();
signals:

public slots:
void slot_AddGame()const;
void showAggiungiView();
};

#endif // CONTROLLER_H
