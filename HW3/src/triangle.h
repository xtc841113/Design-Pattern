#ifndef TRIANGLE_H
#define TRIANGLE_H
#include <vector>
#include <math.h>
#include <iostream>
#include "shape.h"

typedef struct Coordinate
{
    double x;
    double y;

}vertex;

class Triangle : public Shape
{
public:
    Triangle(double x1, double y1, double x2, double y2, double x3, double y3):_x1(x1), _x2(x2), _x3(x3), _y1(y1), _y2(y2), _y3(y3){
        _v1.x = x1; _v1.y = y1;
        _v2.x = x2; _v2.y = y2;
        _v3.x = x3; _v3.y = y3;
        a = distanceOfVertexs(_v1, _v2);
        b = distanceOfVertexs(_v2, _v3);
        c = distanceOfVertexs(_v1, _v3);
        if(!isTriangle())
            throw std::string("Not a triangle.");
    }

    double distanceOfVertexs(const vertex vertex_1, const vertex vertex_2)
    {
        double diff_X, diff_Y, distance;
        diff_X = vertex_1.x - vertex_2.x;
        diff_Y = vertex_1.y - vertex_2.y;
        distance = sqrt(((diff_X * diff_X) + (diff_Y * diff_Y)));
        return distance;
    }

    bool isTriangle()
    {
        if((a+b)>c && (a+c)>b && (b+c)>a)
            return true;
        return false;
    }
    double area() const
    {
        double area;
        double s;
        s = (a + b + c)/(double)2;
        area = sqrt(s * (s-a) * (s-b) * (s-c));
        return area;
    }

    double perimeter() const
    {
        double sumOfLenghts;
        sumOfLenghts = a + b + c;
        return sumOfLenghts;
    }

private:
    double _x1, _x2, _x3, _y1, _y2, _y3;
    vertex _v1, _v2, _v3;
    double a,b,c;
};
#endif
