#include "mywindow.h"
#include <random>
#include <math.h>
#include <QMessageBox>
#include <cstring>


MyWidget::MyWidget(QWidget *parent) : QWidget(parent)
{
    piValue = 0;
}

double MyWidget::GetPi()
{
    return piValue;
}

void MyWidget::paintEvent(QPaintEvent *event)
{

    setFixedSize(700,700);


    QPainter painter(this);

 // ************************ AFFICHAGE FENETRE *******************

    double tailleCarre = 500;
    double decallageFenetre = 20;





    // Rectangle
    QRect rectangle(decallageFenetre,decallageFenetre,tailleCarre,tailleCarre);
    painter.drawRect(rectangle);

    // Cercle
    QRect rectangleCercle(decallageFenetre,decallageFenetre,tailleCarre,tailleCarre);
    painter.drawEllipse(rectangleCercle);

    // Droite Verticale
    QLine ligneVerticale(tailleCarre/2 + decallageFenetre,decallageFenetre,tailleCarre/2 + decallageFenetre, tailleCarre + decallageFenetre);
    painter.drawLine(ligneVerticale);

    // Droite Horizontale
    QLine ligneHorizontale(decallageFenetre,tailleCarre/2 + decallageFenetre,tailleCarre + decallageFenetre, tailleCarre/2 + decallageFenetre);
    painter.drawLine(ligneHorizontale);

    // ******************* FIN AFFICHAGE FENETRE ***********************

    // Initialisation random
        srand(time(NULL));
        // Caste en int pour utiliser le rand
        int a = (int)decallageFenetre;
        int b = (int)decallageFenetre + tailleCarre;
        int c = (int)tailleCarre;

        // On met en Gras les points et on change la couleur
        QPen myPen(Qt::red, 4);
        painter.setPen(myPen);
        int nombrePointIn = 0;
        int nombrePointTotal = 1000;

        for(int i=0;i<=nombrePointTotal;i++)
        {
            int coordX = rand() % (b-a) +a;
            int coordY = rand() % (b-a) +a;
            painter.drawPoint(coordX,coordY);
            if(calculRayon(coordX,coordY,a,c))
            {
                nombrePointIn ++;
            }
        }

        piValue = (double)nombrePointIn/(double)nombrePointTotal*4;

        /*QString nombre = QString::number(piValue);
        m_label->text().clear();
        QString resultat = "Pi Value : "+nombre;
        m_label->setText(resultat);
        m_label->show();*/


       /* QMessageBox box;
        QString nombre = QString::number(piValue);
        box.setText(nombre);
        box.exec();*/
}

bool MyWidget::calculRayon(int x, int y, int decallage, int rayonCercle)
{
    // On enlève le décallage de l'écran
    int x1 = x - decallage;
    int y1 = y - decallage;
    double rayon = sqrt(pow(x1,2) + pow(y1,2));
    bool isIn = false;
    if(rayon <= rayonCercle)
    {
        isIn = true;
    }
    return isIn;
}

