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


std::string GetPersonsID(AVLTree<People> peopletree, AVLTree<People>::Node* node, std::string first, std::string last) {
  if (node == NULL) {
    return NULL;
  }
  if (node->data.first_name == first && node->data.last_name == last){
    return node->data.object_id;
  }
  GetPersonsID(peopletree, node->left , first, last);
  GetPersonsID(peopletree, node->right , first, last);
};

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

void GetEmployeeTitle(AVLTree<People> peopletree, AVLTree<People>::Node* node, HashTable<int, Relationship> table, std::string first, std::string last){
  std::string s;
  s = GetPersonsID(peopletree, node, first, last);
  for (auto it = table.begin(); it != table.end(); it++) {
    if ((*it).second.person_object_id == s) {
		if ((*it).second.is_past=="1")
		{
			if ((*it).second.title!= ""){
		std::cout << "Person is currently working as: " << (*it).second.title << std::endl;
        break;
	  }
	        else{
		std::cout << "Record Not Found" << std::endl;
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

void GiveEmployeeList(AVLTree<People> peopletree, AVLTree<People>::Node* node, std::string company_name)
{
  if (node == NULL) {
    return;
  }
  if (node->data.affiliation_name == company_name){
    std::cout << node->data.first_name << " "<< node->data.last_name<< std::endl;
  }
  GiveEmployeeList(peopletree, node->left , company_name);
  GiveEmployeeList(peopletree, node->right , company_name);
}

void CompanyInCategory(HashTable<int, Objects> table, std::string categoryname) 
{
    int count = 0;
    for (auto it = table.begin(); it != table.end(); it++)
    {
        std::cout << "Company List : ";
        if ((*it).second.category_code == categoryname)
        {
            std::cout << "Company ID: " << (*it).second.id << "\tName: " << (*it).second.name << std::endl;
            count++;
        }
        break;
    }
    //displaying the number of companies in given category
    std::cout << "Number of companies : " << count;
};

void GetCompanyFundingRoundInfo(HashTable<int, Objects> hashObject, HashTable<int, Funding_Rounds> hashFundingRounds, std::string companyname)
{
    std::string id_store;
    for (auto it = hashObject.begin(); it != hashObject.end(); it++)
    {
        if ((*it).second.name == companyname)
        {
            id_store = (*it).second.id;
            break;
        }
    }
    for (auto it = hashFundingRounds.begin(); it != hashFundingRounds.end(); it++)
    {
        if ((*it).second.object_id == id_store)
        {
            std::cout << "Funding Round Type : " << (*it).second.funding_round_type << "\tRaised Amount : " << (*it).second.raised_amount_usd << std::endl;
            break;
        }
       // continue;
    }
}

void GetPersonsEducation(AVLTree<People> peopletree, AVLTree<People>::Node* node, AVLTree<Degree> degreetree, AVLTree<Degree>::Node* node2, std::string first, std::string last) {
  std::string s;
  s = GetPersonsID(peopletree, node, first, last);
  if (node2 == NULL) {
    return;
  }
  if (node2->data.object_id == s){
    std::cout<<"Degree: "<<node2->data.degree_type<<std::endl;
    std::cout<<"Subject: "<<node2->data.subject<<std::endl;
    std::cout<<"Insitution: "<<node2->data.institution<<std::endl;
    std::cout<<"Graduated: "<<node2->data.graduated_at<<std::endl;
    return;
  }
  GetPersonsEducation(peopletree, node , degreetree, node2->left, first, last);
  GetPersonsEducation(peopletree, node , degreetree, node2->right, first, last);
};

void searchByLocation(HashTable<int, Offices> hashOffice, HashTable <int,Objects> hashObject, std::string location)
{
    std::string id_store;
    for (auto it = hashOffice.begin(); it != hashOffice.end(); it++)
    {
        if (((*it).second.region == location) || ((*it).second.city == location))
        {
            id_store = (*it).second.object_id;
                for (auto it = hashObject.begin(); it != hashObject.end(); it++)
                {
                  if ((*it).second.id == id_store)
                  {
                    std::cout << (*it).second.name << std::endl;
                  }
                }
          return;
        }
    }

}

int main()
{
	AVLTree<People> Ppl = parsePeople();
  AVLTree<Degree> Deg = parseDegree();
	HashTable<int, Objects> HashObjects2 = parseObjects();
  HashTable<int, Funding_Rounds> HashObjects3 = parseFundingRounds();
	HashTable<int, Relationship> HashObjects4 = parseRelationship();
	HashTable<int, Offices> HashObjects5 = parseOffices();	
	HashTable<int, Acquisition> HashObjects6 = parseAcquisition();	
  //GetCompanyFundingRoundInfo(HashObjects2, HashObjects3, "Scribd");
  //CompanyInCategory(HashObjects2, "Fitbit");
  //searchByLocation(HashObjects5, HashObjects2, "SF Bay"); 
	//TotalAcquiredEntities(HashObjects6, HashObjects2, "Yahoo!"); tested
	//GetCompanyAddress(HashObjects2, HashObjects5, "Wetpaint"); tested
	//GetEmployeeTitle(HashObjects, HashObjects4, "Owen", "Van Natta"); tested
	//GetPersonsEducation(Ppl, Ppl.root_, Deg, Deg.root_, "Ian", "Reardon"); 
	//GetPersonsID(Ppl, Ppl.root_, "Raju", "Vegesna"); tested
	//GetCompanyId(HashObjects2, "Flektor"); tested
	//GiveEmployeeList(Ppl, Ppl.root_, "Helio"); tested
	return 0;
}