#include "shape.h"
#include "find_area_visitor.h"
#include <string>

void Shape::accept(FindAreaVisitor *fv){
    fv->visit(this);
}
int Shape::numberOfChild(){
    return 0;
}
Shape * Shape::getChild(int index){
    throw std::string("Leaf does not contain any child");
}