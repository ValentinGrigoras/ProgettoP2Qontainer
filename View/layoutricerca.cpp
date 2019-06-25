#include "layoutricerca.h"
#include <QMessageBox>
#include "Controller/controller.h"
#include "Model/dlinkedlist.h"
#include "Model/ps3.h"
#include "Model/ps4.h"
#include "Model/xbox360.h"
#include "Model/xboxone.h"
LayoutRicerca::LayoutRicerca(QWidget * p):
    QWidget (p),
    cercaPerNome(new QLineEdit(this)),
    cbNome(new QCheckBox(this)),
    cercaPerTipo(new ComboBoxTipo(this)),
    cbTipo(new QCheckBox(this)),
    cercaPerPegi(new ComboBoxPegi(this)),
    cbPegi(new QCheckBox(this)),
    cerca(new QPushButton("Cerca",this)),
    reset(new QPushButton("Reset",this)),
    list(new GiochiListWidget(this))
{

    //layout per le due ComboBox
QVBoxLayout *inner_layout = new QVBoxLayout();

//QGroupBox attiva filtri
QGroupBox *QGroup_activate_filter = new QGroupBox(tr("Attiva filtri"));

//QGroupBox configura filtri
QGroupBox *QGroup_set_filter = new QGroupBox(tr("Configura i filtri"));

QGroup_activate_filter->setStyleSheet("QGroupBox::title {subcontrol-origin: margin;subcontrol-position: top center;} QGroupBox{ font-size: 10pt;font-weight: bold;color:#00264d; padding: 8px;border: 2px solid #00264d;}");

//layout interno attiva filtri
QHBoxLayout* activate_layout = new QHBoxLayout();

//layout interno bottoni
QVBoxLayout* button_layout = new QVBoxLayout();

//layout interno configura filtri
QGridLayout* set_filters_layout = new QGridLayout();

//layout  filtri e bottoni
QHBoxLayout *filtri_button = new QHBoxLayout();

//layout principale  filtri , bottoni, lista
QVBoxLayout *main_layout = new QVBoxLayout();
cercaPerNome->setEnabled(false);
cercaPerTipo->setEnabled(false);
cercaPerPegi->setEnabled(false);

cbNome->setEnabled(true);
cbTipo->setEnabled(true);
cbPegi->setEnabled(true);

QGroup_set_filter->setStyleSheet("QGroupBox::title {subcontrol-origin: margin;subcontrol-position: top center;} QGroupBox{ font-size: 10pt;font-weight: bold;color:#00264d; padding: 8px;border: 2px solid #00264d;}");
cerca->setStyleSheet("QPushButton:pressed {background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:1 rgb(0,64,128))} QPushButton{background-color:#00264d; color:#e6e6e6; border: 1px solid black; border-radius: 5px; padding: 8px; font-size:9pt; font-weight:bold; margin-top:10px}");
reset->setStyleSheet("QPushButton:pressed {background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:1 rgb(0,64,128))} QPushButton{background-color:#00264d; color:#e6e6e6; border: 1px solid black; border-radius: 5px; padding: 8px; font-size:9pt; font-weight:bold; margin-top:10px}");
cerca->setFixedSize(270,75);
reset->setFixedSize(270,75);


QLabel * label_tipo = new QLabel(tr("Tipo"));
label_tipo->setStyleSheet("QLabel{font-size : 10pt; font-weight: bold; color:#00264d;}");
activate_layout->addWidget(label_tipo);
activate_layout->addWidget(cbTipo);

QLabel * label_nome = new QLabel(tr("Nome"));
label_nome->setStyleSheet("QLabel{font-size : 10pt; font-weight: bold; color:#00264d;}");
activate_layout->addWidget(label_nome);
activate_layout->addWidget(cbNome);


QLabel * label_pegi = new QLabel(tr("Pegi"));
label_pegi->setStyleSheet("QLabel{font-size : 10pt; font-weight: bold; color:#00264d;}");
activate_layout->addWidget(label_pegi);
activate_layout->addWidget(cbPegi);

QLabel * label_set_Tipo = new QLabel(tr("Tipo"));
label_set_Tipo->setStyleSheet("QLabel{font-size : 10pt; font-weight: bold; color:#00264d;}");

QLabel * label_set_Name = new QLabel(tr("Nome"));
label_set_Name->setStyleSheet("QLabel{font-size : 10pt; font-weight: bold; color:#00264d;}");

QLabel * label_set_Anno = new QLabel(tr("Anno"));
label_set_Anno->setStyleSheet("QLabel{font-size : 10pt; font-weight: bold; color:#00264d;}");

QLabel * label_set_Pegi= new QLabel(tr("Pegi"));
label_set_Pegi->setStyleSheet("QLabel{font-size : 10pt; font-weight: bold; color:#00264d;}");

cercaPerTipo->setStyleSheet("QComboBox{font-size : 10pt; font-weight: bold; color:#00264d;}");
cercaPerNome->setStyleSheet("QComboBox{font-size : 10pt; font-weight: bold; color:#00264d;}");
cercaPerPegi->setStyleSheet("QComboBox{font-size : 10pt; font-weight: bold; color:#00264d;}");

set_filters_layout->addWidget(label_set_Tipo,0,0,1,3);
set_filters_layout->addWidget(cercaPerTipo,1,0,1,3);
set_filters_layout->addWidget(label_set_Name,0,3,1,3);
set_filters_layout->addWidget(cercaPerNome,1,3,1,3);
set_filters_layout->addWidget(label_set_Pegi,0,6,1,3);
set_filters_layout->addWidget(cercaPerPegi,1,6,1,3);

QGroup_set_filter->setLayout(set_filters_layout);
QGroup_set_filter->setFixedHeight(110);
QGroup_set_filter->setFixedWidth(400);

QGroup_activate_filter->setLayout(activate_layout);
QGroup_activate_filter->setFixedHeight(110);
QGroup_activate_filter->setFixedWidth(400);

button_layout->addWidget(reset);
button_layout->addWidget(cerca);

inner_layout->addWidget(QGroup_activate_filter);
inner_layout->addWidget(QGroup_set_filter);

filtri_button->addLayout(inner_layout);
filtri_button->addLayout(button_layout);

main_layout->addLayout(filtri_button);
main_layout->addWidget(list);

setLayout(main_layout);

connect(cbNome,SIGNAL(clicked(bool)),this,SLOT(slotDisableElements()));
connect(cbTipo,SIGNAL(clicked(bool)),this,SLOT(slotDisableElements()));
connect(cbPegi,SIGNAL(clicked(bool)),this,SLOT(slotDisableElements()));

}

