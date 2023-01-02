#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

#include "AVLTree.h"
#include "hashtable.h"
#include "people.h"
#include "degrees.h"
#include "relationship.h"
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

void GetEmployeeTitle(HashTable<int, People> table, HashTable<int, Relationship> table2, std::string first, std::string last){
  std::string s;
  for (auto it = table.begin(); it != table.end(); it++) {
    if ((*it).second.first_name == first && (*it).second.last_name == last) {
      s = (*it).second.object_id;
	  std::cout << s << std::endl;
      break;
    }
  }
  for (auto it = table2.begin(); it != table2.end(); it++) {
    if ((*it).second.person_object_id == s) {
		if ((*it).second.is_past=="1")
		{
			if ((*it).second.title!= ""){
		std::cout << "Person is currently working as: " << (*it).second.title << std::endl;
        break;
	  }
	        else{
		std::cout << "Record Not found" << std::endl;
	  }
		}
		
    }
  }  
};

void GetCompanyAddress(HashTable<int, Objects> hashObject, HashTable<int, Offices> hashOffice, std::string company_name)
{
    std::string s;
    for (auto it = hashObject.begin(); it != hashObject.end(); it++)
    {
        if ((*it).second.name == company_name)
        {
            s = (*it).second.id;
            break;
        }
    }
    for (auto it = hashOffice.begin(); it != hashOffice.end(); it++)
    {
        std::string check = (*it).second.object_id;
        if ( check == s)
        {
            if ((*it).second.address1 != "")
            {
                std::cout << "Address: " << (*it).second.address1 << std::endl;
            }
            if ((*it).second.address2 != "")
            {
                std::cout << (*it).second.address2 << std::endl;
            }
            if ((*it).second.city != "")
            {
                std::cout << "City: " << (*it).second.city << std::endl;
            }
            if ((*it).second.region != "")
            {
                std::cout << "Region: " << (*it).second.region << std::endl;
            }
            if ((*it).second.state_code != "")
            {
                std::cout << "State: " << (*it).second.state_code << std::endl;
            }
            if ((*it).second.country_code != "")
            {
                std::cout << "Country: " << (*it).second.country_code << std::endl;
            }
            else
            {
                std::cout << "Not Found" << std::endl;
            }
            break;
        }
    }
}

void TotalAcquiredEntities(HashTable<int, Acquisition> table, HashTable<int, Objects> table2, std::string companyname){
	std::string s;
	int count=0;
	for (auto it = table2.begin(); it != table2.end(); it++) {
    if ((*it).second.name == companyname) {
		if ((*it).second.entity_type != "Company")
		{
			continue;
		}
		else {
			s = (*it).second.id;
		}
        }
    }
	for (auto it = table.begin(); it != table.end(); it++){
		if ((*it).second.acquiring_object_id == s){
			count++;
			continue;
		}
	}
	std::cout<< "Total number of acquired entities by this company is: " <<count <<std::endl;
};

void GiveEmployeeList(HashTable<int, People> peopleTable, std::string company_name)
{
	std:: cout << "Employee List: ";
	std::string afname;
    for (auto it = peopleTable.begin(); it != peopleTable.end(); it++)
    {
		afname = (*it).second.affiliation_name;
        if (afname == company_name)
        {
			std::string f = (*it).second.first_name;
			std::string l = (*it).second.last_name;
            std::cout <<"\tName: " << f << " " << l;
        }

    }
}

void CompanyInCategory(HashTable<int, Objects> table, std::string categoryname){

};

int main()
{
	AVLTree<People> Ppl = parsePeople();
  AVLTree<Degree> Deg = parseDegree();
	HashTable<int, Objects> HashObjects2 = parseObjects();
	HashTable<int, Relationship> HashObjects4 = parseRelationship();
	HashTable<int, Offices> HashObjects5 = parseOffices();	
	HashTable<int, Acquisition> HashObjects6 = parseAcquisition();	
	//TotalAcquiredEntities(HashObjects6, HashObjects2, "Yahoo!");
	//GetCompanyAddress(HashObjects2, HashObjects5, "Wetpaint");
	//GetEmployeeTitle(HashObjects, HashObjects4, "Owen", "Van Natta");
	//GetPersonsEducation(HashObjects, HashObjects3, "Sridhar", "Gundaiah");
	//GetPersonsID(HashObjects, "Raju", "Vegesna");
	//GetCompanyId(HashObjects2, "Flektor");
	//GiveEmployeeList(HashObjects, "Digg");
  //   std::string s = "p:4";
  // People* p = Ppl.Search(s);
  // std::cout<< p->first_name;
	return 0;
}