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
	static int findString(const std::string& string, const std::string& pattern)
	{
		const int pattern_hash = calculateHash(pattern);
		int current_substring_hash = calculateHash(string.substr(0, pattern.length()));
		
		// The offset of the leftmost character in a rolling hash, used for rolling hash calculation later.
		uint8_t offset_left_char = 1;
		for (size_t i = 0; i < pattern.length() - 1; i++)
		{
			offset_left_char = (offset_left_char * 256) % 101;
		}
		
		for (size_t i = 0; i <= string.length() - pattern.length(); i++)
		{
			// Check if the pattern hash equals the hash of the current substring to check.
			if (pattern_hash == current_substring_hash)
			{
				// Hashes match, compare actual strings.
				bool actual_match = true;
				for (size_t j = 0; actual_match && j < pattern.length(); j++)
				{
					if (pattern[j] != string[i + j])
					{
						// Strings to do not match, set the flag to false so the searching will continue.
						actual_match = false;
					}
				}

				if (actual_match)
				{
					return i;
				}
			}

			// No match found, update the rolling hash value.
			// Do not update if the end of the string is reached (one more check if still being done in the next iteration of this function).
			if (i < string.length() - pattern.length())
			{
				current_substring_hash = calculateRollingHash(current_substring_hash, string[i], string[i + pattern.length()], offset_left_char);
			}
		}

		// Pattern was not found.
		return -1;
	}

public:
	/* Calculates the hash based on the input string, only used for
	* pattern and the first characters of the string to search in.
	*/
	static int calculateHash(const std::string& string)
	{
		int result_hash = 0;

		for (const char c : string)
		{
			result_hash = (result_hash * 256 + c) % HASH_MODULUS;
		}

		return result_hash;
	}

	static int calculateRollingHash(const uint8_t previous_hash, const char old_char, const char new_char, const uint8_t offset_left_char)
	{
		int result = ((previous_hash - old_char * offset_left_char) * 256 + new_char) % HASH_MODULUS;

		// Because of the modulus operator, the result might be negative, if so, add HASH_MODULUS to it.
		if (result < 0)
		{
			result += HASH_MODULUS;
		}

		return result;
	}

};

#endif //RABIN_KARP_H
