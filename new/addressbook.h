#include "contact.h"
#include <map>
class AddressBook
{
private:
     map<string,Contact> entries;
public:           
     map<string,Contact> GetEntries() {return entries;}
     void SetEntries(map<string,Contact> entr){entries=entr;}
};
