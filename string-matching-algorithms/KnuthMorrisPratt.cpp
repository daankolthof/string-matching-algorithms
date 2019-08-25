#include "KnuthMorrisPratt.h"

int KnuthMorrisPratt::findString(const std::string& string, const std::string& pattern)
{
	size_t i = 0;
	int j = 0;

	build_table(pattern);

	while (i < string.length())
	{
		if (pattern[j] == string[i])
		{
			++i;
			++j;

			if (pattern.length() == static_cast<unsigned int>(j))
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

void KnuthMorrisPratt::build_table(const std::string& pattern)
{
	if (pattern.length() + 1 != table.size())
	{
		table.resize(pattern.length() + 1);
	}

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

std::vector<int> KnuthMorrisPratt::table;
