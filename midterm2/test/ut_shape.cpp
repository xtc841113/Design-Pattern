#include <gtest/gtest.h>
#include "../src/triangle.h"
#include "../src/triangle_factory.h"
#include <string>

int main(int argc, char ** argv)
{
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

TEST (Triangle, NormalTriangle)
{
  Triangle t(3,4,5);
  ASSERT_NEAR(6.0,t.area(),0.001);
}

TEST (Triangle, IllegalTriangle)
{
  ASSERT_ANY_THROW(new Triangle(0,1,2));
}

// TEST (TriangleFactory, NormalTriangle)
// {
//   TriangleFactory * ft = new TriangleFactory(3,4,5);
//   ASSERT_EQ(ft, ft->create(3,4,5));
// }
//
// TEST (TriangleFactory, IllegalTriangle)
// {
//   TriangleFactory * f = new TriangleFactory(0,1,2);
//   ASSERT_EQ(nullptr, f->create(0,1,2));
// }
