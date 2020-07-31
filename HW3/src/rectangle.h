#ifndef RECTANGLE_H
#define RECTANGLE_H
#include<math.h>
#include "shape.h"

class Rectangle : public Shape
{
public:
  Rectangle(double l, double w):_l(l), _w(w){}

  double area() const
  {
    return _l*_w;
  }

  double perimeter() const
  {
    return (2*_l)+(2*_w);
  }

private:
  double _l, _w;
};
#endif