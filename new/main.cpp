#include "addressbook.h"
int main()
{
    AddressBook addr;
    Contact con;
    con.SetAge(18);
    con.SetMobile("188");
    con.SetAddress("SH");
    map<string,Contact> ent,ent1;
    ent["Zhang"]=con;
    ent["Li"]=con;
    addr.SetEntries(ent);
    //cout<<addr.GetEntries()<<endl;
    ent1=addr.GetEntries();
    cout<<ent1["Zhang"].GetAge()<<endl;
    cout<<ent1["Zhang"].GetMobile()<<endl;
    cout<<ent1["Zhang"].GetAddress()<<endl;
  
    cout<<ent1["Li"].GetAge()<<endl;
    cout<<ent1["Li"].GetMobile()<<endl;
    cout<<ent1["Li"].GetAddress()<<endl;
    return 0;
}
