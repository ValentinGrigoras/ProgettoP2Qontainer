#ifndef LAYOUTRICERCA_H
#define LAYOUTRICERCA_H
#include "giochilistwidget.h"
#include "comboboxtipo.h"
#include"comboboxanno.h"
#include"comboboxpegi.h"

#include <QLineEdit>
#include <QCheckBox>
#include <QComboBox>
#include <QPushButton>
#include <QFormLayout>
#include <QRadioButton>
#include <Model/gestionegiochi.h>

class LayoutRicerca: public QWidget
{
    Q_OBJECT
private:
    QLineEdit *cercaPerNome;
    QCheckBox *cbNome;
    ComboBoxTipo *cercaPerTipo;
     QCheckBox *cbTipo;
     ComboBoxPegi*cercaPerPegi;
      QCheckBox *cbPegi;
    GestioneGiochi* modello;
    QPushButton *cerca;
    QPushButton *reset;
    GiochiListWidget *list;
public:
    LayoutRicerca(QWidget* = nullptr);
    QLineEdit *getCercaPerNome() const;
    ComboBoxTipo *getCercaPerTipo() const;
    ComboBoxPegi *getCercaPerPegi() const;

    QCheckBox *getCbNome() const;
    QCheckBox *getCbPegi() const;
    QCheckBox *getCbTipo() const;

    QPushButton *getCerca() const;
    QPushButton *getReset() const;
    GiochiListWidget *getList() const;

private slots:
    void slotDisableElements()const;
public slots:
    void slotResetRicerca()const;
signals:
    void signalEliminaTuttiElementi(GestioneGiochi*);
};

#endif // LAYOUTRICERCA_H
