#include "comboboxpegi.h"

ComboBoxPegi::ComboBoxPegi(QWidget* parent):
    QComboBox (parent)
{
    addItem("Pegi 3");
    addItem("Pegi 7");
    addItem("Pegi 12");
    addItem("Pegi 16");
    addItem("Pegi 18");
}
