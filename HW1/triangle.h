#include <math.h>

class Triangle{
public:
Triangle(double x1, double y1, double x2, double y2, double x3, double y3):_x1(x1),_y1(y1),_x2(x2),_y2(y2),_x3(x3),_y3(y3){

}
bool isTriangle(){
  double a = sqrt((_x1-_x2)*(_x1-_x2)+(_y1-_y2)*(_y1-_y2));
  double b = sqrt((_x2-_x3)*(_x2-_x3)+(_y2-_y3)*(_y2-_y3));
  double c = sqrt((_x3-_x1)*(_x3-_x1)+(_y3-_y1)*(_y3-_y1));

  double a1=_x1/_y1;
  double b1=_x2/_y2;
  double c1=_x3/_y3;

  if(a+b<c||a+c<b||b+c<a||a==0||b==0||c==0)
    return false;
  else
    return true;
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

private:
  double _x1,_y1,_x2,_y2,_x3,_y3;

};
