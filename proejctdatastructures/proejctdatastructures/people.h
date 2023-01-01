#ifndef FUNDS_H
#define FUNDS_H

#include "hashtable.h"

#include <iostream>
#include <fstream>
#include <string>

// Class to represent a single people.csv file
class People
{
public:
    std::string object_id;
    std::string first_name;
    std::string last_name;
    std::string birthplace;
    std::string affiliation_name;
};

HashTable<int, People> parsePeople()
{
    // Open the CSV file
    std::ifstream file("people.csv");
    // Check if the file was successfully opened
    if (!file.is_open())
    {
        std::cout << "Error: Failed to open file." << std::endl;
        return 1;
    }

    // Create a hash table to store the data
    HashTable<int, People> data(250000);
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

        // Create an People object to store the data
        People record;
        int id;

        // Read each column of the line
        while (end != std::string::npos)
        {
            // Get the current column
            std::string column_data = line.substr(start, end - start);

            // Store the data in the Acquisition object
            switch (column)
            {
            case 0:
                id = std::stoi(column_data);
                break;
            case 1:
                record.object_id = column_data;
                break;
            case 2:
                record.first_name = column_data;
                break;
            case 3:
                record.last_name = column_data;
                break;
            case 4:
                record.birthplace = column_data;
                break;
            case 5:
                record.affiliation_name = column_data;
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
    int key = 1;
    People row = data.Get(key);

    // Access the attributes of the record
    //std::cout << "First Name: " << row.first_name << std::endl;
    //std::cout << "Object ID: " << row.object_id << std::endl;
    // ...

    // Print the data stored in the hash table

    return 0;
}

#endif