#include "mainview.h"


void MainView::createFiltriBox()
{
    QLabel * label_genere = new QLabel("Genere");
    QLabel * label_pegi = new QLabel("Pegi");
    QLabel * label_piattaforma = new QLabel("Piattaforma");
    QLabel * label_sviluppatore = new QLabel("Sviluppatore");
    QLabel * label_4k = new QLabel("Supporto 4k");
    QLabel * label_multiplayer = new QLabel("Supporto multiplayer");
    QLabel * label_online = new QLabel ("Supporto online");
    QLabel * label_prezzo_min = new QLabel("Prezzo Min");
    QLabel * label_prezzo_max = new QLabel("Prezzo Max");

    filtri_box = new QGroupBox(tr("Tutti i filtri"));
    filtri_box->setStyleSheet("QGroupBox::title {subcontrol-origin: margin; subcontrol-position: top center;} QGroupBox{font-size : 9pt; font-weight: bold; color:#00264d;border:1px solid #00264d; border-radius:5px; padding-top:50px;}");

    filtri_layout = new QVBoxLayout;

    QFormLayout * form_filtri = new QFormLayout;

    label_genere->setStyleSheet("QLabel{font-size : 9pt; font-weight: bold; color:#00264d;}");
    combo_genere = new QComboBox();
    combo_genere->addItem("Tutti");
    combo_genere->addItem("FPS");
    combo_genere->addItem("Sportivo");
    form_filtri->addRow(label_genere,combo_genere);

    label_pegi->setStyleSheet("QLabel{font-size : 9pt; font-weight: bold; color:#00264d;}");
    combo_pegi = new QComboBox();
    combo_pegi->addItem("Tutti");
    combo_pegi->addItem("3");
    combo_pegi->addItem("18");
    form_filtri->addRow(label_pegi,combo_pegi);

    label_piattaforma = new QLabel(this);
    label_piattaforma->setText("Piattaforma");
    label_piattaforma->setStyleSheet("QLabel{font-size : 9pt; font-weight: bold; color:#00264d;}");
    combo_piattaforma = new QComboBox();
    combo_piattaforma->addItem("Tutti");
    combo_piattaforma->addItem("PC");
    combo_piattaforma->addItem("PS3");
    form_filtri->addRow(label_piattaforma,combo_piattaforma);


    label_sviluppatore->setStyleSheet("QLabel{font-size : 9pt; font-weight: bold; color:#00264d;}");
    combo_sviluppatore = new QComboBox();
    combo_sviluppatore->addItem("Tutti");
    combo_sviluppatore->addItem("EA Sports");
    combo_sviluppatore->addItem("Ubisoft");
    form_filtri->addRow(label_sviluppatore,combo_sviluppatore);

    label_4k->setStyleSheet("QLabel{font-size : 9pt; font-weight: bold; color:#00264d;}");
    combo_4k = new QComboBox();
    combo_4k->addItem("Tutti");
    combo_4k->addItem("Si");
    combo_4k->addItem("No");
    form_filtri->addRow(label_4k,combo_4k);

    label_multiplayer->setStyleSheet("QLabel{font-size : 9pt; font-weight: bold; color:#00264d;}");
    combo_multiplayer = new QComboBox();
    combo_multiplayer->addItem("Tutti");
    combo_multiplayer->addItem("Si");
    combo_multiplayer->addItem("No");
    form_filtri->addRow(label_multiplayer,combo_multiplayer);

    label_online->setStyleSheet("QLabel{font-size : 9pt; font-weight: bold; color:#00264d;}");
    combo_online = new QComboBox();
    combo_online->addItem("Tutti");
    combo_online->addItem("Si");
    combo_online->addItem("No");

    form_filtri->addRow(label_online,combo_online);


    label_prezzo_min->setStyleSheet("QLabel{font-size : 9pt; font-weight: bold; color:#00264d;}");
    qline_prezzo_min = new QLineEdit;
    form_filtri->addRow(label_prezzo_min,qline_prezzo_min);

    label_prezzo_max->setStyleSheet("QLabel{font-size : 9pt; font-weight: bold; color:#00264d;}");
    qline_prezzo_max = new QLineEdit;
    form_filtri->addRow(label_prezzo_max,qline_prezzo_max);

    btn_filtra = new QPushButton;
    btn_filtra->setText("Filtra");
    btn_filtra->setStyleSheet("QPushButton:pressed {background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:1 rgb(0,64,128))} QPushButton{background-color:#00264d; color:#e6e6e6; border: 1px solid black; border-radius: 5px; padding: 8px; font-size:9pt; font-weight:bold; margin-top:10px}");
    btn_cancella = new QPushButton;
    btn_cancella->setText("Reimposta");
    btn_cancella->setStyleSheet("QPushButton:pressed {background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:1 rgb(0,64,128))} QPushButton{background-color:#00264d; color:#e6e6e6; border: 1px solid black; border-radius: 5px; padding: 8px; font-size:9pt; font-weight:bold; margin-top:10px}");

    form_filtri->addRow(btn_cancella,btn_filtra);

    form_filtri->setVerticalSpacing(20);
    filtri_layout->addLayout(form_filtri);
    filtri_box->setLayout(filtri_layout);

}

