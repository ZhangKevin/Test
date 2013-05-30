#include "address_ele.h"
#include <fstream>
void Add(person* p);
void Cat(person* p,string str);
void Ls(person* p);
person* Remove(person* p, string str);
void Help(void);
void Save_to_file(person* p);
person* Load_file(person* p);
int main()
{
        string cmd;
        string str;
        person* p=NULL;
        p=Load_file(p);
	while(1)
	{
             cout<<"ab> ";
             cin>>cmd;
             if(cmd=="ls")
                  Ls(p);
             else if(cmd=="cd")
                  cout<<"cd"<<endl;
             else if(cmd=="cat")
             {
                  cout<<"input the name:";
                  cin>>str;
                  Cat(p,str);
             }
             else if(cmd=="add")
             {
                  Add(p);
             }
             else if(cmd=="remove")
             {
                  cout<<"please give the key:";
                  cin>>str;
                  p=Remove(p,str);
             }
             else if(cmd=="!help")
                  Help();
             else if(cmd=="!quit")
             {
                  Save_to_file(p);
                  break;
             }
             else
             {
                  cout<<"Not an avaliable command!"<<endl;
                  Help();
             }
	}
	return 0;
}
void Ls(person* p)
{
      person* ptmp=p;
      while(ptmp!=NULL)
      {
           cout<<ptmp->GetName()<<" ";
           ptmp=ptmp->pNext;
      }
      cout<<endl;
}
void Add(person* p)
{
      string name;
      int age;
      string mobile;
      string address;
      person* ptmp;
      //person* pnew;
      //pnew=new person;

      cout<<"Key:";
      cin>>name;
      ptmp=p;
      while(ptmp!=NULL)
      {
           if(ptmp->GetName()==name)
           {
                 cout<<"The name "<<name<<" already exist!!"<<endl;
                 return ;
           }
           ptmp=ptmp->pNext;
      }
      cout<<"Age:";
      cin>>age;
      cout<<"Mobile:";
      cin>>mobile;
      cout<<"Address:";
      cin>>address;
 
      if(p==NULL)
      {
           p->SetName(name);
           p->SetAge(age);
           p->SetMobile(mobile);
           p->SetAddress(address);
           p->pNext=NULL;
      }
      else
      {
           person* pnew=new person();
           ptmp=p;
           while(ptmp->pNext!=NULL)
                 ptmp=ptmp->pNext;
           pnew->SetName(name);
           pnew->SetAge(age);
           pnew->SetMobile(mobile);
           pnew->SetAddress(address);
           pnew->pNext=NULL;
           ptmp->pNext=pnew;
      }
      cout<<"address entry added!"<<endl;
}
void Cat(person* p,string str)
{
      person* ptmp=p;
      while(ptmp!=NULL)
      {
            if(ptmp->GetName()==str)
            {
                 cout<<"Name:"<<ptmp->GetName()<<endl;
                 cout<<"Age:"<<ptmp->GetAge()<<endl;
                 cout<<"Mobile:"<<ptmp->GetMobile()<<endl;
                 cout<<"Address:"<<ptmp->GetAddress()<<endl;
                 return;
            }
            else
                 ptmp=ptmp->pNext;
      }
      cout<<"No "<<str<<" in records!!"<<endl;
}
person* Remove(person* p,string str)
{
       person* ptmp1=NULL;
       person* ptmp2=NULL;
       if(p->GetName()==str)
       {
              ptmp1=p;
              p=p->pNext;
              delete(ptmp1);
              cout<<str<<" was deleted!!"<<endl;
              return p;
       }
       ptmp1=ptmp2=p;
       while(ptmp1->pNext!=NULL)
       {
              if(ptmp1->pNext->GetName()==str)
              {
                    ptmp2=ptmp1->pNext;
                    ptmp1->pNext=ptmp2->pNext;
                    delete(ptmp2);
                    cout<<str<<" was deleted!!"<<endl;
                    return p;
              }
              ptmp1=ptmp2=ptmp1->pNext;
       }
       cout<<"No "<<str<<" in records!!"<<endl;
       return p;
}
void Help(void)
{
      cout<<"'ls' to list the items in current position"<<endl;
      cout<<"'cd' to go to the entry"<<endl;
      cout<<"'cat' to display the item data"<<endl;
      cout<<"'add' to add new item entry to JSON"<<endl;
      cout<<"'remove' to delete an item"<<endl;
      cout<<"'!help' get help"<<endl;
      cout<<"'!quit' quit from the application"<<endl;
}
void Save_to_file(person* p)
{
      ofstream outfile;
      outfile.open("AddressBook.dat",ios::out);
      if(!outfile)
      {
           cerr<<"open error!"<<endl;
        //   exit(0);
      }
      person* ptmp=p;
      while(ptmp!=NULL)
      {
           outfile<<"Name "<<ptmp->GetName()<<" Age "<<ptmp->GetAge()<<" Mobile "<<ptmp->GetMobile()<<" Address "<<ptmp->GetAddress()<<endl;
           ptmp=ptmp->pNext;
      }
     outfile.close();
}
person* Load_file(person* p)
{
     ifstream infile;
     infile.open("AddressBook.dat",ios::in);
     if(!infile)
     {
          //cerr<<"open error!"<<endl;
          cout<<"No record!"<<endl;
          return p;
     }
     string key;        //the key like: name,age,mobile and address
     string name;
     int age;
     string mobile;
     string address;
     
     while(1)
     {
          for(int i=0;i<4;i++)
          {
          infile>>key;
          if(infile.eof())
             return p;
          if(key=="Name")
               infile>>name;
          else if(key=="Age")
               infile>>key;
          else if(key=="Mobile")
               infile>>mobile;
          else if(key=="Address")
               infile>>address;
          else
              ;
          }
          person* pnew=new person();
          pnew->SetName(name);
          pnew->SetAge(age);
          pnew->SetMobile(mobile);
          pnew->SetAddress(address);
          pnew->pNext=p;
          p=pnew;
     }
     infile.close();
     return p;
     
}
