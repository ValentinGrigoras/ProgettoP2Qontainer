#ifndef GIOCHILISTITEM_H
#define GIOCHILISTITEM_H
#include <QListWidgetItem>
#include <Model/gioco.h>

class GiochiListItem : public QListWidgetItem
{
private:
    Gioco *item;
    QWidget* parent;
public:
    GiochiListItem(Gioco*, QWidget* =nullptr);
    Gioco* getItemAddress() const;
    void update();
   bool isEmpty()const;
};

#endif // GIOCHILISTITEM_H
