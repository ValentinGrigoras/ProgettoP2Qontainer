#ifndef LAYOUTVISUALIZZAITEM_H
#define LAYOUTVISUALIZZAITEM_H

#include <QObject>
#include <QDialog>
#include <QFormLayout>
#include <QLabel>
#include <QPushButton>
#include <QTextEdit>
#include <QWidget>

#include "giochilistitem.h"

class LayoutVisualizzaItem: public QDialog
{
    Q_OBJECT

private:
    GiochiListItem *listItem;
    QPushButton* btnClose;
    QPushButton* salvaModifica;
    Gioco* g;
    QLabel *immagine;
    QTextEdit* descrizione;
public:
    LayoutVisualizzaItem(GiochiListItem*, QWidget* =nullptr);
public slots:
    void  slotSalvaModifica()const;
};

#endif // LAYOUTVISUALIZZAITEM_H
