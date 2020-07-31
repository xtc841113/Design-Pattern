#include <gtest/gtest.h>
#include "../src/circle.h"
#include "../src/rectangle.h"
#include "../src/triangle.h"
#include "../src/shape.h"
#include "../src/sort.h"
#include <algorithm>
#include <iostream>

using namespace std;

TEST(ShapeTest, Sorting)
{
  Shape* test_array[4] = {new Circle(1.0), new Circle(0.5), new Rectangle(5, 6), new Rectangle(0.5, 1.5)};

  std::sort(test_array, test_array+4, [](Shape * a, Shape *b) {
    return a->area() < b->area();
  });
  ASSERT_NEAR(0.75, test_array[0]->area(), 0.001);
  ASSERT_NEAR(0.25*3.1415, test_array[1]->area(), 0.001);
  ASSERT_NEAR(3.1415, test_array[2]->area(), 0.001);
  ASSERT_NEAR(30, test_array[3]->area(), 0.001);
}

TEST(ShapeTest, Sort_1)
{
  std::vector<Shape*>* ivector = new vector<Shape*>;
  ivector->push_back(new Circle(1.0));
  ivector->push_back(new Circle(0.5));
  ivector->push_back(new Rectangle(5, 6));
  ivector->push_back(new Triangle(0.0, 0.0,0.0, 0.0,0.0, 0.0));
  Sort s(ivector);
  s.sortArea( [](Shape* a,Shape* b) {return a->area()>b->area();} );
  std::cout<<(*ivector)[0]->area()<<endl;
  std::cout<<(*ivector)[1]->area()<<endl;
  std::cout<<(*ivector)[2]->area()<<endl;
  std::cout<<(*ivector)[3]->area()<<endl;
  ASSERT_NEAR(30, (*ivector)[0]->area(), 0.001);
  ASSERT_NEAR(3.14159, (*ivector)[1]->area(), 0.001);
  ASSERT_NEAR(0.785398, (*ivector)[2]->area(), 0.001);
  ASSERT_NEAR(.75, (*ivector)[3]->area(), 0.001);
}

TEST(ShapeTest, Sort_2)
{
  std::vector<Shape*>* ivector = new vector<Shape*>;
  ivector->push_back(new Circle(1.0));
  ivector->push_back(new Circle(0.5));
  ivector->push_back(new Rectangle(5, 6));
  ivector->push_back(new Rectangle(0.5, 1.5));
  Sort s(ivector);
  s.sortPerimeter(perimeterAscendingComparison);
  std::cout<<(*ivector)[0]->perimeter()<<endl;
  std::cout<<(*ivector)[1]->perimeter()<<endl;
  std::cout<<(*ivector)[2]->perimeter()<<endl;
  std::cout<<(*ivector)[3]->perimeter()<<endl;
  ASSERT_NEAR(3.14159, (*ivector)[0]->perimeter(), 0.001);
  ASSERT_NEAR(4, (*ivector)[1]->perimeter(), 0.001);
  ASSERT_NEAR(6.28319, (*ivector)[2]->perimeter(), 0.001);
  ASSERT_NEAR(22, (*ivector)[3]->perimeter(), 0.001);
}

TEST(ShapeTest, Sort_3)
{
  std::vector<Shape*>* ivector = new vector<Shape*>;
  ivector->push_back(new Circle(0.0));
  ivector->push_back(new Circle(0.5));
  ivector->push_back(new Rectangle(5, 6));
  ivector->push_back(new Rectangle(0.5, 1.5));
  Sort s(ivector);
  s.sortCompactness(CompactnessAscendingComparison());
  std::cout<<(*ivector)[0]->compactness()<<endl;
  std::cout<<(*ivector)[1]->compactness()<<endl;
  std::cout<<(*ivector)[2]->compactness()<<endl;
  std::cout<<(*ivector)[3]->compactness()<<endl;
  ASSERT_NEAR(12.5664, (*ivector)[0]->compactness(), 0.001);
  ASSERT_NEAR(12.5664, (*ivector)[1]->compactness(), 0.001);
  ASSERT_NEAR(16.1333, (*ivector)[2]->compactness(), 0.001);
  ASSERT_NEAR(21.3333, (*ivector)[3]->compactness(), 0.001);
}
