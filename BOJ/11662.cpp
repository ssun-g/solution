#include<cstdio>
#include<cmath>
#include<utility>
#include<algorithm>
using namespace std;

pair<double, double> mmove1, mmove2, kmove1, kmove2;
int ax, ay, bx, by, cx, cy, dx, dy;

pair<double, double> minho(double t) {
	return make_pair(ax + (bx - ax)*(t / 100), ay + (by - ay)*(t / 100));
}

pair<double, double> kang(double t) {
	return make_pair(cx + (dx - cx)*(t / 100), cy + (dy - cy)*(t / 100));
}

int main() {
	double answer = 100000000;
	scanf("%d %d %d %d %d %d %d %d", &ax, &ay, &bx, &by, &cx, &cy, &dx, &dy);

	double left = 0.0;
	double right = 100.0;
	double ter1, ter2;
	while (right - left >= 1e-6) {
		ter1 = (2 * left + right) / 3;
		ter2 = (left + 2 * right) / 3;

		mmove1 = minho(ter1);
		mmove2 = minho(ter2);
		kmove1 = kang(ter1);
		kmove2 = kang(ter2);

		double length1 = sqrt(pow(mmove1.first - kmove1.first, 2) + pow(mmove1.second - kmove1.second, 2));
		double length2 = sqrt(pow(mmove2.first - kmove2.first, 2) + pow(mmove2.second - kmove2.second, 2));
		answer = min(answer, min(length1, length2));

		if (length1 <= length2) right = ter2;
		else left = ter1;
	}
	printf("%f", answer);

	return 0;
}