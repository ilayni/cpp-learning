//#include <stdio>
#include <iostream>
#include <vector>
#include <list>
using namespace std;

// Move Class
class Move {
private:
    // Declare the raw pointer as
    // the data member of class
    int* data;
 
public:
   
    // Constructor
    Move(int d)
    {
        // Declare object in the heap
        data = new int;
        *data = d;
        cout << "Constructor is called for "
             << d << endl;
    };
 
    // Copy Constructor
    Move(const Move& source)
        : Move{ *source.data }
    {
 
        // Copying the data by making
        // deep copy
        cout << "Copy Constructor is called -"
             << "Deep copy for "
             << *source.data
             << endl;
    }
 
    // Move Constructor
    Move(Move&& source)
        : data{ source.data }
    {
 
        cout << "Move Constructor for "
             << *source.data << endl;
        source.data = nullptr;
    }
 
    // Destructor
    ~Move()
    {
        if (data != nullptr)
 
            // If pointer is not pointing
            // to nullptr
            cout << "Destructor is called for "
                 << *data << endl;
        else
 
            // If pointer is pointing
            // to nullptr
            cout << "Destructor is called"
                 << " for nullptr "
                 << endl;
 
        // Free up the memory assigned to
        // The data member of the object
        delete data;
    }
};

//without move constuctor
class B{
    int x;
    int *p;
    public:
    //A(){ cout<<"default ctr\n";}
    B(int a):x(a){p=new int();*p=a;cout<<"my ctr\n";}
    //copy contructor
    B(const B& srcC){
        x = srcC.x;
        cout<<"copy ctr\n";
        cout<<"ptr adr= "<<srcC.p<<endl;
        p = new int();
    
    }
    //assignment operagtor
    B operator=(const B &srcC)
    {
        x = srcC.x;
        p = new int();
        cout<<"assignemt optr\n";
        return *this;
    }
   
    
    
};


class A{
    int x;
    int *p;
    public:
    //A(){ cout<<"default ctr\n";}
    A(int a):x(a){p=new int();*p=a;x=2*a;cout<<"my ctr\n";}
    //copy contructor
    A(const A& srcC){
        x = srcC.x;
        cout<<"copy ctr\n";
        cout<<"ptr adr= "<<srcC.p<<endl;
        p = new int();
    
    }
    //assignment operagtor
    A& operator=(const A &srcC)
    {
        x = srcC.x;
        p = new int();
        cout<<"assignemt optr\n";
        return *this;
    }
    void setPVal(int num){
        if(p!=NULL)
        {
            //cout<<"setting p"<<endl;
             *p=num;
        }
    }
    void getPval(){cout<<*p;}
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
    A& operator=(A&& src)
    {
        //should we check this p  or src p for null ? 
        cout<<"move assignment"<<endl;
        cout<<"ptr adr= "<<src.p<<endl;
        cout<<"ptr val= "<<*src.p<<endl;
        cout<<"x val " << src.x << endl;
        this->p = src.p;
        src.p = NULL;
        return *this;
    }
    void dummyFunc(A src)
    {
        cout<<"dummy func  A " << &src <<" src ptr " << src.p << endl;
        src.x=100;//this will not change the class sent since a copy of it is being created
    }
    void dummyFuncRef(const A& src)
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

A RetByValue() {
    A obj(1);
    return obj; // Might call move ctor, or no ctor.
}

void TakeByValue(A);
//https://stackoverflow.com/questions/13125632/when-does-move-constructor-get-called/13125851
//https://www.geeksforgeeks.org/move-constructors-in-c-with-examples/
int main()
{
    vector<A> vec;
    vector<B> vec1;
    vector<Move> vec2;
 
    // Inserting Object of Move Class
    vec2.push_back(Move{ 10 });
    vec2.push_back(Move{ 20 });
    vec2.push_back(Move{ 30 });
  
    A a(10);
    B b(20);
    A c = move(a);//move ctr
    //TakeByValue(std::move(a)); // Might call move ctor, or no ctor.

    A d = RetByValue(); // Might call move ctor, or no ctor. - calls my ctr

    a = RetByValue(); // Calls move assignment, a::operator=(a&&) and copy ctr


    vec.push_back(A(30));//my ctr, move ctr
    vec.push_back(a);//even though move constrcutr is defined it will not be called here, copy ctr will be called twice
    vec.push_back(move(a));//move ctr, copy ctr
   
    vec1.push_back(B(40));//my ctr, copy ctr
    vec1.push_back(b);//copy ctr, copy ctr 
    //for(auto i:vec)
        //cout<<i.getPval()<<endl;
}