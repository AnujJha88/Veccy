#ifndef LAYER_H
#define LAYER_H
#include <cstdint>
struct Color
{
  uint8_t r, g, b, a;
};

class BaseLayer
{
public:
  BaseLayer(double x, double y, double vx, double vy, Color c,double g) : x(x), y(y), vx(vx), vy(vy), color(c), gravity(g) {};
  virtual bool isInside(double x, double y) const = 0;
  virtual char getIcon() = 0;
  virtual ~BaseLayer() {};
  virtual void update(int sw, int sh)
  {
    // Standard bounce logic
    if (x > sw || x < 0)
      vx = -vx;
    if (y > sh || y < 0)
      vy = -vy;
    x += vx;
    y += vy;
  }
  double getX() const { return x; }
  double getY() const { return y; }
  double getVX() const { return vx; }
  double getVY() const { return vy; }
  Color getColor() const { return color; }

protected:
  double x, y, vx, vy;
  Color color;
  double gravity;
};

#endif
