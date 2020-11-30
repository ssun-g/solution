#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

double X[100];
double Y[100];
vector<double> vx;
vector<double> vy;
map<double, int> mX;
map<double, int> mY;

int main() {
	double n;
	scanf("%lf", &n);
	for (int i = 0; i < n; i++) {
		scanf("%lf", &X[i]);
		vx.push_back(X[i]);
	}

	for (int i = 0; i < n; i++) {
		scanf("%lf", &Y[i]);
		vy.push_back(Y[i]);
	}
	sort(vx.begin(), vx.end());
	sort(vy.begin(), vy.end());

	for (int i = 0; i < n; i++) {
		mX.insert(make_pair(vx[i], i + 1));
		mY.insert(make_pair(vy[i], i + 1));
	}

	double d = 0.0;
	for (int i = 0; i < n; i++) {
		auto itx = mX.find(X[i]);
		auto ity = mY.find(Y[i]);
		d += pow(itx->second - ity->second, 2);
	}
	printf("%.3f\n", 1 - ((6 * d) / (n*(n*n - 1))));

	return 0;
}
