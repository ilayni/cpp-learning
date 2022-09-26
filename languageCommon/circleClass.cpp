
#include <iostream>
#include <stdio.h>

const float PI_F = 3.14f;

class Circle {
 public:
	Circle(float radius)
	{
		r = radius;
	}
	float getArea(){ return (3.14*r*r);}
	float getPerimeter(){ return 2*3.14*r;}
 private:
		float r;
};

int main()
{
    Circle c = Circle(3.0);
    std::cout << c.getArea() << std::endl;
    std::cout << c.getPerimeter() << std::endl;

}