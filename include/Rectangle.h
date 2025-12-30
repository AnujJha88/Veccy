#include "Layer.h"
class Rectangle : public BaseLayer
{
private:
    double w, h;

public:
    Rectangle(double x, double y, double vx, double vy, double w, double h, Color c,double g) : BaseLayer(x, y, vx, vy, c,g ), w(w), h(h) {}
    bool isInside(double px, double py) const override;
    char getIcon() override;

    double getW() const { return w; }
    double getH() const { return h; }

    double setW(double newW)
    {
        w = newW;
        return w;
    }
    double setH(double newH)
    {
        h = newH;
        return h;
    }

    void update(int sw, int sh) override;
};