#include <iostream>
#include <string>
using namespace std;

class Animal
{
    string m_name;
    int m_age;

    public:
    Animal(int age, string name)
    {
        m_age = age; m_name = name;
    }
    virtual void display()
    {
        cout<<"name " << m_name << " age " << m_age << endl;
    }

};

class Giraff : public Animal
{
    public:
    Giraff(int age, string name) : Animal(age, name){};
    void display()
    {
        Animal::display();
        cout << " G " << endl;
    }
};

class Zebra : public Animal
{
    int stripes;
    public:
    Zebra (int stripesN, int age, string name) : Animal(age, name) { stripes = stripesN;}
    void display()
    {
        Animal::display();
        cout << " stripes  " << stripes << endl;
    }
};

int main()
{
    Animal A(10,"yo");
    Zebra* Z = new Zebra(10, 20,"zz");
    Giraff g(30,"gg");

    A.display();
    Z->display();
    g.display();


    return 0;
}