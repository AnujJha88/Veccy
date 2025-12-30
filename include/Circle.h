#include "Layer.h"
#include<cmath>

class Circle: public BaseLayer{
private:
    double r;
public:
    Circle(double x, double y, double r,Color c):BaseLayer(x,y,5.0,5.0,c),r(r){}
    bool isInside(double x, double y)const override;
    char getIcon()override;

    void setR(double newR){r=newR;}

    double getR(){return r;}

    void update(int sw,int sh)override ;
};
