#include "Circle.h"

bool Circle::isInside(double x, double y)const {
   double dx = x - this->x;
    double dy = y - this->y;
    return (dx * dx + dy * dy) < (r * r);
}

char Circle::getIcon(){
    return 'C';
}

void Circle::update(int sw,int sh) {
    if(x+r>sw || x-r<0)vx=-vx;
    if(y+r>sh || y-r<0)vy=-vy;
    x+=vx;
    y+=vy;
}


