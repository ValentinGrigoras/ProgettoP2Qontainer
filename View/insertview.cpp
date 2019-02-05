#include "insertview.h"
#include "Controller/controller.h"

InsertView::InsertView()
{

    QFormLayout *left_form = new QFormLayout;
    QHBoxLayout *main_layout = new QHBoxLayout;
    QVBoxLayout *second_layout = new QVBoxLayout;

    QLabel * label_titolo = new QLabel("Aggiungi un nuovo gioco in Qantainer");
    QLabel * label_base = new QLabel("Informazioni di base");
    label_titolo->setStyleSheet("QLabel{font-size : 13pt; font-weight: bold; color:#00264d;}");
    label_titolo->setAlignment(Qt::AlignCenter);
    second_layout->addWidget(label_titolo);
    label_base->setAlignment(Qt::AlignLeft);
    label_base->setStyleSheet("QLabel{font-size : 11pt; font-weight: bold; color:#00264d;}");
    second_layout->addWidget(label_base);

    QLabel *label_nome = new QLabel("Nome del gioco");
    label_nome->setStyleSheet("QLabel{font-size : 10pt; font-weight: bold; color:#00264d;}");
    qline_nuovo_gioco_nome = new QLineEdit;
    left_form->addRow(label_nome,qline_nuovo_gioco_nome);


    QLabel * label_anno = new QLabel("Anno rilascio");
    label_anno->setStyleSheet("QLabel{font-size : 10pt; font-weight: bold; color:#00264d;}");
    qline_nuovo_gioco_anno = new QLineEdit;
    left_form->addRow(label_anno,qline_nuovo_gioco_anno);

    QLabel * label_genere = new QLabel(tr("Genere"));
    label_genere->setStyleSheet("QLabel{font-size : 10pt; font-weight: bold; color:#00264d;}");
    combo_nuovo_gioco_genere = new QComboBox;
    combo_nuovo_gioco_genere->addItem("FPS");
    left_form->addRow(label_genere,combo_nuovo_gioco_genere);


    QLabel * label_piattaforma = new QLabel("Piattaforma");
    label_piattaforma->setStyleSheet("QLabel{font-size : 10pt; font-weight: bold; color:#00264d;}");
    combo_nuovo_gioco_piattaforma = new QComboBox;
    combo_nuovo_gioco_piattaforma->addItem("PS3");
    combo_nuovo_gioco_piattaforma->addItem("PS4");
    combo_nuovo_gioco_piattaforma->addItem("XBOX 360");
    combo_nuovo_gioco_piattaforma->addItem("XBOX ONE");
    combo_nuovo_gioco_piattaforma->addItem("PC");
    left_form->addRow(label_piattaforma,combo_nuovo_gioco_piattaforma);

    QLabel * label_pegi = new QLabel("Pegi");
    label_pegi->setStyleSheet("QLabel{font-size : 10pt; font-weight: bold; color:#00264d;}");
    combo_nuovo_gioco_pegi = new QComboBox;
    combo_nuovo_gioco_pegi->addItem("3");
    combo_nuovo_gioco_pegi->addItem("7");
    combo_nuovo_gioco_pegi->addItem("12");
    combo_nuovo_gioco_pegi->addItem("16");
    combo_nuovo_gioco_pegi->addItem("18");
    left_form->addRow(label_pegi,combo_nuovo_gioco_pegi);

    QLabel * label_sviluppatore = new QLabel("Sviluppatore");
    label_sviluppatore->setStyleSheet("QLabel{font-size : 10pt; font-weight: bold; color:#00264d;}");
    qline_nuovo_gioco_sviluppatore = new QLineEdit;
    left_form->addRow(label_sviluppatore,qline_nuovo_gioco_sviluppatore);

    QGridLayout * opzioni_grid = new QGridLayout;
    QGroupBox * nuovo_gioco_opzioni = new QGroupBox(tr("Caratteristiche gioco"));
     nuovo_gioco_opzioni->setStyleSheet("QGroupBox::title {subcontrol-origin: margin; subcontrol-position: top center;} QGroupBox{font-size : 9pt; font-weight: bold; color:#00264d;border:1px solid #00264d; border-radius:5px; padding-top:50px;}");

    QLabel * label_4k = new QLabel("Supporto 4k");
    label_4k->setStyleSheet("QLabel{font-size : 10pt; font-weight: bold; color:#00264d;}");
    check_nuovo_gioco_4k = new QCheckBox;


    QLabel * label_multiplayer = new QLabel("Supporto multiplayer");
    label_multiplayer->setStyleSheet("QLabel{font-size : 10pt; font-weight: bold; color:#00264d;}");
    check_nuovo_gioco_multiplayer = new QCheckBox;


    QLabel * label_online = new QLabel ("Supporto online");
    label_online->setStyleSheet("QLabel{font-size : 10pt; font-weight: bold; color:#00264d;}");
    check_nuovo_gioco_online = new QCheckBox;

opzioni_grid->addWidget(label_4k,0,0,1,1);
opzioni_grid->addWidget(check_nuovo_gioco_4k,0,1,1,1);
opzioni_grid->addWidget(label_multiplayer,0,2,1,1);
opzioni_grid->addWidget(check_nuovo_gioco_multiplayer,0,3,1,1);
opzioni_grid->addWidget(label_online,0,4,1,1);
opzioni_grid->addWidget(check_nuovo_gioco_online,0,5,1,1);

    nuovo_gioco_opzioni->setLayout(opzioni_grid);

    QFormLayout * form_prezzo = new QFormLayout;
    QLabel *label_prezzo = new QLabel("Prezzo del gioco");
    label_prezzo->setStyleSheet("QLabel{font-size : 10pt; font-weight: bold; color:#00264d;}");
    qline_prezzo = new QLineEdit;
    form_prezzo->addRow(label_prezzo,qline_prezzo);
    btn_calcola_prezzo = new QPushButton(tr("Calcola prezzo consigliato"));
    btn_calcola_prezzo->setStyleSheet("QPushButton:pressed {background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:1 rgb(0,64,128))} QPushButton{background-color:#00264d; color:#e6e6e6; border: 1px solid black; border-radius: 5px; padding: 8px; font-size:9pt; font-weight:bold; margin-top:10px}");
    label_prezzo = new QLabel("50.49€");
        label_prezzo->setStyleSheet("QLabel{font-size : 19pt; font-weight: bold; color:#00264d;}");
    form_prezzo->addRow(btn_calcola_prezzo,label_prezzo);



    QHBoxLayout * nuovo_gioco_bottoni_layout = new QHBoxLayout;
    btn_nuovo_gioco_conferma = new QPushButton(tr("Aggiungi"));
    btn_nuovo_gioco_conferma->setStyleSheet("QPushButton:pressed {background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:1 rgb(0,64,128))} QPushButton{background-color:#00264d; color:#e6e6e6; border: 1px solid black; border-radius: 5px; padding: 8px; font-size:9pt; font-weight:bold; margin-top:10px}");
    btn_nuovo_gioco_azzerra = new QPushButton(tr("Azzerra"));
    btn_nuovo_gioco_azzerra->setStyleSheet("QPushButton:pressed {background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:1 rgb(0,64,128))} QPushButton{background-color:#00264d; color:#e6e6e6; border: 1px solid black; border-radius: 5px; padding: 8px; font-size:9pt; font-weight:bold; margin-top:10px}");
    btn_nuovo_gioco_annulla = new QPushButton(tr("Annulla"));
    btn_nuovo_gioco_annulla->setStyleSheet("QPushButton:pressed {background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:1 rgb(0,64,128))} QPushButton{background-color:#00264d; color:#e6e6e6; border: 1px solid black; border-radius: 5px; padding: 8px; font-size:9pt; font-weight:bold; margin-top:10px}");
    nuovo_gioco_bottoni_layout -> addWidget(btn_nuovo_gioco_conferma);
    nuovo_gioco_bottoni_layout->addWidget(btn_nuovo_gioco_azzerra);
    nuovo_gioco_bottoni_layout->addWidget(btn_nuovo_gioco_annulla);

    second_layout->addLayout(left_form);
    second_layout->addWidget(nuovo_gioco_opzioni);
    second_layout->addLayout(form_prezzo);
    second_layout->addLayout(nuovo_gioco_bottoni_layout);



    main_layout->addLayout(second_layout);
    setLayout(main_layout);
    this->setFixedSize(500,550);
    this->setWindowFlags(this->windowFlags() ^ Qt::WindowContextHelpButtonHint);
    this->setWindowFlags(this->windowFlags() | Qt::WindowStaysOnTopHint);

    //connect(btn_nuovo_gioco_conferma, SIGNAL(clicked()), controller, SLOT(slot_AddGame()));

}

QString InsertView::getNome() const
{
    return qline_nuovo_gioco_nome->text();
}
