#include "tp1.h"
#include <QApplication>
#include <time.h>

int isMandelbrot(Point z, int n, Point point){
    if(n>0){
        if(z.length()>2){
                return n;} 
        else {
            float zx=z.x;
            float zy=z.y;
            float pointx=point.x;
            float pointy=point.y;
            Point newP;
            newP.x=(zx*zx + zy*zy + pointx);
            newP.y=(2*zx*zy+pointy);
            return isMandelbrot(newP, n-1, pointy);}} 
    else {return 0;}

    return 0;
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow* w = new MandelbrotWindow(isMandelbrot);
    w->show();

    a.exec();
}



