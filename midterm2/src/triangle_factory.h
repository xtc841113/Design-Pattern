#ifndef TRIANGLE_FACTORY_H
#define TRIANGLE_FACTORY_H
#include "triangle.h"
#include <string>
#include <iostream>

class TriangleFactory : public Triangle{

public:
  TriangleFactory(int a, int b, int c):Triangle(a,b,c){
      //std::cout << std::string("yyyy")<<std::endl;
  }

  Triangle * create(int a, int b, int c);

private:
  Triangle * _t;
  int _a, _b, _c;
};

#endif
