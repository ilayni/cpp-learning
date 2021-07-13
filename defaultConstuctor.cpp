//#include <stdio>
#include <iostream>
using namespace std;


class A{
    int x;
    int *p;
    public:
    A(){}
    A(int a):x(a){p=new int();}
    //copy contructor
    A(const A& srcC){
        x = srcC.x;
        p = new int();
    cout<<"copy ctr\n";
    }
    //assignment operagtor
    A& operator=(const A &srcC)
    {
        x = srcC.x;
        p = new int();
        cout<<"assignemt optr\n";
        return *this;
    }
    setPVal(int x){if(p!=NULL) *p=x;}
};


int main()
{
    cout<<"hello world\n";
    A a(10);
    A b = a;
    A c;
    c = a;
    a.setPVal(20);
    b.setPVal(30);
}