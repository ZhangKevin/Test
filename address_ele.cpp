//#include<iostream.h>
#include "address_ele.h"
person::person()
{
    age=0;
    mobile="";
    address="";
    pNext=NULL;
}
void person::SetName(string str)
{
    name=str;
}
string person::GetName(void)
{
    return name;
}
void person::SetAge(int newVal)
{
    age=newVal;
}
int person::GetAge(void)
{
    return age;
}
void person::SetMobile(string str)
{
    mobile=str;
}
string person::GetMobile(void)
{
    return mobile;
}
void person::SetAddress(string str)
{
    address=str;
}
string person::GetAddress(void)
{
    return address;
}
