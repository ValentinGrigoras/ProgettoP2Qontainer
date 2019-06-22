#ifndef LAYOUTINSERISCI_H
#define LAYOUTINSERISCI_H

#include <QDialog>
#include <QObject>
#include <QWidget>
#include <QPushButton>
#include <QLineEdit>
#include <QComboBox>
#include <QCheckBox>
#include <QFormLayout>
#include <QLabel>
#include <QGroupBox>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGridLayout>
#include <QTextEdit>
#include"comboboxgenere.h"
#include"comboboxanno.h"
#include"comboboxpegi.h"
#include"comboboxtipo.h"



class LayoutInserisci : public QWidget
{
    Q_OBJECT
private:
    QLineEdit * qline_nuovo_gioco_nome;
    ComboBoxAnno * combo_nuovo_gioco_anno;
    ComboBoxGenere * combo_nuovo_gioco_genere;
    ComboBoxPegi * combo_nuovo_gioco_pegi;
    QLineEdit * qline_nuovo_gioco_sviluppatore;
    QCheckBox * check_nuovo_gioco_multiplayer;
    QCheckBox * check_nuovo_gioco_4k;
    QCheckBox * check_nuovo_gioco_online;
    QPushButton * btn_nuovo_gioco_conferma;
    QPushButton * btn_nuovo_gioco_azzerra;
    QPushButton * btn_nuovo_gioco_annulla;
  ComboBoxTipo * combo_nuovo_gioco_tipo;
  QTextEdit *textEditDescrizione;
    QGroupBox * FeaturesGroup();

private slots:
 //void slotAzzera()const;

public:
    LayoutInserisci(QWidget* =nullptr);
    ComboBoxTipo* getTipo()const;

    QLineEdit *getNome() const;
    ComboBoxAnno *getAnno() const;
    QLineEdit *getSviluppatore() const;
    QCheckBox * getMultiplayer()const;
    QCheckBox * getOnline()const;
    QCheckBox * get4k()const;
    ComboBoxPegi* getPegi()const;
    ComboBoxGenere* getGenere()const;
    QTextEdit * getDescrizione()const;
    QPushButton* getBtnConferma()const;
    QPushButton* getBtnAzzerra()const;
    QPushButton* getBtnAnnulla()const;


};

#endif // LAYOUTINSERISCI_H
