#ifndef TRIANGLE_H
#define TRIANGLE_H
#include <string>
#include <iostream>

class Triangle{
public:
  Triangle(int a, int b, int c);
  double area() const;


private:
  //Triangle * _t;
  int _a, _b, _c;
};



#endif
