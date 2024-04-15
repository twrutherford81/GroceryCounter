#ifndef CS210_MODULE7_PROJECT3_MAIN_MENU_H_
#define CS210_MODULE7_PROJECT3_MAIN_MENU_H_

#include <string>

/**
* Class prototype used to declare functions and constants for
* the main menu.
*
* @author Thomas Rutheford
*/
class MainMenu
{
public:
	/** Prints a span of a specified char a specified length */
	static std::string nCharString(char t_char, int t_numChars = OUTPUT_WIDTH);

	/** Prints a heading surrounded by a box of asterisks */
	static void printHeading(std::string t_prompt);

	/** Prints a left justified line surrounded by asterisks */
	static void printLineLeft(std::string t_lineText);

	/** Prints a centered line surrounded by asterisks */
	static void printLineCentered(std::string t_lineText);

	/** Prompts for gets a user choice from a menu */
	int getUserChoice();

	/** Pauses the program, waiting for user input */
	void waitForResponse();

	// Define menu choice values
	static const int MENU_ITEM_SEARCH_WORD = 1;
	static const int MENU_ITEM_PRINT_COUNT = 2;
	static const int MENU_ITEM_PRINT_HISTOGRAM = 3;
	static const int MENU_ITEM_EXIT = 4;

private:
	/** Defines the default width of the generated output */
	static const int OUTPUT_WIDTH = 50;
};

#endif //!CS210_MODULE7_PROJECT3_MAIN_MENU_H_