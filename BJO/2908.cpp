#include<cstdio>
using namespace std;

int main() {
	int a, b;
	int n = 0;
	int m = 0;
	scanf("%d %d", &a, &b);
	for (int i = 100; i >= 1; i /= 10) {
		n += (a % 10) * i;
		m += (b % 10) * i;
		a /= 10;
		b /= 10;
	}
	(n > m) ? printf("%d\n", n) : printf("%d\n", m);

	return 0;
}