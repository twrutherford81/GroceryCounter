#ifndef CS210_MODULE7_PROJECT3_FILE_HELPER_H_
#define CS210_MODULE7_PROJECT3_FILE_HELPER_H_

#include <string>
#include <map>
#include <vector>

/**
* Helper class used to read and write files. This class declares methods that can be
* used to import from or export to a file. The file must be formatted with a string on
* each line.
* 
* @author Thomas Rutheford
*/
class FileHelper
{
public:
	// Imports a list from file
	static std::vector<std::string> importListFromFile(std::string t_fileName);

	// Exports a list to file
	static void exportListToFile(const std::map<std::string, int>& t_mapToExport, std::string t_fileName);
};

#endif // !CS210_MODULE7_PROJECT3_FILE_HELPER_H_