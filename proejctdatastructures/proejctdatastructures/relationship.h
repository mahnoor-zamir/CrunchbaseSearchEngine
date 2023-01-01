#ifndef RELATIONSHIP_H
#define RELATIONSHIP_H

#include "hashtable.h"
#include <iostream>
#include <fstream>
#include <string>

// Class to represent a single relationship
class Relationship
{
public:

    std::string relationship_id;
    int person_object_id;
    int relationship_object_id;
    std::string start_at;
    std::string end_at;
    bool is_past;
    std::string title;
};

HashTable<int, Relationship> parseRelationship()
{
    // Open the CSV file
    std::ifstream file("relationships.csv");
    // Check if the file was successfully opened
    if (!file.is_open())
    {
        std::cout << "Error: Failed to open file." << std::endl;
        return 1;
    }

    // Create a hash table to store the data
    HashTable<int, Relationship> data(10000);
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

        // Create a Relationship object to store the data
        Relationship record;
        int id;

        // Read each column of the line
        while (end != std::string::npos)
        {
            // Get the current column
            std::string column_data = line.substr(start, end - start);

            // Store the data in the Relationship object
            switch (column)
            {
            case 0:
                id = std::stoi(column_data);
                break;
            case 1:
                record.relationship_id = column_data;
                break;
            case 2:
                record.person_object_id = std::stoi(column_data);
                break;
            case 3:
                record.relationship_object_id = std::stoi(column_data);
                break;
            case 4:
                record.start_at = column_data;
                break;
            case 5:
                record.end_at = column_data;
                break;
            case 6:
                record.is_past = (column_data == "true");
                break;
            case 7:
                record.title = column_data;
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
    Relationship row = data.Get(key);

    // Access the attributes of the record
    std::cout << "Relationship ID: " << row.relationship_id << std::endl;
    std::cout << "Start at: " << row.start_at << std::endl;
    std::cout << "End at: " << row.end_at << std::endl;
    std::cout << "Title: " << row.title << std::endl;
    // ...

    // Print the data stored in the hash table

    return 0;
}

#endif