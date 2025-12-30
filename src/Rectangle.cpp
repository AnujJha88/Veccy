#include "Rectangle.h"

bool Rectangle::isInside(double px, double py) const{
    return(px>=x && px<=x+w&& py>=y && py<=y+h);
}

char Rectangle::getIcon(){
    return 'R';
}

void Rectangle::update(int sw, int sh){
    if(x+w>sw || x<0)vx=-vx;
    if(y+h>sh || y<0)vy=-vy;
    x+=vx;
    y+=vy;
}