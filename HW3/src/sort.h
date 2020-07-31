#ifndef SORT_H
#define SORT_H
#include <math.h>
#include <vector>
#include <iostream>
#include <algorithm>
#include "shape.h"

class Sort
{

    public:
    Sort(std::vector<Shape*>* v): _v(v){}
    ~Sort(){ delete _v; }

    template <class sortAreaComparison>
    void sortArea(sortAreaComparison comp)
    {
        std::sort(_v->begin(), _v->end(), comp);
    }

    template <class sortPerimeterComparison>
    void sortPerimeter(sortPerimeterComparison comp)
    {
        std::sort(_v->begin(), _v->end(), comp);
    }

    // template <class sortCompactnessComparison>
    // void sortCompactness(sortCompactnessComparison comp)
    // {
    //     std::sort(_v->begin(), _v->end(), comp);
    // }

    private:
        std::vector<Shape*>* _v;
};

bool perimeterAscendingComparison(Shape* a, Shape* b)
{
    return a->perimeter() < b->perimeter();
}

bool perimeterDescendingComparison(Shape* a, Shape* b)
{
    return a->perimeter() > b->perimeter();
}


bool areaAscendingComparison(Shape* a, Shape* b)
{
    return a->area() < b->area();
}

bool areaDescendingComparison(Shape* a, Shape* b)
{
    return a->area() > b->area();
}


// class CompactnessAscendingComparison
// {
//     public:
//     bool operator() (Shape *a, Shape *b)
//     {
//         return a->compactness() < b->compactness() ;
//     }
// };
//
// class CompactnessDescendingComparison
// {
//     public:
//     bool operator() (Shape *a, Shape *b)
//     {
//         return a->compactness() >  b->compactness() ;
//     }
// };

#endif
