#ifndef ACQUISITIONS_H
#define ACQUISITIONS_H

#include "hashtable.h"
#include <iostream>
#include <fstream>
#include <string>

// Class to represent a single acquisition
class Acquisition
{
public:
    std::string acquisition_id;
    std::string acquiring_object_id;
    std::string acquired_object_id;
    std::string term_code;
    std::string price_amount;
    std::string price_currency_code;
    std::string acquired_at;
};

HashTable<int, Acquisition> parseAcquisition()
{
    // Open the CSV file
    std::ifstream file("acquisitions.csv");
    // Check if the file was successfully opened
    if (!file.is_open())
    {
        std::cout << "Error: Failed to open file." << std::endl;
        return 1;
    }

    // Create a hash table to store the data
    HashTable<int, Acquisition> data(10000);
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
        Acquisition record;
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
                record.acquisition_id = column_data;
                break;
            case 2:
                record.acquiring_object_id = column_data;
                break;
            case 3:
                record.acquired_object_id = column_data;
                break;
            case 4:
                record.term_code = column_data;
                break;
            case 5:
                record.price_amount = column_data;
                break;
            case 6:
                record.price_currency_code = column_data;
                break;
            case 7:
                record.acquired_at = column_data;
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
    //int key = 1234;
    //Acquisition row = data.Get(key);

    // Access the attributes of the record
  //  std::cout << "Acquisition ID: " << row.acquisition_id << std::endl;
    //std::cout << "Acquiring object ID: " << row.acquiring_object_id << std::endl;
    // ...

    // Print the data stored in the hash table

    return data;
}

#endif