#ifndef SORT_H
#define SORT_H
#include "shape.h"
#include <math.h>
#include <algorithm>
#include <vector>
#include <iostream>
#include <functional>

class Sort{
    public:
      Sort(std::vector<Shape*>* v): _v(v){}

      void sortArea(std::function<bool(Shape*,Shape*)> compare){
        std::sort(_v->begin(),_v->end(),compare);
      }

      void sortPerimeter(std::function<bool(Shape*,Shape*)> compare){
        std::sort(_v->begin(),_v->end(),compare);
      }

      void sortCompactness(std::function<bool(Shape*,Shape*)> compare){
        std::sort(_v->begin(),_v->end(),compare);
      }

    private:
      std::vector<Shape*>* _v;
};

bool perimeterAscendingComparison(Shape* a, Shape *b){
  return a->perimeter() < b->perimeter();
}

bool perimeterDescendingComparison(Shape* a, Shape *b){
  return a->perimeter() > b->perimeter();
}


//You should use those objects as parameter for Sort::sortCompactness()


class CompactnessAscendingComparison{
public:
  bool operator()(Shape* a,Shape* b) const{
      return a->compactness() < b->compactness();
  }
};

class CompactnessDescendingComparison{
public:
  bool operator()(Shape* a,Shape* b) const{
      return a->compactness() > b->compactness();
  }
};

#endif
