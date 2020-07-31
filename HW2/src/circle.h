#ifndef CIRCLE_H
#define CIRCLE_H
#include "shape.h"
#include <math.h>
#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

string ooppss="Division by zero";
class Circle:public Shape{
public:
  Circle(double r):_r(r)
  {

  }

  double area() const
  {
    return M_PI * _r * _r;
  }

  double perimeter() const
  {
    return 2 * M_PI * _r;
  }

  double compactness() const
  {
    if(area()!=0)
      return perimeter()*perimeter()/area();
    else
        throw ooppss;

  }
private:
  double _r;
};

#endif
