#ifndef UT_MIDTERM_H
#define UT_MIDTERM_H
#include "../src/shape.h"
#include "../src/ellipse.h"
#include "../src/rectangle.h"
#include "../src/circle.h"
#include "../src/complex_shapes.h"
#include "../src/find_area_visitor.h"
#include <vector>
#include <iostream>

TEST(Ellipse_Perimeter, )
{
    Shape *ell = new Ellipse(2,1.5);
    ASSERT_NEAR(11.1015,ell->perimeter(),0.01);
}
TEST(Ellipse_Area, )
{
    Shape *ell = new Ellipse(2,1.5);
    ASSERT_NEAR(9.419,ell->area(),0.01);
}

TEST(ComplexShapes_Perimeter, )
{
    Shape * circle = new Circle(1.2);
    Shape * rectangle = new Rectangle(2.7,4.4);
    Shape *ell = new Ellipse(2.5,1.5);
    std::vector<Shape *> shapes = {circle,rectangle};
    Shape * complexShapes = new ComplexShapes(&shapes);
    std::vector<Shape *> shapes2 = {complexShapes,ell};
    Shape * complexShapes2 = new ComplexShapes(&shapes2);
    ASSERT_NEAR(34.686,complexShapes2->perimeter(),0.01);
}

TEST(ComplexShapes_Area, )
{
    Shape * circle = new Circle(1.2);
    Shape * rectangle = new Rectangle(2.7,4.4);
    Shape *ell = new Ellipse(2.5,1.5);
    std::vector<Shape *> shapes = {circle,rectangle};
    Shape * complexShapes = new ComplexShapes(&shapes);
    std::vector<Shape *> shapes2 = {complexShapes,ell};
    Shape * complexShapes2 = new ComplexShapes(&shapes2);
    ASSERT_NEAR(28.178,complexShapes2->area(),0.01);
}


TEST(ComplexShapes_ChildOperation, )
{
    Shape * circle = new Circle(1);
    Shape * rectangle = new Rectangle(2,4);
    Shape * ell = new Ellipse(1,1);
    Shape * ell2 = new Ellipse(2.5,1.5);
    Shape * rectangle2 = new Rectangle(4.5,2.5);

    std::vector<Shape *> shapes = {};
    ComplexShapes * complexShapes = new ComplexShapes(&shapes);
    std::vector<Shape *> shapes2 = {ell2,rectangle2,complexShapes};
    ComplexShapes * complexShapes2 = new ComplexShapes(&shapes2);

    ASSERT_EQ(0,complexShapes->numberOfChild());
    complexShapes->add(circle);
    ASSERT_EQ(1,complexShapes->numberOfChild());
    complexShapes->add(rectangle);
    ASSERT_EQ(2,complexShapes->numberOfChild());
    complexShapes->add(ell);
    ASSERT_EQ(3,complexShapes->numberOfChild());

    ASSERT_NEAR(3.14,complexShapes->getChild(0)->area(),0.01);
    ASSERT_NEAR(6.28,complexShapes->getChild(0)->perimeter(),0.01);
    ASSERT_NEAR(8,complexShapes->getChild(1)->area(),0.001);
    ASSERT_NEAR(12,complexShapes->getChild(1)->perimeter(),0.001);
    ASSERT_NEAR(3.14,complexShapes->getChild(2)->area(),0.01);
    ASSERT_NEAR(6.28,complexShapes->getChild(2)->perimeter(),0.01);

    complexShapes2->add(ell2);
    ASSERT_EQ(4,complexShapes2->numberOfChild());
    ASSERT_NEAR(11.775,complexShapes2->getChild(3)->area(),001);
    ASSERT_NEAR(12.946,complexShapes2->getChild(3)->perimeter(),0001);

    ASSERT_EQ(3,complexShapes2->getChild(2)->numberOfChild());

    ASSERT_NEAR(3.14,complexShapes2->getChild(2)->getChild(0)->area(),0.01);
    ASSERT_NEAR(6.28,complexShapes2->getChild(2)->getChild(0)->perimeter(),0.01);

}

TEST(Visitor_FindAreaInLeaf, )
{
    Shape * circle = new Circle(1);
    Shape * rectangle = new Rectangle(2,4);
    Shape * ell = new Ellipse(1,1);
    std::vector<Shape *> shapes = {ell,rectangle};

    Shape * complexShapes = new ComplexShapes(&shapes);

    FindAreaVisitor *fv =new FindAreaVisitor(1,5);

    circle->accept(fv);
    ASSERT_EQ(0,fv->findResult().size());
    
    complexShapes->getChild(0)->accept(fv);
    ASSERT_EQ(0,fv->findResult().size());
    
    complexShapes->getChild(1)->accept(fv);
    ASSERT_EQ(0,fv->findResult().size());


}

TEST(Visitor_FindAreaInComposite, )
{
    Shape * circle = new Circle(1);
    Shape * rectangle = new Rectangle(2,4);
    Shape * ell = new Ellipse(1,1);
    std::vector<Shape *> shapes = {circle,rectangle,ell};
    ComplexShapes * complexShapes = new ComplexShapes(&shapes);
    std::vector<Shape *> shapes2 = {complexShapes};
    ComplexShapes * complexShapes2 = new ComplexShapes(&shapes2);

    FindAreaVisitor *fv =new FindAreaVisitor(1,5);
    complexShapes->accept(fv);
    ASSERT_EQ(2,fv->findResult().size());

}

