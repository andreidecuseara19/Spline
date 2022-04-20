#include "CSpline.h"
#include <math.h>

using namespace std;

CSpline::CSpline(int nr, double * pX, double * pY) {
	this ->nrGivenPoints = nr;
	for(int i = 0; i < nrGivenPoints; i++){
		xi.push_back(*(pX + i));
		yi.push_back(*(pY + i));
	}
	nrTotalPoints = (nr - 1) * accuracy;
}

CSpline::~CSpline() {

}


void CSpline::derivatives(){
	for(int i = 0; i < nrGivenPoints; i++){
		double alpha = 0;
		if((i > 0) && (i < (nrGivenPoints - 1))){
			double a1 = atan2((yi[i+1] - yi[i]), (xi[i+1] - xi[i]));
			double a2 = atan2((yi[i] - yi[i-1]), (xi[i] - xi[i-1]));
			alpha = (a1 + a2) / 2;
		}
		double xprim = derivFactor * cos(alpha);
		double yprim = derivFactor * sin(alpha);

		x1.push_back(xprim);
		y1.push_back(yprim);
	}
}

void CSpline::solve(){
	double m2[4][4] = {   {2, -3, 0, 1}
						, {-2, 3, 0, 0}
						, {1, -2, 1, 0}
						, {1, -1, 0, 0}};
	derivatives();
	for(int i = 0; i < nrGivenPoints - 1; i++){
		double m1x[4] = {xi[i], xi[i+1], x1[i], x1[i+1]};
		double m1y[4] = {yi[i], yi[i+1], y1[i], y1[i+1]};
		for(int j = 0; j < accuracy; j++){
			double t = (double)j / accuracy;
			double m3[4] = {t*t*t, t*t, t, 1};
			double m23[4];
			for(int k = 0; k < 4; k++){
				m23[k] = 0;
				for(int l = 0; l < 4; l++){
					m23[k] += m2[k][l] * m3[l];
				}
			}
			double xp = 0;
			double yp = 0;
			for(int k = 0; k < 4; k++){
				xp += m1x[k] * m23[k];
				yp += m1y[k] * m23[k];
			}

			x.push_back(xp);
			y.push_back(yp);
		}
	}
}

