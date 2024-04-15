/**
 * This program allows the user to import a list of grocery items for counting. The
 * grocery count can be output as a single item, the full list, or as a histogram.
 * Each time the program is run, a backup of the calculated counts is written to a
 * '.dat' file.
 *
 * @author Thomas Rutherford
 * @date   04/12/24
 */
#include <iostream>
#include "FileHelper.h"
#include "GroceryCounter.h"
#include "MainMenu.h"

using namespace std;

int main()
{
    // The file name of the input file
    const string IMPORT_FILENAME = "CS210_Project_Three_Input_File.txt";

    // The file name of the backup file
    const string BACKUP_FILENAME = "frequency.dat";

    // Stores the full grocery list loaded from file
    vector<string> groceryList;

    // Main menu instance used to interface the menu
    MainMenu mainMenu;

    // Holds the user menu choice
    int menuChoice = 0;

    // Populate the grocery list from file
    groceryList = FileHelper::importListFromFile(IMPORT_FILENAME);

	// Verify that the import was successful. If not, notify the user and quit the program.
    if (groceryList.size() == 0)
    {
		cout << "\nAn error occured loading the grocery list.\n"
		     << "Check that file \"" << IMPORT_FILENAME << "\" exists in the same "
		     << "directory as the program and try again." << endl;

        return -1;
    }

    // Initialize the grocery counter
    GroceryCounter groceryCounter(groceryList);

    // Backup the counted grocery list to file
    FileHelper::exportListToFile(groceryCounter.getGroceryMap(), BACKUP_FILENAME);

	// Show the main menu, and loop as long as the user wishes to continue.
	do
	{
		try
		{
			// Print the menu and prompt for a choice
			menuChoice = mainMenu.getUserChoice();

			// Handle the user choice
			switch (menuChoice)
			{
			case MainMenu::MENU_ITEM_SEARCH_WORD:
				groceryCounter.getCountForItem();
				break;
			case MainMenu::MENU_ITEM_PRINT_COUNT:
				groceryCounter.printTotals();
				break;
			case MainMenu::MENU_ITEM_PRINT_HISTOGRAM:
				groceryCounter.printHistogram('*');
				break;
			case MainMenu::MENU_ITEM_EXIT:
				cout << "Program terminated" << endl;
				break;
			default:
				cout << "Unknown menu option: " << menuChoice << endl;
				break;
			}

			// Allow the user to examine the ouput before continuing
			if (menuChoice != MainMenu::MENU_ITEM_EXIT)
			{
				mainMenu.waitForResponse();
			}
		}
		catch (runtime_error& error)
		{
			// If an error occurs, notify the user and quit safely.
			cout << error.what() << endl;
			cout << "An error occurred in the main menu, the program will now quit" << endl;
			menuChoice = MainMenu::MENU_ITEM_EXIT;
		}
	}
	while (menuChoice != MainMenu::MENU_ITEM_EXIT);


	return 0;
}