/**
* Implements the functions declarded in GroceryCounter.h. This class will
* count grocery items found in a vector and allow the user to search for
* an item or print reports of the totals.
* 
* @author Thomas Rutheford
*/
#include <iomanip>
#include <iostream>
#include <algorithm>
#include <cctype>
#include "GroceryCounter.h"

using namespace std;

/**
* Creates a new instance of the GroceryCounter and initializes the
* grocery list count storing the data in a map.
* 
* @param t_groceryList: the grocery list to count
*/
GroceryCounter::GroceryCounter(const vector<string>& t_groceryList)
{
    loadMap(t_groceryList);
}

/**
* Gets a grocery item (string) from the user and searches the grocery
* list for that item. If found, the count total for that item will be
* printed.
*/
void GroceryCounter::getCountForItem()
{
    string userInput;

    // Get the item to search for from the user
    cout << "Enter a grocery item: ";
    cin >> userInput;
    cout << endl;


    // Check if the user item is found in the map an print the count if found.
    // If the item is not found, try to switch the input to sentence case and
    // search again. If the item is still not found, notifiy the user.
    if (m_groceryMap.count(userInput) != 0)
    {
        cout << "Count for " << userInput << " is " << m_groceryMap.at(userInput);
    }
    else
    {
        // Cache the original string before modifying
        string tempString = userInput;

        // Help the user out by converting their input into sentence case and double checking.
        // The search is case sensative, so it could be that the user input does not match a
        // grocery item because it is the wrong case.
        transform(userInput.begin(), userInput.end(), userInput.begin(), [](unsigned char c) { return std::tolower(c); });
        transform(userInput.begin(), userInput.begin() + 1, userInput.begin(), [](unsigned char c) { return std::toupper(c); });

        if (m_groceryMap.count(userInput) != 0)
        {
            cout << "Count for " << userInput << " is " << m_groceryMap.at(userInput);
        }
        else
        {
            cout << tempString << " was not found in the list!";
        }
    }

    cout << endl;
}

/**
* Prints the grocery items with the occurance totals
*/
void GroceryCounter::printTotals()
{
    // Print a header
    cout << string(26, '=') << endl;
    cout << " GROCERY TOTALS BY ITEM" << endl;
    cout << string(26, '=') << endl;

    // Print each grocery item and the count total
    for (auto const& mapValuePair : m_groceryMap)
    {
        // Print each item as follows:
        //  GroceryItem ........ 5
        int fill = m_maxStringLength - (mapValuePair.first).size() + 8;
        cout << " " << mapValuePair.first << " " << setfill('.') << setw(fill);
        cout << " " << mapValuePair.second << endl;
    }

    // Print a footer
    cout << string(26, '=') << endl;
    cout << string(26, '=') << endl;
}

/**
* Prints the grocery list totals formatted as a histogram.
* 
* @param t_char: the char to use for the histogram
*/
void GroceryCounter::printHistogram(char t_char)
{
    // Print a header
    cout << string(26, '=') << endl;
    cout << " GROCERY TOTALS HISTOGRAM" << endl;
    cout << string(26, '=') << endl;

    // Print each grocery item and the count as a histogram
    for (auto const& mapValuePair : m_groceryMap)
    {
        // Align the item names on the right and print the histogram char
        // per the count.
        cout << " " << right << setw(m_maxStringLength) << setfill(' ');
        cout << mapValuePair.first << " ";
        cout << string(mapValuePair.second, t_char) << endl;
    }

    // Print a footer
    cout << string(26, '=') << endl;
    cout << string(26, '=') << endl;
}

/**
* Call to get the grocery counts contained in a map. The map
* key is the grocery item, the value is the count.
* 
* @return a map with the grocery item counts
*/
map<string, int> GroceryCounter::getGroceryMap()
{
    return m_groceryMap;
}

/**
* Loads a vector list of grocery items into a map. Each unique
* grocery item will be listed once in the map as the key and the value
* will be the number of occurances of the item in the list.
* 
* @param t_groceryList: the grocery list vector to parse
*/
void GroceryCounter::loadMap(const vector<string>& t_groceryList)
{
    string groceryItem;
    m_maxStringLength = 0;

    for (size_t i = 0; i < t_groceryList.size(); ++i)
    {
        groceryItem = t_groceryList.at(i);

        // If the grocery item exists in the map, increment the count.
        // Otherwise, add the grocery item to the map.
        if (m_groceryMap.count(groceryItem) != 0)
        {
            // Increment the count
            m_groceryMap.at(groceryItem)++;
        }
        else
        {
            m_groceryMap.emplace(groceryItem, 1);
        }

        // Keep track of the max length grocery item. This will
        // be used to format the printed reports.
        if (static_cast<int>(groceryItem.size()) > m_maxStringLength)
        {
            m_maxStringLength = groceryItem.size();
        }
    }
}
