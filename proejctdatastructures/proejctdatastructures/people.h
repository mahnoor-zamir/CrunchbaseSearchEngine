#ifndef PEOPLE_H
#define PEOPLE_H

#include <iostream>
#include <fstream>
#include <sstream>
#include "AVLTree.h"
// Class to represent a single people.csv file
class People
{
public:
    std::string id;
    std::string object_id;
    std::string first_name;
    std::string last_name;
    std::string birthplace;
    std::string affiliation_name;

    People(const std::string id="", const std::string& object_id="", const std::string& first_name="",
         const std::string& last_name="", const std::string& birthplace="",
         const std::string& affiliation_name="")
            : id(id),
              object_id(object_id),
              first_name(first_name),
              last_name(last_name),
              birthplace(birthplace),
              affiliation_name(affiliation_name) {}

    bool operator>(const People& other) const { return object_id > other.object_id; }
    bool operator<(const People& other) const { return object_id < other.object_id; }
    bool operator==(const People& other) const { return object_id == other.object_id; }
    bool operator>(const std::string& other) const { return object_id > other; }
    bool operator<(const std::string& other) const { return object_id < other; }
    bool operator==(const std::string& other) const { return object_id == other; }


};


std::ostream& operator<<(std::ostream& out, const People& ppl) {
    out << "ID: " << ppl.id << std::endl;
    out << "Object ID: " << ppl.object_id << std::endl;
    out << "First Name: " << ppl.first_name << std::endl;
    out << "Last Name: " << ppl.last_name << std::endl;
    out << "Birthplace: " << ppl.birthplace << std::endl;
    out << "Affiliation Name: " << ppl.affiliation_name << std::endl;
    return out;
}


AVLTree<People> parsePeople() {
    std::ifstream file("people.csv");
    std::string line;
    AVLTree<People> tree;
    while (std::getline(file, line)) {
        std::stringstream lineStream(line);
        std::string cell;
        People ppl;
        std::getline(lineStream, ppl.id, ',');
        std::getline(lineStream, ppl.object_id, ',');
        std::getline(lineStream, ppl.first_name, ',');
        std::getline(lineStream, ppl.last_name, ',');
        std::getline(lineStream, ppl.birthplace, ',');
        std::getline(lineStream, ppl.affiliation_name, ',');
        tree.Insert(ppl);
    }
    return tree;
}



#endif
