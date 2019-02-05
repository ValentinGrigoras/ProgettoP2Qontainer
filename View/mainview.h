#ifndef MAINVIEW_H
#define MAINVIEW_H

#include <QObject>
#include <QWidget>
#include <QPushButton>
#include <QComboBox>
#include <QLabel>
#include<QGroupBox>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLineEdit>
#include <QListView>
#include <QAction>
#include <QMenuBar>
#include <QMenu>
#include <QFormLayout>
#include<QGridLayout>
#include "Controller/controller.h"



class Controller;


class MainView : public QWidget
{
    Q_OBJECT

private:
QPushButton * btn_filtra;
QPushButton * btn_aggiungi;
QPushButton * btn_cancella;
QPushButton * btn_modifica;
QPushButton * btn_elimina;
QPushButton * btn_cerca;

QMenuBar *menuBar;
QMenu * menu;
QMenu * menu2;

QAction * menu_importa;
QAction * menu_esporta;
QAction * menu_salva;
QAction * menu_exit;

QAction * scopri_qantainer;
QAction * scopri_svilupp;
QAction * manuale;

QComboBox * combo_genere;
QComboBox * combo_pegi;
QComboBox * combo_piattaforma;
QComboBox * combo_sviluppatore;
QComboBox * combo_anno_rilascio;
QComboBox * combo_4k;
QComboBox * combo_multiplayer;
QComboBox * combo_online;

QLineEdit * qline_prezzo_min;
QLineEdit * qline_prezzo_max;
QLineEdit * qline_cerca;

QVBoxLayout * window_layout;
QHBoxLayout * main_layout;
QVBoxLayout * filtri_layout;
QHBoxLayout * prezzi_layout;
QHBoxLayout * filters_button_layout;
QHBoxLayout * services_layout;
QVBoxLayout * list_layout;
QVBoxLayout * view_layout;
QGridLayout * layout_interno_filtri;
QVBoxLayout *menuLayout;
QHBoxLayout *menuLayoutH;

QGroupBox * filtri_box;
QGroupBox * services_box;
QListView * listItem;

Controller *controller;
InsertView * insert_v;



//metodi per creare le varie box
void createFiltriBox();
void createServiciesBox();
void createListItem();
void createMenuBar();
public:
    explicit MainView(QWidget *parent = nullptr);

signals:

public slots:

};

#endif // MAINVIEW_H
