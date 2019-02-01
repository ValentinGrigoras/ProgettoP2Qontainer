#include "aggiungiview.h"

AggiungiView::AggiungiView(QWidget *parent) : QWidget(parent)
{

    QFormLayout *left_form = new QFormLayout;
    QHBoxLayout *main_layout = new QHBoxLayout;
    QVBoxLayout *second_layout = new QVBoxLayout;

    QLabel * label_titolo = new QLabel("Aggiungi un nuovo gioco in Qantainer");
    label_titolo->setStyleSheet("QLabel{font-size : 13pt; font-weight: bold; color:#00264d;}");
    label_titolo->setAlignment(Qt::AlignCenter);
    second_layout->addWidget(label_titolo);

    QLabel *label_nome = new QLabel("Nome del gioco");
    qline_nuovo_gioco_nome = new QLineEdit;
    left_form->addRow(label_nome,qline_nuovo_gioco_nome);


    QLabel * label_anno = new QLabel("Anno rilascio");
    qline_nuovo_gioco_anno = new QLineEdit;
    left_form->addRow(label_anno,qline_nuovo_gioco_anno);

    QLabel * label_genere = new QLabel(tr("Genere"));
    combo_nuovo_gioco_genere = new QComboBox;
    combo_nuovo_gioco_genere->addItem("FPS");
    left_form->addRow(label_genere,combo_nuovo_gioco_genere);


    QLabel * label_piattaforma = new QLabel("Piattaforma");
    combo_nuovo_gioco_piattaforma = new QComboBox;
    combo_nuovo_gioco_piattaforma->addItem("PS3");
    combo_nuovo_gioco_piattaforma->addItem("PS4");
    combo_nuovo_gioco_piattaforma->addItem("XBOX 360");
    combo_nuovo_gioco_piattaforma->addItem("XBOX ONE");
    combo_nuovo_gioco_piattaforma->addItem("PC");
    left_form->addRow(label_piattaforma,combo_nuovo_gioco_piattaforma);

    QLabel * label_pegi = new QLabel("Pegi");
    combo_nuovo_gioco_pegi = new QComboBox;
    combo_nuovo_gioco_pegi->addItem("3");
    combo_nuovo_gioco_pegi->addItem("7");
    combo_nuovo_gioco_pegi->addItem("12");
    combo_nuovo_gioco_pegi->addItem("16");
    combo_nuovo_gioco_pegi->addItem("18");
    left_form->addRow(label_pegi,combo_nuovo_gioco_pegi);

    QLabel * label_sviluppatore = new QLabel("Sviluppatore");
    qline_nuovo_gioco_sviluppatore = new QLineEdit;
    left_form->addRow(label_sviluppatore,qline_nuovo_gioco_sviluppatore);

    QGridLayout * opzioni_grid = new QGridLayout;
    QGroupBox * nuovo_gioco_opzioni = new QGroupBox(tr("Caratteristiche gioco"));
     nuovo_gioco_opzioni->setStyleSheet("QGroupBox::title {subcontrol-origin: margin; subcontrol-position: top center;} QGroupBox{font-size : 9pt; font-weight: bold; color:#00264d;border:1px solid #00264d; border-radius:5px; padding-top:50px;}");

    QLabel * label_4k = new QLabel("Supporto 4k");
    check_nuovo_gioco_4k = new QCheckBox;


    QLabel * label_multiplayer = new QLabel("Supporto multiplayer");
    check_nuovo_gioco_multiplayer = new QCheckBox;


    QLabel * label_online = new QLabel ("Supporto online");
    check_nuovo_gioco_online = new QCheckBox;

opzioni_grid->addWidget(label_4k,0,0,1,1);
opzioni_grid->addWidget(check_nuovo_gioco_4k,0,1,1,1);
opzioni_grid->addWidget(label_multiplayer,0,2,1,1);
opzioni_grid->addWidget(check_nuovo_gioco_multiplayer,0,3,1,1);
opzioni_grid->addWidget(label_online,0,4,1,1);
opzioni_grid->addWidget(check_nuovo_gioco_online,0,5,1,1);

    nuovo_gioco_opzioni->setLayout(opzioni_grid);


    QHBoxLayout * nuovo_gioco_bottoni_layout = new QHBoxLayout;
    btn_nuovo_gioco_conferma = new QPushButton(tr("Aggiungi"));
    btn_nuovo_gioco_azzerra = new QPushButton(tr("Azzerra"));
    btn_nuovo_gioco_annulla = new QPushButton(tr("Annulla"));
    nuovo_gioco_bottoni_layout -> addWidget(btn_nuovo_gioco_conferma);
    nuovo_gioco_bottoni_layout->addWidget(btn_nuovo_gioco_azzerra);
    nuovo_gioco_bottoni_layout->addWidget(btn_nuovo_gioco_annulla);

    second_layout->addLayout(left_form);
    second_layout->addWidget(nuovo_gioco_opzioni);
    second_layout->addLayout(nuovo_gioco_bottoni_layout);



    main_layout->addLayout(second_layout);
    setLayout(main_layout);
}