QLineEdit *LayoutRicerca::getCercaPerNome() const
{
    return cercaPerNome;
}

ComboBoxTipo *LayoutRicerca::getCercaPerTipo() const
{
    return cercaPerTipo;
}


ComboBoxPegi *LayoutRicerca::getCercaPerPegi() const
{
    return cercaPerPegi;
}

QCheckBox *LayoutRicerca::getCbNome() const
{
    return cbNome;
}


QCheckBox *LayoutRicerca::getCbPegi() const
{
    return cbPegi;
}

QCheckBox *LayoutRicerca::getCbTipo() const
{
    return cbTipo;
}

QPushButton *LayoutRicerca::getCerca() const
{
    return cerca;
}

QPushButton *LayoutRicerca::getReset() const
{
    return reset;
}

GiochiListWidget *LayoutRicerca::getList() const
{
    return  list;
}

void LayoutRicerca::slotDisableElements() const
{
    cbTipo->isChecked()?
                cercaPerTipo->setEnabled(true):
               cercaPerTipo->setEnabled(false);



    cbNome->isChecked()?
                cercaPerNome->setEnabled(true):
                cercaPerNome->setEnabled(false);


    cbPegi->isChecked()?
                cercaPerPegi->setEnabled(true):
                cercaPerPegi->setEnabled(false);
}

void LayoutRicerca::slotResetRicerca() const
{
    cercaPerNome->clear();
    cercaPerTipo->setCurrentIndex(0);
    cercaPerPegi->setCurrentIndex(0);
    list->clear();
     list->update();
}
