#include <iostream>
using namespace std;
class Student
{
public:
    string sName;
    int sAge;
    int sDob;
    Student(string name, int age, int dob)
    {
        this->sName = name;
        this->sAge = age;
        this->sDob = dob;
    }
};
int main()
{
    
    Student s1("Tarun", 22, 2002);
       cout<<s1.sName<<endl;
    cout<<s1.sAge<<endl;
    cout<<s1.sDob<<endl;

  
     Student s2("Tarun", 22, 2002);
        cout<<s2.sName<<endl;
    cout<<s2.sAge<<endl;
    cout<<s2.sDob<<endl;

    
     Student s3("Tarun", 22, 2002);
        cout<<s3.sName<<endl;
    cout<<s3.sAge<<endl;
    cout<<s3.sDob<<endl;

     
    cout<<s1.sName<<endl;
    cout<<s1.sAge<<endl;
    cout<<s1.sDob<<endl;



    return 0;
}