#ifndef CSPLINE_H_
#define CSPLINE_H_

#include <iostream>
#include <vector>

using namespace std;

class CSpline {
public:
	CSpline(int, double *, double *);
	~CSpline();

	void solve();
	int getNrTotalPoints() const { return nrTotalPoints; }

	const vector<double>& getX() const { return x; }
	const vector<double>& getY() const { return y; }

private:
	int nrGivenPoints;
	int accuracy = 50;
	int nrTotalPoints = 0;
	double derivFactor = 1.5;

	vector<double> xi;
	vector<double> yi;
	vector<double> x1;
	vector<double> y1;

	void derivatives();
	vector<double> x;
	vector<double> y;

};

#endif /* CSPLINE_H_ */
