/**
* This class implements the functions declared in fileHelper.h.  The purpose
* of this file is to provide functions for importing and exporting data using
* files.
* 
* @author Thomas Rutherford
*/

#include <iostream>
#include <fstream>
#include "FileHelper.h"

using namespace std;

/**
* Imports a list of items from the given file. The file should be formatted
* with one string on each line for a successful import.
* 
* @param t_fileName: the full path of the file to import
* 
* @return a vector containing the strings read from the file
*/
vector<string> FileHelper::importListFromFile(std::string t_fileName)
{
    string groceryItem;
    vector<string> groceryList;
    ifstream inputFS;
 
    try
    {
        inputFS.open(t_fileName);

        // Notify the user if the file could not be opened
        if (!inputFS.is_open()) {
            cout << "Could not open file: " << t_fileName << endl;
            return groceryList;
        }

        // Read the first string, then loop through the remaining data in the file
        // until a read failure occurs.
        inputFS >> groceryItem;
        while (!inputFS.fail())
        {
            groceryList.push_back(groceryItem);

            // Get the next grocery item
            inputFS >> groceryItem;
        }

        // Report an error if the whole input file was not read
        if (!inputFS.eof()) {
            cout << "Failed to read the entire input file: " << t_fileName << endl;
        }
    }
    catch (runtime_error& error)
    {
        cout << "Failed to import file: " << t_fileName;
        cout << ", " << error.what() << endl;
    }

    // Close the file
    inputFS.close();

    return groceryList;
}

/**
* Exports the given map to file for backup purposes. The file will be stored as the given filename.
* 
* @param t_listToExport: the map containing the data to export to file
* @param t_fileName: the file to export to
*/
void FileHelper::exportListToFile(const map<string, int>& t_listToExport, string t_fileName)
{
    ofstream outputFS;
    string lastItem;

    try
    {
        outputFS.open(t_fileName);

        // Notify the user if the file could not be opened 
        if (!outputFS.is_open())
        {
            throw runtime_error("Could not open file: " + t_fileName);
        }

        // Get the last item to determine when not to add an end line char
        lastItem = t_listToExport.rbegin()->first;

        // Export each map value pair to the output file
        for (auto const& mapValuePair : t_listToExport)
        {
            // Write the data pairs as "key value" on each line
            outputFS << mapValuePair.first << " " << mapValuePair.second;

            // Add end line char except for last item
            if (mapValuePair.first != lastItem)
                outputFS << endl;
        }
    }
    catch (runtime_error& error)
    {
        cout << "Failed to backup grocery list to file: " << t_fileName;
        cout << ", " << error.what() << endl;
    }

    // Close the file
    outputFS.close();
}
