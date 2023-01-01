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


void PrintCompanyDetails(HashTable<int, Objects> table, std::string companyname ) {
	
	for (int i = 0; i <= table.size_; i++) {
		Objects temp;
		temp = table.Get(i);
		if (temp.name == companyname) {
			std::cout << "Id of the company is: " << temp.id;
			std::cout << "Description of the company is: " << temp.description;
			return;
		};
	};
};

void GiveAffiliationName(HashTable<int, People> table, std::string first, std::string last) {
	
	for (int i = 0; i <= table.size_; i++) {
		People temp;
		temp = table.Get(i);
		if (temp.first_name == first && temp.last_name == last) {
			std::cout << "Affiliation is: " << temp.affiliation_name;
			return;
		};
	};
};

int main()
{
	HashTable<int, People> HashObjects = parsePeople();
	//PrintCompanyDetails(HashObjects, "ChatRandom");
	GiveAffiliationName(HashObjects, "Raju", "Vegesna");
	return 0;
}