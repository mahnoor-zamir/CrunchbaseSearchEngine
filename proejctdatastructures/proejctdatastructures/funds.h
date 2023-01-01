#ifndef FUNDS_H
#define FUNDS_H

#include "hashtable.h"

#include <iostream>
#include <fstream>
#include <string>

// Class to represent a single funds.csv file
class funds
{
public:
    std::string fund_id;
    std::string object_id;
    std::string name;
    std::string funded_at;
    std::string raised_amount;
    std::string raised_currency_code;
    std::string source_url;
    std::string source_description;
};

HashTable<int, funds> parseFunds()
{
    // Open the CSV file
    std::ifstream file("funds.csv");
    // Check if the file was successfully opened
    if (!file.is_open())
    {
        std::cout << "Error: Failed to open file." << std::endl;
        return 1;
    }

    // Create a hash table to store the data
    HashTable<int, funds> data(10000);
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

        // Create an funds object to store the data
        funds record;
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
                record.fund_id = column_data;
                break;
            case 2:
                record.object_id = column_data;
                break;
            case 3:
                record.name = column_data;
                break;
            case 4:
                record.funded_at = column_data;
                break;
            case 5:
                record.raised_amount = column_data;
                break;
            case 6:
                record.raised_currency_code = column_data;
                break;
            case 7:
                record.source_url = column_data;
                break;
            case 8:
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
    funds row = data.Get(key);

    // Access the attributes of the record
    //std::cout << "Funds ID: " << row.fund_id << std::endl;
    //std::cout << "Object ID: " << row.object_id << std::endl;
    // ...

    // Print the data stored in the hash table

    return 0;
}

#endif