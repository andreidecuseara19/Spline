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

	int pos = read(5.24, xi, yi, nTotal);
	double interpolated = yi[pos];
	cout << interpolated << endl;

	double dy, dx;
	dy = yi[pos + 1] - yi[pos];
	dx = xi[pos + 1] - xi[pos];
	double derivated = dy / dx;
	cout << derivated << endl;
	//derivata se face scazand cele mai apropiate doua puncte x si facand Dy/Dx

	delete pS;

	return 0;
}