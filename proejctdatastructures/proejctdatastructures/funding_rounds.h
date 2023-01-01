#ifndef FUNDING_ROUNDS_H
#define FUNDING_ROUNDS_H

#include "hashtable.h"

#include <iostream>
#include <fstream>
#include <string>

// Class to represent a single office
class Funding_Rounds
{
public:
    std::string funding_round_id;
    std::string object_id;
    std::string funded_at;
    std::string funding_round_type;
    std::string funding_round_code;
    std::string raised_amount_usd;
    std::string pre_money_valuation_usd;
    std::string post_money_valuation_usd;
    std::string participants;
    std::string is_first_round;
    std::string is_last_round;
    std::string source_url;
    std::string source_description;

};

HashTable<int, Funding_Rounds> parseFundingRounds()
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
    HashTable<int, Funding_Rounds> data(10000);
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
        Funding_Rounds record;
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
                record.funding_round_id = column_data;
                break;
            case 2:
                record.object_id = column_data;
                break;
            case 3:
                record.funded_at = column_data;
                break;
            case 4:
                record.funding_round_type = column_data;
                break;
            case 5:
                record.funding_round_code = column_data;
                break;
            case 6:
                record.raised_amount_usd = column_data;
                break;
            case 7:
                record.pre_money_valuation_usd = column_data;
                break;
            case 8:
                record.post_money_valuation_usd = column_data;
                break;
            case 9:
                record.participants = column_data;
                break;
            case 10:
                record.is_first_round = column_data;
                break;
            case 11:
                record.is_last_round = column_data;
                break;
            case 12:
                record.source_url = column_data;
                break;
            case 13:
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
    int key = 1;
    Funding_Rounds row = data.Get(key);

    // Access the attributes of the record
    //std::cout << "Funding object ID: " << row.funding_round_id << std::endl;
    // ...

    // Print the data stored in the hash table

    return 0;
}


#endif