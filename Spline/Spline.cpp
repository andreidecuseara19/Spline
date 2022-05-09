#include <iostream>
#include <math.h>
#include "CSpline.h"


int read(double val, vector<double> xi, vector<double> yi, int nTotal)
{
	double mindiff = 1;
	int pos;
	for (int i = 0; i < nTotal; i++) {
		if (abs(val - xi[i]) < mindiff)
		{
			mindiff = abs(val - xi[i]);
			pos = i;
		}
	}
	return pos;
}


int main() {
	double x[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	double y[] = { 5, 1, 3, 9, 9, 7, 8, 9, 5, 1 };

	int n = sizeof(x) / sizeof(double);

	double* pX = x;
	double* pY = y;
	CSpline* pS = new CSpline(n, pX, pY);

	pS->solve();
	int nTotal = pS->getNrTotalPoints();
	vector<double> xi = pS->getX();
	vector<double> yi = pS->getY();


	for (int i = 0; i < nTotal; i++) {
		cout << xi[i] << "\t" << yi[i] << endl;
	}

	double value;
	int pos;
	double interpolated;

	double dy, dx;
	double derivated;

	value = 1.75;
	pos = read(value, xi, yi, nTotal);
	interpolated = yi[pos];
	cout << "\nInterpolated value for " << value << " is: " << interpolated << endl;

	dy = yi[pos + 1] - yi[pos];
	dx = xi[pos + 1] - xi[pos];
	derivated = dy / dx;
	cout << "Derivated value for " << value << " is: " << derivated << endl;
	//derivata se face scazand cele mai apropiate doua puncte x si facand Dy/Dx

	value = 3.15;
	pos = read(value, xi, yi, nTotal);
	interpolated = yi[pos];
	cout << "\nInterpolated value for " << value << " is: " << interpolated << endl;

	dy = yi[pos + 1] - yi[pos];
	dx = xi[pos + 1] - xi[pos];
	derivated = dy / dx;
	cout << "Derivated value for " << value << " is: " << derivated << endl;
	//derivata se face scazand cele mai apropiate doua puncte x si facand Dy/Dx

	value = 5.24;
	pos = read(value, xi, yi, nTotal);
	interpolated = yi[pos];
	cout << "\nInterpolated value for " << value << " is: " << interpolated << endl;

	dy = yi[pos + 1] - yi[pos];
	dx = xi[pos + 1] - xi[pos];
	derivated = dy / dx;
	cout << "Derivated value for " << value << " is: " << derivated << endl;
	//derivata se face scazand cele mai apropiate doua puncte x si facand Dy/Dx

	value = 7.8;
	pos = read(value, xi, yi, nTotal);
	interpolated = yi[pos];
	cout << "\nInterpolated value for " << value << " is: " << interpolated << endl;

	dy = yi[pos + 1] - yi[pos];
	dx = xi[pos + 1] - xi[pos];
	derivated = dy / dx;
	cout << "Derivated value for " << value << " is: " << derivated << endl;
	//derivata se face scazand cele mai apropiate doua puncte x si facand Dy/Dx

	value = 9.12;
	pos = read(value, xi, yi, nTotal);
	interpolated = yi[pos];
	cout << "\nInterpolated value for " << value << " is: " << interpolated << endl;

	dy = yi[pos + 1] - yi[pos];
	dx = xi[pos + 1] - xi[pos];
	derivated = dy / dx;
	cout << "Derivated value for " << value << " is: " << derivated << endl;
	//derivata se face scazand cele mai apropiate doua puncte x si facand Dy/Dx

	delete pS;

	return 0;
}