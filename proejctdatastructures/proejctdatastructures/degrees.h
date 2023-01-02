#ifndef DEGREES_H
#define DEGREES_H

#include <iostream>
#include <fstream>
#include <sstream>
#include "AVLTree.h"
// Class to represent a single people.csv file
class Degree
{
public:
    std::string id;
    std::string object_id;
    std::string degree_type;
    std::string subject;
    std::string institution;
    std::string graduated_at;

    Degree(const std::string id="", const std::string& object_id="", const std::string& degree_type="",
         const std::string& subject="", const std::string& institution="",
         const std::string& graduated_at="")
            : id(id),
              object_id(object_id),
              degree_type(degree_type),
              subject(subject),
              institution(institution),
              graduated_at(graduated_at) {}

    bool operator>(const Degree& other) const { return object_id > other.object_id; }
    bool operator<(const Degree& other) const { return object_id < other.object_id; }
    bool operator==(const Degree& other) const { return object_id == other.object_id; }
    bool operator>(const std::string& other) const { return object_id > other; }
    bool operator<(const std::string& other) const { return object_id < other; }
    bool operator==(const std::string& other) const { return object_id == other; }
};


std::ostream& operator<<(std::ostream& out, const Degree& deg) {
    out << "ID: " << deg.id << std::endl;
    out << "Object ID: " << deg.object_id << std::endl;
    out << "Degree Type: " << deg.degree_type << std::endl;
    out << "Subject: " << deg.subject << std::endl;
    out << "Institution: " << deg.institution << std::endl;
    out << "Graduation Date: " << deg.graduated_at << std::endl;
}


AVLTree<Degree> parseDegree() {
    std::ifstream file("degrees.csv");
    std::string line;
    AVLTree<Degree> tree;
    while (std::getline(file, line)) {
        std::stringstream lineStream(line);
        std::string cell;
        Degree deg;
        std::getline(lineStream, deg.id, ',');
        std::getline(lineStream, deg.object_id, ',');
        std::getline(lineStream, deg.degree_type, ',');
        std::getline(lineStream, deg.subject, ',');
        std::getline(lineStream, deg.institution, ',');
        std::getline(lineStream, deg.graduated_at, ',');
        tree.Insert(deg);
    }
    return tree;
}



#endif