void MainView::createServiciesBox()
{

    services_box = new QGroupBox(tr("Servizi"));
    services_box->setStyleSheet("QGroupBox::title {subcontrol-origin: margin; subcontrol-position: top center;} QGroupBox{font-size : 9pt; font-weight: bold; color:#00264d;border:1px solid #00264d; border-radius:5px; padding: 5px;}");

    btn_aggiungi = new QPushButton("Aggiungi");
    btn_aggiungi->setStyleSheet("QPushButton:pressed {background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:1 rgb(0,64,128))} QPushButton{background-color:#00264d; color:#e6e6e6; border: 1px solid black; border-radius: 5px; padding: 8px; font-size:9pt; font-weight:bold}");

    btn_modifica = new QPushButton("Modifica");
    btn_modifica->setStyleSheet("QPushButton:pressed {background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:1 rgb(0,64,128))} QPushButton{background-color:#00264d; color:#e6e6e6; border: 1px solid black; border-radius: 5px; padding: 8px; font-size:9pt; font-weight:bold}");

    btn_cerca = new QPushButton("Cerca");
    btn_cerca->setStyleSheet("QPushButton:pressed {background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:1 rgb(0,64,128))} QPushButton{background-color:#00264d; color:#e6e6e6; border: 1px solid black; border-radius: 5px; padding: 8px; font-size:9pt; font-weight:bold}");

    btn_elimina = new QPushButton("Elimina");
    btn_elimina->setStyleSheet("QPushButton:pressed {background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:1 rgb(0,64,128))} QPushButton{background-color:#00264d; color:#e6e6e6; border: 1px solid black; border-radius: 5px; padding: 8px; font-size:9pt; font-weight:bold}");

    QLabel* label_c = new QLabel("Ricerca un gioco nel contenitore");
    label_c->setStyleSheet("QLabel{font-size : 9pt; font-weight: bold; color:#00264d;}");
    qline_cerca = new QLineEdit;
    services_layout = new QHBoxLayout;

    services_layout->addWidget(btn_aggiungi);
    services_layout->addWidget(btn_modifica);
    services_layout->addWidget(btn_elimina);
    services_layout->addWidget(label_c);
    services_layout->addWidget(qline_cerca);
    services_layout->addWidget(btn_cerca);

    services_box->setLayout(services_layout);
}

void MainView::createListItem()
{

    listItem = new QListView;
    QLabel* risultati = new QLabel("Risultati");
    risultati->setStyleSheet("QLabel{font-size : 9pt; font-weight: bold; color:#00264d;}");
    risultati->setAlignment(Qt::AlignCenter);
    list_layout = new QVBoxLayout;
    list_layout->addWidget(risultati);
    list_layout->addWidget(listItem);



}

void MainView::createMenuBar()
{
    menuBar = new QMenuBar;
     menu = new QMenu("File", menuBar);
    menu_importa = new QAction("Importa", menu);
    menu_esporta = new QAction("Esporta",menu);
    menu_salva = new QAction("Salva su file",menu);
    menu_exit = new QAction("Esci", menu);
    menuBar->addMenu(menu);
    menu->addAction(menu_importa);
    menu->addAction(menu_esporta);
    menu->addAction(menu_salva);
    menu->addAction(menu_exit);
    menuLayout = new QVBoxLayout;

    menu2 = new QMenu("Aiuto", menuBar);
   scopri_qantainer = new QAction("Scopri Qantainer", menu);
   scopri_svilupp = new QAction("Scopri lo sviluppatore",menu);
   manuale = new QAction("Manuale utente",menu);

   menuBar->addMenu(menu2);
   menu2->addAction(manuale);
   menu2->addAction(scopri_svilupp);
   menu2->addAction(scopri_qantainer);

   menuLayout = new QVBoxLayout;

   menuLayout->addWidget(menuBar);

}

MainView::MainView(QWidget *parent) : QWidget(parent), controller(new Controller(this))
{

    this->setFixedSize(1200,600);
    createFiltriBox();
    createServiciesBox();
    createListItem();
    createMenuBar();
    QVBoxLayout * full_layout = new QVBoxLayout;
    main_layout = new QHBoxLayout;
    view_layout = new QVBoxLayout;
    main_layout->addWidget(filtri_box);
    view_layout->addWidget(services_box);
    view_layout->addLayout(list_layout);
    main_layout->addLayout(view_layout);
    main_layout->setStretchFactor(filtri_box,1);
    main_layout->setStretchFactor(view_layout,4);
    full_layout->addLayout(menuLayout);
    full_layout->addLayout(main_layout);

    setLayout(full_layout);

    //connect
    connect(menu_exit,SIGNAL(triggered()),this,SLOT(close()));
    connect(btn_aggiungi,SIGNAL(clicked()),controller,SLOT(showAggiungiView()));
     //sconnect(btn_aggiungi,SIGNAL(clicked()),controller,SLOT(showInsertView()));
    //connect(btn_aggiungi,SIGNAL(clicked()),this,SLOT(aggiungiEntry()));
}




