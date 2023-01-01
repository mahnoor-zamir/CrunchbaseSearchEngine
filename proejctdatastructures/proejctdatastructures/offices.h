#ifndef OFFICES_H
#define OFFICES_H

#include "hashtable.h"
#include <iostream>
#include <fstream>
#include <string>

// Class to represent a single office
class Offices
{
public:
    std::string object_id;
    std::string office_id;
    std::string description;
    std::string region;
    std::string address1;
    std::string address2;
    std::string city;
    std::string zip_code;
    std::string state_code;
    std::string country_code;
    std::string latitude;
    std::string longitude;
};

HashTable<int, Offices> parseOffices()
{
    // Open the CSV file
    std::ifstream file("offices.csv");
    // Check if the file was successfully opened
    if (!file.is_open())
    {
        std::cout << "Error: Failed to open file." << std::endl;
        return 1;
    }

    // Create a hash table to store the data
    HashTable<int, Offices> data(10000);
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

        // Create an Acquisition object to store the data
        Offices record;
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
                record.office_id = column_data;
                break;
            case 3:
                record.description = column_data;
                break;
            case 4:
                record.region = column_data;
                break;
            case 5:
                record.address1 = column_data;
                break;
            case 6:
                record.address2 = column_data;
                break;
            case 7:
                record.city = column_data;
                break;
            case 8:
                record.zip_code = column_data;
                break;
            case 9:
                record.state_code = column_data;
                break;
            case 10:
                record.country_code = column_data;
                break;
            case 11:
                record.latitude = column_data;
                break;
            case 12:
                record.longitude = column_data;
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
    Offices row = data.Get(key);

    // Access the attributes of the record
    //std::cout << "Office ID: " << row.office_id << std::endl;
    // ...

    // Print the data stored in the hash table

    return 0;
}

#endif