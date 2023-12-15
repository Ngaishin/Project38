#ifndef MYSALES_H_
#define MYSALES_H_

void runsales();


namespace SALES
{
	const int QUARTERS = 4;
	struct sales
	{
		double sales[QUARTERS];
		double max;
		double min;
		double average;
	};
	void setsales(sales& s, const double ar[], int n=4);
	void setsales(sales& s);
	void showsales(const sales& s);
}
#endif // !MYSALES_H_
