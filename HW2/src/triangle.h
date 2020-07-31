#ifndef TRIANGLE_H
#define TRIANGLE_H
#include "shape.h"
#include <math.h>
#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

string oopsss="Division by zero";
string oopss = "Not a triangle.";
class Triangle:public Shape{
public:
Triangle(double x1, double y1, double x2, double y2, double x3, double y3):_x1(x1),_y1(y1),_x2(x2),_y2(y2),_x3(x3),_y3(y3){
isTriangle();
}
bool isTriangle(){
  double a = sqrt((_x1-_x2)*(_x1-_x2)+(_y1-_y2)*(_y1-_y2));
  double b = sqrt((_x2-_x3)*(_x2-_x3)+(_y2-_y3)*(_y2-_y3));
  double c = sqrt((_x3-_x1)*(_x3-_x1)+(_y3-_y1)*(_y3-_y1));

  double a1=_x1/_y1;
  double b1=_x2/_y2;
  double c1=_x3/_y3;

  if(a+b<c||a+c<b||b+c<a||a==0||b==0||c==0){
    throw oopss;
    return false;}
  else{
      return true;}
}

double area() const{
  double a = sqrt((_x1-_x2)*(_x1-_x2)+(_y1-_y2)*(_y1-_y2));
  double b = sqrt((_x2-_x3)*(_x2-_x3)+(_y2-_y3)*(_y2-_y3));
  double c = sqrt((_x3-_x1)*(_x3-_x1)+(_y3-_y1)*(_y3-_y1));
  double s = (a+b+c)/2;
  return sqrt(s*(s-a)*(s-b)*(s-c));
}

double perimeter() const{
  double a = sqrt((_x1-_x2)*(_x1-_x2)+(_y1-_y2)*(_y1-_y2));
  double b = sqrt((_x2-_x3)*(_x2-_x3)+(_y2-_y3)*(_y2-_y3));
  double c = sqrt((_x3-_x1)*(_x3-_x1)+(_y3-_y1)*(_y3-_y1));
  double s = (a+b+c)/2;
  return 2*s;
}

double compactness() const
{
  if(area()!=0)
    return perimeter()*perimeter()/area();
  else
    throw oopsss;

}

private:
  double _x1,_y1,_x2,_y2,_x3,_y3;

};

#endif
