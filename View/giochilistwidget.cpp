#include "giochilistwidget.h"
#include <QScrollBar>
GiochiListWidget::GiochiListWidget(QWidget *p): parent(p)
{
     addScrollBarWidget(new QScrollBar(Qt::Orientation::Vertical,parent), Qt::AlignRight);
     setAlternatingRowColors(true);
}

void GiochiListWidget::addGioco(Gioco *g)
{
    GiochiListItem* item= new GiochiListItem(g, parent);
    addItem(item);
}

GiochiListItem *GiochiListWidget::takeItem(int index)
{
    GiochiListItem* p=static_cast<GiochiListItem*>(QListWidget::takeItem(index));
    return p;
}
GiochiListItem* GiochiListWidget::takeItem(Gioco * daTogliere){

    bool trovato=false;
    GiochiListItem* daRest=nullptr;
    for(int i=0; i<count()&& !trovato; i++){
        GiochiListItem* temp=static_cast<GiochiListItem*>(item(i));
        if(temp->getItemAddress()==daTogliere){
            daRest=static_cast<GiochiListItem*>(takeItem(i));
            trovato=true;
        }
        return daRest;
    }
}



GiochiListItem* GiochiListWidget::currentItem() const{
    return static_cast<GiochiListItem*>(QListWidget::currentItem());

}
