#include <gtest/gtest.h>
#include "../src/circle.h"
#include "../src/rectangle.h"
#include "../src/triangle.h"
#include "../src/shape.h"
#include "../src/sort.h"
#include <algorithm>
#include <iostream>

using namespace std;

TEST (ShapeTest, first)
{
  ASSERT_TRUE(true);
}

TEST (ShapeTest, Circle)
{
  Circle c(10.0);
  ASSERT_NEAR(314.159, c.area(), 0.001);
  ASSERT_NEAR(62.831, c.perimeter(), 0.001);
}

TEST (ShapeTest, Rectangle)
{
  Rectangle r(3, 4);
  ASSERT_NEAR(12, r.area(), 0.001);
  ASSERT_NEAR(14, r.perimeter(), 0.001);
}

TEST (triangle, isTriangle)
{
  Triangle t(0.0,0.0,0.0,0.0,0.0,0.0);
  try{
    ASSERT_NEAR(0, t.isTriangle(), 0.001);
  }catch(std::exception& ex){
    ASSERT_STREQ("Not a triangle",ex.what());
  }

}
