#ifndef DEGREES_H
#define DEGREES_H

#include "hashtable.h"
#include <iostream>
#include <fstream>
#include <string>

// Class to represent a single degree
class Degree
{
public:
    std::string object_id;
    std::string degree_type;
    std::string subject;
    std::string institution;
    std::string graduated_at;
};

HashTable<int, Degree> parseDegree()
{
    // Open the CSV file
    std::ifstream file("degrees.csv");
    // Check if the file was successfully opened
    if (!file.is_open())
    {
        std::cout << "Error: Failed to open file." << std::endl;
        return 1;
    }

    // Create a hash table to store the data
    HashTable<int, Degree> data(120000);
    // Read the header line of the CSV file
    std::string header;
    std::getline(file, header);

    // Read each line of the CSV file
    while (file.good())
    {
        // Read a line from the file
        std::string line;
        std::getline(file, line);

        // Split the line into columns
        int start = 0;
        int end = line.find(',');
        int column = 0;

        // Create a Degree object to store the data
        Degree record;
        int id;
        // Read each column of the line
        while (end != std::string::npos)
        {
            // Get the current column
            std::string column_data = line.substr(start, end - start);

            // Store the data in the Degree object
            switch (column)
            {
            case 0:
                id = std::stoi(column_data);
                break;
            case 1:
                record.object_id = column_data;
                break;
            case 2:
                record.degree_type = column_data;
                break;
            case 3:
                record.subject = column_data;
                break;
            case 4:
                record.institution = column_data;
                break;
            case 5:
                record.graduated_at = column_data;
                break;
            }

            // Move to the next column
            start = end + 1;
            end = line.find(',', start);
            column++;
        }

        // Store the data in the hash table
        data.Set(id, record);
    }

    // Close the file
    file.close();
    //int key = 1;
    //Degree row = data.Get(key);

    // Access the attributes of the record
    /*std::cout << "Object ID: " << row.object_id << std::endl;
    std::cout << "Degree type: " << row.degree_type << std::endl;
    std::cout << "Subject: " << row.subject << std::endl;
    std::cout << "Institution" << row.institution << std::endl;*/
    return data;
}


#endif