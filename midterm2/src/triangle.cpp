#include "triangle.h"
#include <string>
#include <iostream>
#include <math.h>

Triangle::Triangle(int a, int b, int c):_a(a),_b(b),_c(c){

  if(_a>0 && _b>0 && _c>0 && _a+_b>_c && _b+_c>_a && _a+_c>_b){
      std::cout << std::string("0")<<std::endl;
      //throw std::string("Normal triangle");
  }

  else{
    std::cout << std::string("1")<<std::endl;
    throw std::string("illegal triangle");
  }




}

double Triangle::area() const{
  double s = (_a+_b+_c)/2;
  return sqrt(s*(s-_a)*(s-_b)*(s-_c));
}
