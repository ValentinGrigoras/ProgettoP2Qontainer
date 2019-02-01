#ifndef AGGIUNGIVIEW_H
#define AGGIUNGIVIEW_H

#include <QObject>
#include <QWidget>
#include <QPushButton>
#include <QLineEdit>
#include <QComboBox>
#include <QCheckBox>
#include <QFormLayout>
#include <QLabel>
#include <QGroupBox>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGridLayout>


class AggiungiView : public QWidget
{
    Q_OBJECT
public:
    explicit AggiungiView(QWidget *parent = nullptr);
private:
    QLineEdit * qline_nuovo_gioco_nome;
    QLineEdit * qline_nuovo_gioco_anno;
    QComboBox * combo_nuovo_gioco_genere;
    QComboBox * combo_nuovo_gioco_piattaforma;
    QComboBox * combo_nuovo_gioco_pegi;
    QLineEdit * qline_nuovo_gioco_sviluppatore;
    QCheckBox * check_nuovo_gioco_multiplayer;
    QCheckBox * check_nuovo_gioco_4k;
    QCheckBox * check_nuovo_gioco_online;
    QPushButton * btn_nuovo_gioco_conferma;
    QPushButton * btn_nuovo_gioco_azzerra;
    QPushButton * btn_nuovo_gioco_annulla;

signals:

public slots:
};

#endif // AGGIUNGIVIEW_H
