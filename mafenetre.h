#ifndef MAFENETRE_H
#define MAFENETRE_H

#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include "mywindow.h"
#include <QGridLayout>
#include <QMessageBox>

class MaFenetre : public QWidget
{

Q_OBJECT

public:
    MaFenetre();

public slots:
    void affichageResultat();




private:
    QGridLayout *layout;
    MyWidget *myWidget;
    QPushButton *m_bouton;



};





#endif // MAFENETRE_H
