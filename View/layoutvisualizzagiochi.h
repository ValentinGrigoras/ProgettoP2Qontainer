#ifndef LAYOUT_VISUALIZZA_H
#define LAYOUT_VISUALIZZA_H

#include <QObject>
#include <QWidget>
#include <QPushButton>
#include <QScrollBar>
#include<QVBoxLayout>

#include"giochilistwidget.h"
#include"layoutvisualizzaitem.h"

class LayoutVisualizzaGiochi : public QWidget
{
    Q_OBJECT
private:
    QPushButton *btnElimina;
    QPushButton* btnModifica;
    GiochiListWidget *list;
    LayoutVisualizzaItem* dialog;
    QWidget* parent;
public:
    explicit LayoutVisualizzaGiochi(QWidget *parent = nullptr);
     ~LayoutVisualizzaGiochi();

    GiochiListWidget *getList() const;

    QPushButton *getBtnElimina() const;

    QPushButton *getBtnModifica() const;

signals:
 void signalElementoSelezionato(bool=true)const;
public slots:
    void slotElementoSelezionato(bool= true)const;

    void slotRowChanged()const;
};

#endif // LAYOUT_VISUALIZZA_H
