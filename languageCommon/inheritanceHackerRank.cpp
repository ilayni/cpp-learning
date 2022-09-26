#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
#include <string>


class Person
{
   string name;
   int age; 
   public:
   virtual void getdata(){ cin >> name >> age;};
   virtual void putdata(){ cout << name << " " << age << " ";};
};
class Professor : public Person
{
  int publications;
  static int gencur_id;
  int cur_id;
  public:
  Professor(){
      //cout << "professor cur id" << cur_id << endl; 
      gencur_id++;
      cur_id = gencur_id;};  
  void getdata(){ Person::getdata(); cin >> publications;}
  void putdata(){ Person::putdata(); cout << publications << " " << cur_id << endl;}
};
class Student : public Person{
    static const int numMarks = 6;
    int marks[numMarks];
    static int gencur_id;
    int cur_id;
    int sum;
    public:
    Student(){\
          //cout << "student cur id" << cur_id << endl; 
 
        gencur_id++;
        cur_id = gencur_id;}
    void getdata(  ) { Person::getdata() ; for(int i=0;i<numMarks;i++) { cin >> marks[i];} ; sum =0;}
    void putdata() {  Person::putdata(); for(int i=0;i<numMarks;i++) { sum +=  marks[i]; } cout << sum << " " << cur_id << endl;}
};
int Professor::gencur_id = 0;
int Student::gencur_id = 0;

int main(){

    int n, val;
    cin>>n; //The number of objects that is going to be created.
    Person *per[n];

    for(int i = 0;i < n;i++){

        cin>>val;
        if(val == 1){
            // If val is 1 current object is of type Professor
            per[i] = new Professor;

        }
        else per[i] = new Student; // Else the current object is of type Student

        per[i]->getdata(); // Get the data from the user.

    }

    for(int i=0;i<n;i++)
        per[i]->putdata(); // Print the required output for each object.

    return 0;

}
