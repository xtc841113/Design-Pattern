class Rectangle{
public:
  Rectangle(double w,double h):_w(w),_h(h)
  {

  }

  double area() const{
    return _w*_h;
  }

  double perimeter() const{
    return _w*2+_h*2;
  }

private:
  double _w,_h;
};
