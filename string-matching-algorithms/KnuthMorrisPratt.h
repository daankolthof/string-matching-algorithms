#ifndef KNUTH_MORRIS_PRATT_H
#define KNUTH_MORRIS_PRATT_H

#include <string>
#include <vector>

class KnuthMorrisPratt
{
public:

	/* Finds the given pattern in a string, returning starting index of the pattern in the given string.
	 * Will return -1 if the pattern was not found in the string.
	 * Uses Knuth-Morris-Pratt algorithm, with a runtime of O(n+m), with n: size of string.
	*/
	static int findString(const std::string& string, const std::string& pattern);

private:
	/* Builds the table to use during string matching.
	*/
	static void build_table(const std::string& pattern);

	static std::vector<int> table;
};

#endif //KNUTH_MORRIS_PRATT_H
