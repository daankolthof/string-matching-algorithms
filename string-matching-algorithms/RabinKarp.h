#ifndef RABIN_KARP_H
#define RABIN_KARP_H

#include <string>

class RabinKarp
{
public:

	/* Finds the given pattern in a string, returning starting index of the pattern in the given string.
	* Will return -1 if the pattern was not found in the string.
	* Uses Rabin-Karp algorithm, with an average runtime of O(n+m).
	*/
	static int findString(const std::string& string, const std::string& pattern)
	{
		// Not implemented yet.
		return -1;
	}

};

#endif //RABIN_KARP_H
