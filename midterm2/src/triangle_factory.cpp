#include "triangle_factory.h"
#include "triangle.h"
#include <string>
#include <iostream>
// TriangleFactory::TriangleFactory(){}

Triangle * TriangleFactory::create(int a, int b, int c){
  // if(_a>0 && _b>0 && _c>0 && _a+_b>_c && _b+_c>_a && _a+_c>_b){
  if(a>0 && b>0 && c>0 && a+b>c && b+c>a && a+c>b){

    std::cout << std::string("yyyy")<<std::endl;
    //_t = new Triangle(a,b,c);
    return new Triangle(a,b,c);;
  }
  else{
    std::cout << std::string("nnnn")<<std::endl;
    return nullptr;
  }

}
