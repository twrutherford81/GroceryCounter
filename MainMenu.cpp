/**
* This class implements the functions declared in MainMenu.h and contains
* helper functions to display a menu and get a user choice.
*
* @author Thomas Rutherford
*/

#include <iomanip>
#include <iostream>
#include <string>
#include <vector>
#include "MainMenu.h"

using namespace std;

/**
* Helper function to print repeating characters.
*
* @param t_char:     the char to repeat
* @param t_numChars: number of repeats (defaults to OUTPUT_WIDTH)
*/
string MainMenu::nCharString(char t_char, int t_numChars)
{
	return string(t_numChars, t_char);
}

/**
* Prints the given prompt centered in a box of '*' characters. The
* width of the heading will be equal to the OUTPUT_WIDTH.
*
* @param t_prompt the text to print in the heading
*/
void MainMenu::printHeading(string t_prompt)
{
	cout << endl;
	cout << nCharString('*') << endl;
	printLineCentered(t_prompt);
	cout << nCharString('*') << endl;
}

/**
* Prints a line of text left justified between two '*' characters. The
* width of the line will be equal to the OUTPUT_WIDTH.
*
* @param t_lineText: the text to print
*/
void MainMenu::printLineLeft(string t_lineText)
{
	// Calculate the number of spaces before the end '*'.
	int numSpaces = OUTPUT_WIDTH - 3 - static_cast<int>(t_lineText.size());

	// Output each line formatted as * t_lineText    *.
	cout << "* " << t_lineText << nCharString(' ', numSpaces) << "*" << endl;
}

/**
* Prints a line of text centered between two '*' characters. The
* width of the line will be equal to the OUTPUT_WIDTH.
*
* @param t_lineText: the text to print
*/
void MainMenu::printLineCentered(string t_lineText)
{
	// Calculate the number of spaces needed on each side
	int numSpaces = OUTPUT_WIDTH - static_cast<int>(t_lineText.size());

	// Account for a space on either side of the prompt
	int promptSize = static_cast<int>(t_lineText.size()) + 2;

	// Calculated the left and right spacing
	int spacingLeft = (OUTPUT_WIDTH - promptSize) / 2;
	int spacingRight = (OUTPUT_WIDTH - promptSize) % 2 == 0 ? spacingLeft : spacingLeft + 1;

	// Output each menu item formatted as *  t_lineText  *.
	cout << "*" << nCharString(' ', spacingLeft) << t_lineText << nCharString(' ', spacingRight) << "*" << endl;
}

/**
 * Prints a menu based on the given vector, then gets the
 * user menu choice. The menu will be 1 based, not 0 based.
 * For instance, the first item in the vector will be choice
 * 1, not choice 0.
 *
 * @return the value of the user choice (see MainMenu.h)
 */
int MainMenu::getUserChoice()
{
	// Defines the menu choices to display
	const vector<string> MENU_ITEMS = { "Get count for specific grocery item",
										"Print grocery item totals",
										"Print grocery item histogram",
										"Exit Program" };

	bool invalid = true;
	auto const MENU_ITEM_MIN = 1;
	auto const MENU_ITEM_MAX = static_cast<int>(MENU_ITEMS.size());
	int userChoice = 0;

	// Print the header
	printHeading("Corner Grocer Menu Options");

	// Print each menu item
	for (size_t i = 0; i < MENU_ITEMS.size(); ++i)
	{
		// Output each menu item formatted as * # - MENU ITEM    *
		// Note the menu item number will be one greater than its index in the vector
		string lineText = to_string((i + (size_t)1)) + " - " + MENU_ITEMS.at(i);
		printLineLeft(lineText);
	}

	// Print the footer
	cout << nCharString('*') << endl;


	// Loop until the user enters a valid option
	do
	{
		cout << "Enter a choice: ";
		cin >> userChoice;

		// Validate the input
		if (cin.fail())
		{
			// Clear the fail state.
			cin.clear();

			// Ignore the rest of the wrong user input, till the end of the line.
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		else
		{
			invalid = (userChoice < MENU_ITEM_MIN || userChoice > MENU_ITEM_MAX);
		}

		if (invalid)
		{
			// Print an error and skip the switch statement
			cout << "Enter a number between " << MENU_ITEM_MIN << " and " << MENU_ITEM_MAX << endl << endl;
		}
	} while (invalid);

	// Add a blank line after the menu choice
	cout << endl;

	return userChoice;
}

/**
* Pauses the program and waits for the user to press enter. This
* allows the user to examine the data on the screen before continuing.
*/
void MainMenu::waitForResponse()
{
	try
	{
		// Wait for user to press Enter before moving on
		cout << endl << "Press Enter to continue...";
		// Clear the input stream first
		cin.seekg(0, ios::end);
		cin.clear();
		// Wait for a response
		cin.get();
	}
	catch (runtime_error& error)
	{
		cout << error.what() << endl;
		cout << "An error occurred while waiting for user input" << endl;
	}
}
