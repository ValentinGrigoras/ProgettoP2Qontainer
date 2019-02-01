#include <QApplication>
#include "View/mainview.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainView f;
    f.show();

    return a.exec();
}
