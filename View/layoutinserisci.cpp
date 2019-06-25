#include "layoutinserisci.h"
#include "Controller/controller.h"

QGroupBox *LayoutInserisci::FeaturesGroup()
{
        QGroupBox *myFeaturesBox = new QGroupBox(tr("Caratteristiche"));
        QHBoxLayout * mychecks = new QHBoxLayout;
        check_nuovo_gioco_multiplayer->setStyleSheet("QCheckBox{font-size : 10pt; font-weight: bold; color:#00264d;}");
        mychecks->addWidget(check_nuovo_gioco_multiplayer);
        check_nuovo_gioco_online->setStyleSheet("QCheckBox{font-size : 10pt; font-weight: bold; color:#00264d;}");
        mychecks->addWidget(check_nuovo_gioco_online);
        check_nuovo_gioco_4k->setStyleSheet("QCheckBox{font-size : 10pt; font-weight: bold; color:#00264d;}");
        mychecks->addWidget(check_nuovo_gioco_4k);
        mychecks->addStretch(1);
        myFeaturesBox->setLayout(mychecks);
        myFeaturesBox->setStyleSheet("QGroupBox{font-size : 10pt; font-weight: bold; color:#00264d;}");
        return myFeaturesBox;
}





LayoutInserisci::LayoutInserisci(QWidget* p):
        QWidget (p),
        qline_nuovo_gioco_nome(new QLineEdit(this)),
        combo_nuovo_gioco_anno(new ComboBoxAnno(this)),
        combo_nuovo_gioco_genere(new ComboBoxGenere(this)),
        combo_nuovo_gioco_pegi(new ComboBoxPegi(this)),
        qline_nuovo_gioco_sviluppatore(new QLineEdit(this)),
        check_nuovo_gioco_multiplayer(new QCheckBox("Multiplayer", this)),
        check_nuovo_gioco_4k(new QCheckBox("4k", this)),
        check_nuovo_gioco_online(new QCheckBox("Online",this)),
        btn_nuovo_gioco_conferma(new QPushButton("Aggiungi al contenitore",this)),
        btn_nuovo_gioco_azzerra(new QPushButton("Azzerra",this)),
        btn_nuovo_gioco_annulla(new QPushButton("Annulla",this)),
          combo_nuovo_gioco_tipo(new ComboBoxTipo(this)),
        textEditDescrizione(new QTextEdit(this))
{

    QVBoxLayout *main_layout = new QVBoxLayout(this);

    QLabel * label_titolo = new QLabel("Aggiungi un nuovo gioco in Qantainer");
    label_titolo->setStyleSheet("QLabel{font-size : 13pt; font-weight: bold; color:#00264d;}");
    label_titolo->setAlignment(Qt::AlignCenter);
    main_layout->addWidget(label_titolo);

    QLabel * label_base = new QLabel("Informazioni di base. Tutti i campi sono obbligatori");
    label_base->setAlignment(Qt::AlignLeft);
    label_base->setStyleSheet("QLabel{font-size : 11pt; font-weight: bold; color:#00264d;}");
    main_layout->addWidget(label_base);

    QLabel * label_tipo = new QLabel("Seleziona il tipo di gioco");
    label_tipo->setAlignment(Qt::AlignLeft);
    label_tipo->setStyleSheet("QLabel{font-size : 11pt; font-weight: bold; color:#00264d;}");
    main_layout->addWidget(label_tipo);
    combo_nuovo_gioco_tipo->setStyleSheet("QComboBox{font-size : 10pt; font-weight: bold; color:#00264d;}");
    main_layout->addWidget(combo_nuovo_gioco_tipo);

    QLabel *label_nome = new QLabel("Nome del gioco");
    label_nome->setStyleSheet("QLabel{font-size : 10pt; font-weight: bold; color:#00264d;}");
    qline_nuovo_gioco_nome->setPlaceholderText("Inserisci il nome del gioco");
    main_layout->addWidget(label_nome);
     main_layout->addWidget(qline_nuovo_gioco_nome);

    QLabel * label_anno = new QLabel("Anno rilascio");
    label_anno->setStyleSheet("QLabel{font-size : 10pt; font-weight: bold; color:#00264d;}");
     main_layout->addWidget(label_anno);
     combo_nuovo_gioco_anno->setStyleSheet("QComboBox{font-size : 10pt; font-weight: bold; color:#00264d;}");
    main_layout->addWidget(combo_nuovo_gioco_anno);

    QLabel * label_sviluppatore = new QLabel(tr("Sviluppatore"));
    label_sviluppatore->setStyleSheet("QLabel{font-size : 10pt; font-weight: bold; color:#00264d;}");
    qline_nuovo_gioco_sviluppatore->setPlaceholderText("Inserisci il nome dello sviluppatore");
    main_layout->addWidget(label_sviluppatore);
    main_layout->addWidget(qline_nuovo_gioco_sviluppatore);
   main_layout->addWidget(FeaturesGroup());

   QLabel * label_pegi = new QLabel(tr("Pegi"));
   label_pegi->setStyleSheet("QLabel{font-size : 10pt; font-weight: bold; color:#00264d;}");
   main_layout->addWidget(label_pegi);
   combo_nuovo_gioco_pegi->setStyleSheet("QComboBox{font-size : 10pt; font-weight: bold; color:#00264d;}");
   main_layout->addWidget(combo_nuovo_gioco_pegi);

    QLabel * label_genere = new QLabel(tr("Genere"));
    label_genere->setStyleSheet("QLabel{font-size : 10pt; font-weight: bold; color:#00264d;}");
    main_layout->addWidget(label_genere);
      combo_nuovo_gioco_genere->setStyleSheet("QComboBox{font-size : 10pt; font-weight: bold; color:#00264d;}");
    main_layout->addWidget(combo_nuovo_gioco_genere);

    QLabel* labe_descrizione = new QLabel(tr("Inserisci una descrizione del gioco"));
    labe_descrizione->setStyleSheet("QLabel{font-size : 10pt; font-weight: bold; color:#00264d;}");
    main_layout->addWidget(labe_descrizione);
    textEditDescrizione->setPlaceholderText("Inserisci una descrizione del gioco");
     textEditDescrizione->setStyleSheet("QEditText{font-size : 10pt; font-weight: bold; color:#00264d;}");
     main_layout->addWidget(textEditDescrizione);

    btn_nuovo_gioco_conferma->setStyleSheet("QPushButton:pressed {background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:1 rgb(0,64,128))} QPushButton{background-color:#00264d; color:#e6e6e6; border: 1px solid black; border-radius: 5px; padding: 8px; font-size:9pt; font-weight:bold; margin-top:10px}");
    main_layout->addWidget(btn_nuovo_gioco_conferma);

    btn_nuovo_gioco_azzerra->setStyleSheet("QPushButton:pressed {background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:1 rgb(0,64,128))} QPushButton{background-color:#00264d; color:#e6e6e6; border: 1px solid black; border-radius: 5px; padding: 8px; font-size:9pt; font-weight:bold; margin-top:10px}");
    main_layout->addWidget(btn_nuovo_gioco_azzerra);

    btn_nuovo_gioco_annulla->setStyleSheet("QPushButton:pressed {background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:1 rgb(0,64,128))} QPushButton{background-color:#00264d; color:#e6e6e6; border: 1px solid black; border-radius: 5px; padding: 8px; font-size:9pt; font-weight:bold; margin-top:10px}");
    main_layout->addWidget(btn_nuovo_gioco_annulla);


    setFixedSize(400,700);

}

