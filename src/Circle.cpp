#include "Circle.h"

bool Circle::isInside(double x, double y)const{
    return std::pow(x-this->x,2)+std::pow(y-this->y,2) < std::pow(this->r,2);
}

char Circle::getIcon(){
    return 'C';
}
