//#include <stdio>
#include <iostream>
#include <vector>
#include <list>
using namespace std;


class A{
    int x;
    int *p;
    public:
    //A(){ cout<<"default ctr\n";}
    A(int a):x(a){p=new int();*p=a;x=2*a;}
    //copy contructor
    A(const A& srcC){
        x = srcC.x;
        cout<<"copy ctr\n";
        cout<<"ptr adr= "<<srcC.p<<endl;
        p = new int();
    
    }
    //assignment operagtor
    A operator=(const A &srcC)
    {
        x = srcC.x;
        p = new int();
        cout<<"assignemt optr\n";
        return *this;
    }
    setPVal(int num){
        if(p!=NULL)
        {
            //cout<<"setting p"<<endl;
             *p=num;
        }
    }
    getPval(){cout<<*p;}
    //move construcotr 
    A(A&& src)
    {
        //should we check this p  or src p for null ? 
        cout<<"move constructor"<<endl;
        cout<<"ptr adr= "<<src.p<<endl;
        cout<<"ptr val= "<<*src.p<<endl;
        cout<<"x val " << src.x << endl;
        this->p = src.p;
        src.p = NULL;
    }
    dummyFunc(A src)
    {
        cout<<"dummy func  A " << &src <<" src ptr " << src.p << endl;
        src.x=100;//this will not change the class sent since a copy of it is being created
    }
    dummyFuncRef(const A& src)
    {
         cout<<"dummy func  A " << &src <<" src ptr " << src.p << endl;
         //src.x=100;// will not work with const
    }
    
    
};

void listRef(list<int>& src)
{
    for(auto i:src)
        cout<< i << endl;
}

int main()
{
    vector<A> vec;
    list<int> lst;
    lst.push_back(10);lst.push_back(20);
    listRef(lst);

    A a(10);
    A b = a;
    a.dummyFunc(b);
    a.dummyFuncRef(b);
    A c(10);
    A d = A(60);
    c = move(d);//a;
    a.setPVal(20);
    b.setPVal(30);
    vec.push_back(A(10));
    for(auto i:vec)
        cout<<i.getPval()<<endl;
}