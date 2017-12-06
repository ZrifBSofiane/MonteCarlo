#include"mafenetre.h"
#include <iostream>


MaFenetre::MaFenetre() : QWidget()
{
    int tailleFenetrePrincipale = 600;
    setFixedSize(tailleFenetrePrincipale,tailleFenetrePrincipale);

    layout = new QGridLayout(this);
    myWidget = new MyWidget(this);
    layout->addWidget(myWidget,0,0);


     //myWidget.show();



   // BOUTON
    m_bouton = new QPushButton("Afficher résultat !",this);
    m_bouton->setGeometry(0,5,200,20);
    m_bouton->move(tailleFenetrePrincipale/2-m_bouton->width()/2,5);
    m_bouton->setCursor(Qt::PointingHandCursor);


    QObject::connect(m_bouton,SIGNAL(clicked()),this,SLOT(affichageResultat()));

}

void MaFenetre::affichageResultat()
{
    double numero = myWidget->GetPi();
    std::cout << numero << endl;
    QString resultat = QString::number(numero);
    QMessageBox boiteDialogue;
    boiteDialogue.setText("Pi is approximately " + resultat);
    boiteDialogue.exec();

}


