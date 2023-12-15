#include "mystatic.h"
#include <cctype>
#include <string>

void runstrcount()
{
	using namespace std;
	string str;
	cout << "enter string: ";
	while ((getline(cin, str)) && !str.empty())
	{
		strcount(str);
		cout << "next: ";
	}
	cout << "Bye!";

}

void strcount(const std::string str)
{
	using namespace std;
	static int total = 0;
	int count = 0;
	cout << '\"' << str << '\"' << "contains ";
	for (const char& ch : str)
	{
		if (isgraph(ch))
			count++;
	}
	total += count;
	cout << count << " characters\n";
	cout << total << " characters total.\n";

}