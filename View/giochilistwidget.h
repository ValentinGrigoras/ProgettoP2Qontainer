#ifndef GIOCHILISTWIDGET_H
#define GIOCHILISTWIDGET_H

#include <QListWidget>
#include <QPushButton>
#include"giochilistitem.h"

class GiochiListWidget : public QListWidget
{
      Q_OBJECT
    QWidget* parent;
    QAction* onClickAction, *onRightClickAction;

public:
    GiochiListWidget(QWidget* =nullptr);
    void addGioco(Gioco*);
    GiochiListItem* takeItem(int );
    GiochiListItem* currentItem()const;
    GiochiListItem* takeItem(Gioco*);

signals:
    void   signalEliminaElementoDaList(Gioco*);
};

#endif // GIOCHILISTWIDGET_H
