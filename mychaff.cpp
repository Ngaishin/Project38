#include "mychaff.h"
#include <new>
#include <iostream>
#include <cstring>

void runchaff()
{
	using namespace std;
	cout << "Set buffer size : ";
	int size;
	while (!(cin >> size))
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Incorreect input!\nPlease enter integer: ";
	}
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	chaff* pbf = new chaff[size];

	chaff* pc = new (pbf) chaff[size];

	char dross[20];
	for (int i = 0; i < size; i++)
	{
		cout << "character " << i + 1 << " :\n";
		cout << "Dross: ";
		cin.getline(dross, 20);
		cout << "slag: ";
		while (!(cin >> pc[i].slag))
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Incorreect input!\nPlease enter integer: ";
		}
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		strcpy_s(pc[i].dross,20, dross);
	}

	for (int i = 0; i < size; i++)
	{
		cout << "character " << i + 1 << endl;
		cout << pc[i].dross << endl
			<< pc[i].slag << endl;
	}

	cout << "=================================\n";
	cout << "pbf address: " << (void*)pbf << endl;
	cout << "pc address: " << (void*)pc << endl;

	delete[]pbf;
}