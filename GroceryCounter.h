#ifndef CS210_MODULE7_PROJECT3_GROCERY_COUNTER_H_
#define CS210_MODULE7_PROJECT3_GROCERY_COUNTER_H_

#include<string>
#include<map>
#include<vector>

/**
* Class used to manage and count grocery list items. This class declares methods
* that can be used by the user to search or print the grocery list totals.
*
* @author Thomas Rutheford
*/
class GroceryCounter
{
public:
	// Constructor
	GroceryCounter(const std::vector<std::string>& t_groceryList);

	// Get and print count for specific item
	void getCountForItem();

	// Prints count totals
	void printTotals();

	// Print counts as histogram
	void printHistogram(char t_char);

	// Get the grocery totals map
	std::map<std::string, int> getGroceryMap();

private:
	// Loads the list into the map
	void loadMap(const std::vector<std::string>& t_groceryList);

	// Map to store the grocery list totals
	std::map<std::string, int> m_groceryMap;

	// Stores the max lenght grocery item string
	int m_maxStringLength;
};

#endif // !CS210_MODULE7_PROJECT3_GROCERY_COUNTER_H_