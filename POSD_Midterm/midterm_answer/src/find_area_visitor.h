#ifndef FIND_AREA_VISITOR_H
#define FIND_AREA_VISITOR_H
#include <vector>
class Shape;
class ComplexShapes;

class FindAreaVisitor{
  public:
    FindAreaVisitor(double min, double max);
    void visit(ComplexShapes *c);
    void visit(Shape *s);
    void deepVisit(Shape *s);
    std::vector<Shape*> findResult();
    
  private:
    std::vector<Shape *> found;
    double _min;
    double _max;
};

#endif