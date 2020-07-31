#include "complex_shapes.h"
#include "find_area_visitor.h"

ComplexShapes::ComplexShapes(std::vector<Shape*> *shapes):_shapes(shapes){}
double ComplexShapes::area()const{
      double sum=0;
      for(int i=0; i<_shapes->size();i++)
        sum += (*_shapes)[i]->area();
      return sum;
}
void ComplexShapes::add(Shape *s){
      _shapes->push_back(s);
}
double ComplexShapes::perimeter()const{
    double sum=0;
    for(int i=0; i<_shapes->size();i++)
    {
      sum+=(*_shapes)[i]->perimeter();
    }
    return sum;
  }
Shape * ComplexShapes::getChild(int index){
      return  (*_shapes)[index];
}
int ComplexShapes::numberOfChild(){
      return _shapes->size();
}
void ComplexShapes::accept(FindAreaVisitor *fv){
      fv->visit(this);
}
