#ifndef CONTROLLER_H
#define CONTROLLER_H
#include <QObject>
#include "View/aggiungiview.h"


class  MainView;

class Controller : public QObject
{
    Q_OBJECT
private:
MainView* view;

public:
    explicit Controller( QObject *parent = nullptr, MainView * v=nullptr);
signals:

public slots:
void showAggiungiView()const;
};

#endif // CONTROLLER_H
