#pragma once
#include <iostream>
namespace ImplementsStr {
	int ImplementsStr(std::string haystack, std::string needle) {
		int hycount = haystack.size();
		int ndcount = needle.size();
		for (size_t i = 0; ; i++)
		{
			for (size_t j = 0; ; j++)
			{
				if (j == ndcount)
				{
					return i;
				}
				if (i+j == hycount)
				{
					return -1;
				}
				if (needle.at(j) != haystack.at(i + j)) {
					break;
				}
			}
		}
	}
}

