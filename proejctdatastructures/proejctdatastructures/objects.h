#ifndef OBJECTS_H
#define OBJECTS_H

#include "hashtable.h"
#include <iostream>
#include <fstream>
#include <string>

// Class to represent a single object
class Objects
{
public:
    std::string entity_type;
    std::string id;
    std::string parent_id;
    std::string name;
    std::string normalized_name;
    std::string category_code;
    std::string status;
    std::string founded_at;
    std::string closed_at;
    std::string homepage_url;
    std::string twitter_username;
    std::string description;
    std::string tag_list;
    std::string country_code;
    std::string state_code;
    std::string city;
    std::string region;
    std::string investment_rounds;
    std::string invested_companies;
    std::string first_funding_at;
    std::string last_funding_at;
    std::string funding_rounds;
    std::string funding_total_usd;
    std::string first_milestone_at;
    std::string last_milestone_at;
    std::string milestones;
    std::string relationships;

};

HashTable<int, Objects> parseObjects() {
    // Open the CSV file
    std::ifstream file("objects.csv");
    // Check if the file was successfully opened
    if (!file.is_open())
    {
        std::cout << "Error: Failed to open file." << std::endl;
        return 1;
    }

    // Create a hash table to store the data
    HashTable<int, Objects> data(500000);
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
        Objects record;
        int entity_id;


        // Read each column of the line
        while (end != std::string::npos)
        {
            // Get the current column
            std::string column_data = line.substr(start, end - start);

            // Store the data in the Acquisition object
            switch (column)
            {
            case 0:
                record.id = column_data;
                break;
            case 1:
                record.entity_type = column_data;
                break;
            case 2:
                try {
                    int value = std::stoi(column_data);
                    entity_id = value;
                }
                catch (const std::invalid_argument& e) {
                    std::cerr << "Error: Invalid input: " << column_data << std::endl;
                }
                break;
            case 3:
                record.parent_id = column_data;
                break;
            case 4:
                record.name = column_data;
                break;
            case 5:
                record.normalized_name = column_data;
                break;
            case 6:
                record.category_code = column_data;
                break;
            case 7:
                record.status = column_data;
                break;
            case 8:
                record.founded_at = column_data;
                break;
            case 9:
                record.closed_at = column_data;
                break;
            case 10:
                record.homepage_url = column_data;
                break;
            case 11:
                record.twitter_username = column_data;
                break;
            case 12:
                record.description = column_data;
                break;
            case 13:
                record.tag_list = column_data;
                break;
            case 14:
                record.country_code = column_data;
                break;
            case 15:
                record.state_code = column_data;
                break;
            case 16:
                record.city = column_data;
                break;
            case 17:
                record.region = column_data;
                break;
            case 18:
                record.investment_rounds = column_data;
                break;
            case 19:
                record.invested_companies = column_data;
                break;
            case 20:
                record.first_funding_at = column_data;
                break;
            case 21:
                record.last_funding_at = column_data;
                break;
            case 22:
                record.funding_rounds = column_data;
                break;
            case 23:
                record.funding_total_usd = column_data;
                break;
            case 24:
                record.first_milestone_at = column_data;
                break;
            case 25:
                record.last_milestone_at = column_data;
                break;
            case 26:
                record.milestones = column_data;
                break;
            case 27:
                record.relationships = column_data;
                break;
            }

            // Move to the next column
            start = end + 1;
            end = line.find(',', start);
            column++;
        }

        // Store the data in the hash table
        data.Set(entity_id, record);
    }

    // Close the file
    file.close();
    //int key = 100189;
    //Objects row = data.Get(key);

    // Access the attributes of the record
    //std::cout << "Entity object ID: " << row.name << std::endl;
    // ...

    // Print the data stored in the hash table

    return data;
}

#endif 