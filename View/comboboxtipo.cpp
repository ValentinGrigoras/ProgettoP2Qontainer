#include "comboboxtipo.h"

ComboBoxTipo::ComboBoxTipo(QWidget* parent):
    QComboBox (parent)
{
    addItem("Ps3");
    addItem("Ps4");
    addItem("Xbox360");
    addItem("XboxOne");
}
