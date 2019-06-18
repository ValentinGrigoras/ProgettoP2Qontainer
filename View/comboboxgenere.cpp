#include "comboboxgenere.h"

ComboBoxGenere::ComboBoxGenere(QWidget* parent):
    QComboBox (parent)
{
    addItem("Arcade");
    addItem("Battle Royale");
    addItem("Casual Game");
    addItem("FPS");
    addItem("Free-to-play");
    addItem("Guida");
    addItem("MMORPG");
    addItem("Picchiaduro");
    addItem("Quiz");
    addItem("Simulazione");
     addItem("Sportivo");
    addItem("Strategia");

}
