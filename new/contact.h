#include <iostream>
#include <string>
using namespace std;
class Contact
{
private:
     int age;
     string mobile;
     string address;
public:
     int GetAge() {return age;}
     void SetAge(int a){age=a;}
     string GetMobile() {return mobile;}
     void SetMobile(string m) {mobile=m;}
     string GetAddress() {return address;}
     void SetAddress(string addr) {address=addr;}
};
