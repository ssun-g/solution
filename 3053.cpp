#define _USE_MATH_DEFINES
#include<cstdio>
#include<cmath>
using namespace std;

int main() {
	double r;
	scanf("%lf", &r);
	printf("%.6f\n", M_PI * r * r);
	printf("%.6f\n", r * r * 2);

	return 0;
}