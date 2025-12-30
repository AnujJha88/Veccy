#include "Rectangle.h"

bool Rectangle::isInside(double px, double py) const
{
    return (px >= x && px <= x + w && py >= y && py <= y + h);
}

char Rectangle::getIcon()
{
    return 'R';
}

void Rectangle::update(int sw, int sh)
{
    vy+=gravity;
    x += vx;
    y += vy;
    if(x+w>sw){
        vx=-vx*0.9;
        x=sw-w;
    }
    if(x<0){
        vx=-vx*0.9;
        x=0;
    }
    if(y+h>sh){
        vy=-vy*0.9;
        y=sh-h;
    }
    if(y<0){
        vy=-vy*0.9;
        y=0;
    }
}
