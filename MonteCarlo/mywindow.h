#ifndef MYWINDOW_H
#define MYWINDOW_H

#include <QtGui>
#include <QWidget>
#include <QLabel>


class MyWidget : public QWidget
{
    Q_OBJECT
public:
   MyWidget(QWidget *parent = 0);
   double GetPi();

private:

   double piValue;



protected:
    void paintEvent(QPaintEvent *event);
    bool calculRayon(int x, int y, int decallage, int rayon);

signals:

public slots:

};





#endif // MYWINDOW_H
