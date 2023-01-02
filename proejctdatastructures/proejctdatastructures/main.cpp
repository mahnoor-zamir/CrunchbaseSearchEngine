#include <iostream>
#include <fstream>

#include <string>
#include <sstream>

#include "hashtable.h"
#include "people.h"
#include "degrees.h"
#include "funds.h"
#include "investments.h"
#include "objects.h"
#include "offices.h"
#include "funding_rounds.h"
#include "acquisitions.h"



void GetPersonsID(HashTable<int, People> table, std::string first, std::string last) {
  for (auto it = table.begin(); it != table.end(); it++) {
    if ((*it).second.first_name == first && (*it).second.last_name == last) {
      std::cout << "Person's ID is: " << (*it).second.object_id << std::endl;
      break;
    }
  }
};

void GetCompanyId(HashTable<int, Objects> table, const std::string& companyname) {
  for (auto it = table.begin(); it != table.end(); it++) {
    if ((*it).second.name == companyname) {
		if ((*it).second.entity_type != "Company")
		{
			continue;
		}
		else {
			std::cout << "The company id is: " << (*it).second.id << std::endl;
		}
    }
  }
};

void GetPersonsEducation(HashTable<int, People> table, HashTable<int, Degree> table2, std::string first, std::string last) {
  std::string s;
  for (auto it = table.begin(); it != table.end(); it++) {
    if ((*it).second.first_name == first && (*it).second.last_name == last) {
      s = (*it).second.object_id;
      break;
    }
  }
  for (auto it = table2.begin(); it != table2.end(); it++) {
    if ((*it).second.object_id == s) {
	  if ((*it).second.institution!= ""){
		std::cout << "Person's educational institute is: " << (*it).second.institution << std::endl;
        break;
	  }
	  else{
		std::cout << "Not found" << std::endl;
	  }
    }
  }  
};



int main()
{
	HashTable<int, People> HashObjects = parsePeople();
	HashTable<int, Objects> HashObjects2 = parseObjects();
	HashTable<int, Degree> HashObjects3 = parseDegree();
	GetPersonsEducation(HashObjects, HashObjects3, "Sridhar", "Gundaiah");
	//GetPersonsID(HashObjects, "Raju", "Vegesna");
	//GetCompanyId(HashObjects2, "Flektor");
	return 0;
}