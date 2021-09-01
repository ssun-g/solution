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

		if (height < c) right = mid; // �־��� ���̺��� ������ ���� ������ �Ÿ��� ������ ��
		else left = mid; // �־��� ���̺��� ������ ���� ������ �Ÿ��� �ø�
	}


	// �Ҽ��� ��°�ڸ����� ���
	cout << fixed;
	cout.precision(3);
	cout << mid << '\n';

	return 0;
}