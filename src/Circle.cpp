#include "Circle.h"

bool Circle::isInside(double x, double y) const
{
    double dx = x - this->x;
    double dy = y - this->y;
    return (dx * dx + dy * dy) < (r * r);
}

char Circle::getIcon()
{
    return 'C';
}

void Circle::update(int sw, int sh)
{
    vy+=gravity;
    x += vx;
    y += vy;
   if(x+r>sw){
        vx=-vx*0.9;
        x=sw-r;
    }
    if(x-r<0){
        vx=-vx*0.9;
        x=r;
    }
    if(y+r>sh){
        vy=-vy*0.9;
        y=sh-r;
    }
    if(y-r<0){
        vy=-vy*0.9;
        y=r;
    }
}
