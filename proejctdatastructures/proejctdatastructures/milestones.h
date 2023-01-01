#ifndef MILESTONES_H
#define MILESTONES_H

#include "hashtable.h"
#include <iostream>
#include <fstream>
#include <string>

// Class to represent a single milestone
class Milestone
{
public:
    int object_id;
    std::string milestone_at;
    std::string description;
    std::string source_url;
    std::string source_description;
};

HashTable<int, Milestone> parseMilestone()
{
    // Open the CSV file
    std::ifstream file("milestones.csv");
    // Check if the file was successfully opened
    if (!file.is_open())
    {
        std::cout << "Error: Failed to open file." << std::endl;
        return 1;
    }

    // Create a hash table to store the data
    HashTable<int, Milestone> data(10000);
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

        // Create a Milestone object to store the data
        Milestone record;
        int id;

        // Read each column of the line
        while (end != std::string::npos)
        {
            // Get the current column
            std::string column_data = line.substr(start, end - start);

            // Store the data in the Milestone object
            switch (column)
            {
            case 0:
                id = std::stoi(column_data);
                break;
            case 1:
                record.object_id = std::stoi(column_data);
                break;
            case 2:
                record.milestone_at = column_data;
                break;
            case 3:
                record.description = column_data;
                break;
            case 4:
                record.source_url = column_data;
                break;
            case 5:
                record.source_description = column_data;
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
    int key = 1234;
    Milestone row = data.Get(key);

    // Access the attributes of the record
    std::cout << "Object ID: " << row.object_id << std::endl;
    std::cout << "Milestone at: " << row.milestone_at << std::endl;
    std::cout << "Description: " << row.description << std::endl;
    std::cout << "source description: " << row.source_description << std::endl;



#endif