#include <iostream>
#include <cstring>
#include <cctype>
#include "golf.h"

void rungolf()
{
	using std::cout;
	using std::cin;

	cout << "Enter size of list: ";
	int len;
	while (!(cin >> len))
	{
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		cout << "Please enter integer: ";
	}
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	golf* g = new golf[len];
	int i = 0;

	for (; (i < len) and (setgolf(g[i])); i++);


	/*char name[40];
	int handicap;
	for (; i < len; i++)
	{
		cout << "Name: ";
		cin.getline(name, 40);
		int cnt = 0;
		for (int i = 0; i < strlen(name); i++)
		{
			if (isgraph(name[i]))
				cnt++;
		}
		if (!cnt)
			break;

		cout << "handicap: ";
		while (!(cin >> handicap))
		{
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << "Please enter integer: ";
		}
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

		setgolf(g[i], name, handicap);
	}*/

	cout << "++++++++++++++++++++++++++++++++++++\n"
		<< "++++++++++++++++++++++++++++++++++++\n";

	for (int j = 0; j < i; j++)
	{
		cout << "====================\n";
		showgolf(g[j]);
		cout << "====================\n";
	}

	delete[] g;
}

void setgolf(golf& g, const char* name, int hc)
{
	strcpy_s(g.fullname, 40, name);
	g.handicap = hc;
}

int setgolf(golf& g)
{
	using std::cout;
	using std::cin;

	char name[40];
	cout << "Name: ";
	cin.getline(name, 40);

	int cnt = 0;
	for (int i = 0; i < strlen(name); i++)
	{
		if (isgraph(name[i]))
			cnt++;
	}
	if (!cnt)
		return 0;

	int handicap;
	cout << "handicap: ";
	while (!(cin >> handicap))
	{
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		cout << "Please enter integer: ";
	}

	setgolf(g, name, handicap);
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	return 1;
}

void handicap(golf& g, int hc)
{
	g.handicap = hc;
}

void showgolf(const golf& g)
{
	std::cout << "Name    : " << g.fullname << '\n'
			  << "Handicap: " << g.handicap << std::endl;
}