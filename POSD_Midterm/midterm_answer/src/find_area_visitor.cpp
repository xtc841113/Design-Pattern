#include "find_area_visitor.h"
#include "shape.h"
#include "complex_shapes.h"
#include <iostream>
#include <string>

FindAreaVisitor::FindAreaVisitor (double min, double max):_min(min),_max(max){}
void FindAreaVisitor::visit(Shape *s){
  found.clear();
}

void FindAreaVisitor::visit(ComplexShapes *c){
  found.clear();
  for(int i = 0; i<c->numberOfChild(); i++){
    deepVisit(c->getChild(i));
  }

}

void FindAreaVisitor::deepVisit(Shape *s){
  if(s->area()>= _min && s->area()<= _max)
    found.push_back(s);
  for(int i = 0 ; i< s->numberOfChild() ; i ++){
      deepVisit(s->getChild(i));
  }
}

std::vector<Shape*> FindAreaVisitor::findResult(){
  return found;
}
