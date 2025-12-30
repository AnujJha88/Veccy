#include "Layer.h"
#include<cmath>

class Circle: public BaseLayer{
private:
    double x,y;
    double r;
public:
    Circle(double x, double y, double r):x(x),y(y),r(r){}
    bool isInside(double x, double y)const;
    char getIcon();
    void setX(double newX){x=newX;}
    void setY(double newY){y=newY;}
    void setR(double newR){r=newR;}
    double getX(){return x;}
    double getY(){return y;}
    double getR(){return r;}
};
