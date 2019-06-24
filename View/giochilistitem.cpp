#include "giochilistitem.h"


GiochiListItem::GiochiListItem(Gioco* i, QWidget* p):
    item(i), parent(p)
{
    update();


}

void GiochiListItem::update(){

   setText(QString::fromStdString(item->getInfo()));

}

bool GiochiListItem::isEmpty() const
{
    return item==nullptr? true : false;
}

Gioco* GiochiListItem::getItemAddress() const{
    return item;
}
