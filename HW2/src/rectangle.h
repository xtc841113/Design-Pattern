#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "shape.h"
#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

string ooopss="Division by zero";
class Rectangle:public Shape{
public:
  Rectangle(double w,double h):_w(w),_h(h)
  {

  }

  double area() const{
    return _w*_h;
  }

  double perimeter() const{
    return _w*2+_h*2;
  }

  double compactness() const
  {
    if(area()!=0)
      return perimeter()*perimeter()/area();
    else
      throw ooopss;

  }

private:
  double _w,_h;
};

#endif
