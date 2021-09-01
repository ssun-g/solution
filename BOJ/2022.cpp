#include <bits/stdc++.h>
using namespace std;

double x, y, c;

double calc_height(double h) {
	double h1 = sqrt(x * x - h * h);
	double h2 = sqrt(y * y - h * h);
	double ret = (h1 * h2) / (h1 + h2);

	return round(ret * 1000) / 1000;
}

int main() {
	cin >> x >> y >> c;

	double left = 0.0;
	double right = min(x, y);
	double mid;
	while (abs(right - left) >= 1e-6) {
		mid = (left + right) / 2.0;
		double height = calc_height(mid);

		if (height < c) right = mid; // 주어진 높이보다 낮으면 빌딩 사이의 거리를 좁혀야 함
		else left = mid; // 주어진 높이보다 높으면 빌딩 사이의 거리를 늘림
	}


	// 소수점 셋째자리까지 출력
	cout << fixed;
	cout.precision(3);
	cout << mid << '\n';

	return 0;
}