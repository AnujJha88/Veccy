#ifndef LAYER_H
#define LAYER_H

class BaseLayer{
public:
  virtual bool isInside(double x, double y) const=0;
    virtual char getIcon()=0;
    virtual ~BaseLayer(){};
};

#endif
