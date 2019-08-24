#ifndef RABIN_KARP_H
#define RABIN_KARP_H

#include <string>

class RabinKarp
{
public:

	static const uint8_t HASH_MODULUS = 101;

	/* Finds the given pattern in a string, returning starting index of the pattern in the given string.
	* Will return -1 if the pattern was not found in the string.
	* Uses Rabin-Karp algorithm, with an average runtime of O(n+m).
	*/
	static int findString(const std::string& string, const std::string& pattern);

private:
	/* Calculates the hash based on the input string, only used for
	* pattern and the first characters of the string to search in.
	*/
	static int calculateHash(const std::string& string);

	/* Calculates rolling hash based on previous hash, the character that will roll out of the hash,
	* the character that will roll into the hash, and the offset of the character that will roll out.
	*/
	static int calculateRollingHash(const uint8_t previous_hash, const char old_char, const char new_char, const uint8_t offset_left_char);

};

#endif //RABIN_KARP_H
