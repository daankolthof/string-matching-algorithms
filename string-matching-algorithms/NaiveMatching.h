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
	static int findString(const std::string& string, const std::string& pattern)
	{
		for (size_t i = 0; i <= string.length() - pattern.length(); i++)
		{
			// For this starting position in the string, iterate over the entire pattern, looking for a match.
			bool match = true;
			for (size_t j = 0; match && j < pattern.length(); j++)
			{
				if (string[i+j] != pattern[j])
				{
					match = false;
				}		
			}

			if (match)
			{
				// A match was found, return the string index at which the pattern starts.
				return i;
			}
		}

		// No match was found, return -1 to indicate this.
		return -1;
	}
};

#endif //NAIVE_MATCHING
