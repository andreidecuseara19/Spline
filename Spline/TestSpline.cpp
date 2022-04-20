#include "CSpline.h"

int main(){
	double x[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	double y[] = {9, 8, 5, 8, 4, 6, 2, 3, 5, 1};

	int n = sizeof(x) / sizeof(double);

	double * pX = x;
	double * pY = y;
	CSpline * pS = new CSpline(n, pX, pY);

	pS ->solve();
	int nTotal = pS->getNrTotalPoints();
	vector<double> xi = pS->getX();
	vector<double> yi = pS->getY();


	for(int i = 0; i < nTotal; i++){
		cout << xi[i] << "\t" << yi[i] << endl;
	}

	delete pS;

	return 0;
}
