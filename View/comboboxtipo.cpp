#include "comboboxtipo.h"

ComboBoxTipo::ComboBoxTipo(QWidget* parent):
    QComboBox (parent)
{
    addItem("PS3");
    addItem("PS4");
    addItem("XBOX360");
    addItem("XBOXONE");
}
