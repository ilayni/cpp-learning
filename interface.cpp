#include <iostream>
using namespace std;

class Animal{
    public:
    virtual void Noise() = 0;  
    virtual void move(int x) = 0;  
};

class SuperHero{
    public:
    virtual void save() = 0;
    virtual void move(int x) = 0;  
};

class superMan : public SuperHero
{
    int x = 0;
    public:
    void save() { cout<< "i will save u\n";}
    void move(int pos) { x+= pos; cout<<x<<endl;}
};

class Amoeba : public SuperHero, public Animal
{
    int x = 0;
    public:
    void Noise() { cout<< "brrr\n";}
    void save() { cout<< "i will save u\n";}
    void move(int pos) { x+= pos; cout<<x<<endl;}
};

int main()
{
    Amoeba A;
    superMan S;
    A.save();
    A.Noise();
    A.move(10);
    S.save();
    S.move(20);
}