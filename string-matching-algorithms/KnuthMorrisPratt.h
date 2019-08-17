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
	static int findString(const std::string& string, const std::string& pattern)
	{
		size_t i = 0;
		int j = 0;

		std::vector<int> table(pattern.length()+1);
		build_table(pattern, table);

		while (i < string.length())
		{
			if (pattern[j] == string[i])
			{
				++i;
				++j;

				if (pattern.length() == j)
				{
					// Found pattern in input string, return index within the string.
					return i - j;
				}
			}
			else
			{
				j = table[j];
				if (j < 0)
				{
					++i;
					++j;
				}
			}
		}

		// Pattern was not found.
		return -1;
	}

private:
	/* Builds the table to use during string matching.
	*/
	static void build_table(const std::string& pattern, std::vector<int>& table)
	{
		size_t pos = 1;
		int cnd = 0;

		table[0] = -1;

		while (pos < pattern.length())
		{
			if (pattern[pos] == pattern[cnd])
			{
				table[pos] = table[cnd];
			}
			else
			{
				table[pos] = cnd;
				cnd = table[cnd];

				while (cnd >= 0 && pattern[pos] != table[cnd])
				{
					cnd = table[cnd];
				}
			}

			++pos;
			++cnd;
		}

		table[pos] = cnd;
	}


};

#endif //KNUTH_MORRIS_PRATT_H
