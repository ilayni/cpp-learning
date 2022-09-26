
#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;

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

class CircleInfo : public Circle
{
	public:
	
	CircleInfo(float radius, string str): Circle(radius) 
	{
		Name = str;
	}
	string getName(){return Name;}
	private:
	string Name;
	
};

int main()
{
    Circle c = Circle(3.0);
	CircleInfo c1 = CircleInfo(3.0,"kuku");
    std::cout << c.getArea() << std::endl;
    std::cout << c.getPerimeter() << std::endl;
	std::cout << c1.getArea() << std::endl;
    std::cout << c1.getName() << std::endl;


}