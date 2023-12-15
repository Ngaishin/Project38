#include "mysales.h"
#include <iostream>

void runsales()
{
	using namespace SALES;

	sales s1, s2;
	double d[4]{ 123,2.4,5434,342.65 };

	std::cout << "s1 sales: \n";
	setsales(s1, d, 4);

	std::cout << "\n==============================\ns2 sales: \n";

	setsales(s2);

	std::cout << "\n==============================\ns1 show: \n";

	showsales(s1);
	std::cout << "\n==============================\ns2 show: \n";
	showsales(s2);
}

namespace SALES
{
	void setsales(sales& s, const double ar[], int n)
	{
		double total = 0;
		s.max = ar[0], s.min = ar[0];
		for (int i = 0; i < n; i++)
		{
			s.sales[i] = ar[i];
			total += ar[i];
			s.max = s.max > ar[i] ? s.max : ar[i];
			s.min = s.min < ar[i] ? s.min : ar[i];
		}
		s.average = total / n;
	}

	void setsales(sales& s)
	{
		double t, total = 0;
		using namespace std;

		cout << "season " << 1 << " : ";
		while (!(cin >> t))
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Try again: ";
		}
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		s.sales[0] = t;
		s.max =  t;
		s.min =  t;

		for (int i = 1; i < 4; i++)
		{
			cout << "season " << i + 1 << " : ";
			while (!(cin >> t))
			{
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "Try again: ";
			}
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			s.sales[i] = t;
			s.max = s.max > t ? s.max : t;
			s.min = s.min < t ? s.min : t;
			total += t;
		}
		s.average = total / 4;
	}

	void showsales(const sales& s)
	{
		using namespace std;
		cout << "four seasons sale --\n";
		for (int i = 0; i < 4; i++)
		{
			cout << s.sales[i] << ", ";
		}
		cout << "\naverage: " << s.average << endl;
		cout << "max: " << s.max << endl;
		cout << "min: " << s.min << endl;
	}
}