ComboBoxTipo *LayoutInserisci::getTipo() const
{
    return combo_nuovo_gioco_tipo;
}

QLineEdit *LayoutInserisci::getNome() const
{
    return qline_nuovo_gioco_nome;
}

ComboBoxAnno *LayoutInserisci::getAnno() const
{
    return combo_nuovo_gioco_anno;
}

QLineEdit *LayoutInserisci::getSviluppatore() const
{
    return qline_nuovo_gioco_sviluppatore;
}

QCheckBox *LayoutInserisci::getMultiplayer() const
{
    return check_nuovo_gioco_multiplayer;
}

QCheckBox *LayoutInserisci::getOnline() const
{
    return check_nuovo_gioco_online;
}

QCheckBox *LayoutInserisci::get4k() const
{
    return check_nuovo_gioco_4k;
}

ComboBoxPegi *LayoutInserisci::getPegi() const
{
    return  combo_nuovo_gioco_pegi;
}

ComboBoxGenere *LayoutInserisci::getGenere() const
{
    return combo_nuovo_gioco_genere;
}

QTextEdit *LayoutInserisci::getDescrizione() const
{
    return textEditDescrizione;
}

QPushButton *LayoutInserisci::getBtnConferma() const
{
    return btn_nuovo_gioco_conferma;
}

QPushButton *LayoutInserisci::getBtnAzzerra() const
{
    return btn_nuovo_gioco_azzerra;
}

QPushButton *LayoutInserisci::getBtnAnnulla() const
{
    return btn_nuovo_gioco_annulla;
}
