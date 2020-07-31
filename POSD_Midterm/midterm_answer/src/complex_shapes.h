#ifndef COMPLEX_SHAPES_H
#define COMPLEX_SHAPES_H
#include <vector>
#include "shape.h"

class FindAreaVisitor;

class ComplexShapes:public Shape{
  public:
    ComplexShapes(std::vector<Shape*> *shapes);
    double area()const;
    void add(Shape *s);
    double perimeter() const;
    Shape * getChild(int index);
    int numberOfChild();

    void accept(FindAreaVisitor *);

  private:
    std::vector<Shape*> *_shapes;
};
#endif