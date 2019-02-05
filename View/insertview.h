#ifndef INSERTVIEW_H
#define INSERTVIEW_H
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



class Controller;


class InsertView: public QDialog
{
    Q_OBJECT
public:
    InsertView();
private:
    QLineEdit * qline_nuovo_gioco_nome;
    QLineEdit * qline_nuovo_gioco_anno;
    QComboBox * combo_nuovo_gioco_genere;
    QComboBox * combo_nuovo_gioco_piattaforma;
    QComboBox * combo_nuovo_gioco_pegi;
    QLineEdit * qline_nuovo_gioco_sviluppatore;
    QCheckBox * check_nuovo_gioco_multiplayer;
    QCheckBox * check_nuovo_gioco_4k;
    QCheckBox * check_nuovo_gioco_online;
    QPushButton * btn_nuovo_gioco_conferma;
    QPushButton * btn_nuovo_gioco_azzerra;
    QPushButton * btn_nuovo_gioco_annulla;
    QLabel * label_prezzo;
    QPushButton * btn_calcola_prezzo;
    QLineEdit * qline_prezzo;

    Controller *controller;
public:
    QString getNome()const;
};

#endif // INSERTVIEW_H
