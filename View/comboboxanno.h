#ifndef COMBOBOXANNO_H
#define COMBOBOXANNO_H
#include<QComboBox>

class ComboBoxAnno : public QComboBox
{
public:
    ComboBoxAnno(QWidget* =nullptr);
    void CreateComboBox(std::string);
};

#endif // COMBOBOXANNO_H