TEST(Visitor_FindAreaInNestedComposite, )
{
    Shape * circle = new Circle(1);
    Shape * circle2 = new Circle(2);
    Shape * rectangle = new Rectangle(2,4);
    Shape * circle3 = new Circle(1.5);
    Shape * circle4 = new Circle(2.5);
    Shape * rectangle2 = new Rectangle(1,2);
    Shape * ell = new Ellipse(1,1);

    std::vector<Shape *> shapes = {circle,rectangle,circle2};
    ComplexShapes * complexShapes2 = new ComplexShapes(&shapes);
    std::vector<Shape *> shapes3 = {circle3,rectangle2,circle4};
    ComplexShapes * complexShapes3 = new ComplexShapes(&shapes3);

    std::vector<Shape *> shapes2 = {ell,complexShapes2};
    ComplexShapes * complexShapes = new ComplexShapes(&shapes2);


    FindAreaVisitor *fv= new FindAreaVisitor(5,24);
    FindAreaVisitor *fv2= new FindAreaVisitor(1,5);
    FindAreaVisitor *fv3= new FindAreaVisitor(7.065,19.635);

    complexShapes->accept(fv);
    ASSERT_EQ(3,fv->findResult().size());
    complexShapes->add(complexShapes3);
    complexShapes->accept(fv);
    ASSERT_EQ(5,fv->findResult().size());
    complexShapes->accept(fv3);
    ASSERT_EQ(4,fv3->findResult().size());

}

TEST(Visitor_InitialAcceptWhenFunctionCall,)
{
    Shape * circle = new Circle(1);
    Shape * circle2 = new Circle(2);
    Shape * rectangle = new Rectangle(2,4);
    Shape * ell = new Ellipse(1,1);

    std::vector<Shape *> shapes = {circle,rectangle,circle2};
    ComplexShapes * complexShapes = new ComplexShapes(&shapes);
    std::vector<Shape *> shapes2 = {ell};
    ComplexShapes * complexShapes2 = new ComplexShapes(&shapes2);

    FindAreaVisitor *fv= new FindAreaVisitor(4,15);

    complexShapes->accept(fv); // find 2
    complexShapes2->accept(fv); // find 0
    ASSERT_EQ(0,fv->findResult().size());
    complexShapes->accept(fv); // find 2
    ASSERT_EQ(2,fv->findResult().size());


}
TEST(Visitor_VisitDifferentComposite, )
{
    Shape * circle = new Circle(1);
    Shape * circle2 = new Circle(2);
    Shape * rectangle = new Rectangle(2,4);
    Shape * ell = new Ellipse(1,1);
    Shape * circle3 = new Circle(1.5);
    Shape * circle4 = new Circle(2.5);
    Shape * rectangle2 = new Rectangle(1,2);

    std::vector<Shape *> shapes = {circle,rectangle,circle2};
    ComplexShapes * complexShapes = new ComplexShapes(&shapes);
    std::vector<Shape *> shapes2 = {ell};
    ComplexShapes * complexShapes2 = new ComplexShapes(&shapes2);
    std::vector<Shape *> shapes3 = {circle3,circle4,rectangle2};
    ComplexShapes * complexShapes3 = new ComplexShapes(&shapes3);

    FindAreaVisitor *fv= new FindAreaVisitor(4,8);
    FindAreaVisitor *fv2= new FindAreaVisitor(1,4);
    FindAreaVisitor *fv3= new FindAreaVisitor(1,8);

    complexShapes->accept(fv);
    ASSERT_EQ(1,fv->findResult().size());
    complexShapes->accept(fv2);
    ASSERT_EQ(1,fv2->findResult().size());
    complexShapes->accept(fv3);
    ASSERT_EQ(2,fv3->findResult().size());

    complexShapes2->accept(fv);
    ASSERT_EQ(0,fv->findResult().size());
    complexShapes2->accept(fv2);
    ASSERT_EQ(1,fv2->findResult().size());
    complexShapes2->accept(fv3);
    ASSERT_EQ(1,fv3->findResult().size());

    complexShapes3->accept(fv);
    ASSERT_EQ(1,fv->findResult().size());
    complexShapes3->accept(fv2);
    ASSERT_EQ(1,fv2->findResult().size());
    complexShapes3->accept(fv3);
    ASSERT_EQ(2,fv3->findResult().size());

    complexShapes2->add(complexShapes);

    complexShapes2->accept(fv);
    ASSERT_EQ(1,fv->findResult().size());
    complexShapes2->accept(fv2);
    ASSERT_EQ(2,fv2->findResult().size());
    complexShapes2->accept(fv3);
    ASSERT_EQ(3,fv3->findResult().size());

    complexShapes2->add(complexShapes3);

    complexShapes2->accept(fv);
    ASSERT_EQ(2,fv->findResult().size());
    complexShapes2->accept(fv2);
    ASSERT_EQ(3,fv2->findResult().size());
    complexShapes2->accept(fv3);
    ASSERT_EQ(5,fv3->findResult().size());


}

#endif