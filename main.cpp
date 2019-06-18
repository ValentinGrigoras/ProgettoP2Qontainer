#include <QApplication>
#include "Controller/controller.h"
#include "Model/gestionegiochi.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Controller  w (new GestioneGiochi());
        //w.show();
    a.setWindowIcon(QIcon(":Images/icon.png"));
    w.show();

    return a.exec();
}
