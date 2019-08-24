#ifndef NAIVE_MATCHING
#define NAIVE_MATCHING

#include <string>

class NaiveMatching
{
public:

	/* Finds the given pattern in a string, returning starting index of the pattern in the given string.
	 * Will return -1 if the pattern was not found in the string.
	 * Uses naive O(n*m) algorithm, with n: size of string, m: size of pattern.
	*/
	static int findString(const std::string& string, const std::string& pattern);
};

#endif //NAIVE_MATCHING
