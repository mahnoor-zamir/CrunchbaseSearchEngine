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



int main()
{
	//HashTable<int, Objects> HashObjects = parseObjects();
	//PrintCompanyDetails(HashObjects, "ChatRandom");
	return 0;
}