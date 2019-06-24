#include "layoutvisualizzagiochi.h"

LayoutVisualizzaGiochi::LayoutVisualizzaGiochi(QWidget *parent) :
    QWidget(parent),
    btnElimina(new QPushButton("Elimina", this)),
    btnModifica(new QPushButton("Modifica",this)),
    list(new GiochiListWidget(this)),
    dialog(nullptr)
{
    QVBoxLayout* vBox=new QVBoxLayout(this);
    btnElimina->setEnabled(false);
    btnElimina->setStyleSheet("QPushButton:pressed {background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:1 rgb(0,64,128))} QPushButton{background-color:#00264d; color:#e6e6e6; border: 1px solid black; border-radius: 5px; padding: 8px; font-size:9pt; font-weight:bold; margin-top:10px}");

    btnModifica->setEnabled(false);
    btnModifica->setStyleSheet("QPushButton:pressed {background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:1 rgb(0,64,128))} QPushButton{background-color:#00264d; color:#e6e6e6; border: 1px solid black; border-radius: 5px; padding: 8px; font-size:9pt; font-weight:bold; margin-top:10px}");
QLabel *label_lista = new  QLabel(tr("I tuoi giochi: "));
label_lista->setStyleSheet("QLabel{font-size : 10pt; font-weight: bold; color:#00264d;}");
    vBox->addWidget(label_lista);
    vBox->addWidget(list);
    list->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    list->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    QHBoxLayout* l= new QHBoxLayout();
    l->addWidget(btnModifica);
    l->addWidget(btnElimina);


    vBox->addLayout(l);

    connect(list, SIGNAL(currentRowChanged(int)), this, SLOT(slotElementoSelezionato()));

    connect(this, SIGNAL(signalElementoSelezionato(bool)), this,SLOT(slotElementoSelezionato(bool)));

    setFixedWidth(400);
    setFixedHeight(700);
    list->update();
}

QPushButton *LayoutVisualizzaGiochi::getBtnElimina() const
{
    return btnElimina;
}

QPushButton *LayoutVisualizzaGiochi::getBtnModifica() const
{
    return btnModifica;
}

LayoutVisualizzaGiochi::~LayoutVisualizzaGiochi(){
    delete list;
    delete  btnElimina;
}

GiochiListWidget *LayoutVisualizzaGiochi::getList() const
{
    return list;
}

void LayoutVisualizzaGiochi::slotElementoSelezionato(bool t)const{
    btnElimina->setEnabled(t);
    btnModifica->setEnabled(t);

}
void LayoutVisualizzaGiochi::slotRowChanged()const{
    emit slotElementoSelezionato(true);
}
