#ifndef ELLIPSE_H
#define ELLIPSE_H
#include "shape.h"
#include <cmath>

class Ellipse:public Shape{
  public:
    Ellipse(double a ,double b):_a(a),_b(b){}
    double area() const{
      return _a*_b*M_PI;
    }
    double perimeter() const{
      return 2*M_PI*sqrt((_a*_a+_b*_b)/2);
    }

  private:
    double _a;
    double _b;

};

#endif