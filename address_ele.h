#include<iostream>
#include<string>
using namespace std;
class person
{
public:
     person(void);
    // person(int newVal,string str1,string str2);

     void SetName(string str);
     string GetName(void);

     void SetAge(int newVal);
     int GetAge(void);

     void SetMobile(string str);
     string GetMobile(void);

     void SetAddress(string str);
     string GetAddress(void);
private:
    string name;
    int age;
    string mobile;
    string address;
public:
    person* pNext;
};
