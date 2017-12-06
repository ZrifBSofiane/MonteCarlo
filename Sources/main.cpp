#include <QApplication>
#include <QtGui>
//#include "mywindow.h"
#include <QLabel>

#include "mafenetre.h"

int main( int argc, char **argv )
{
  QApplication app( argc, argv );

 // MyWidget myWidget;
  //myWidget.show();

  MaFenetre fenetre;
  fenetre.show();


  return app.exec();
}
