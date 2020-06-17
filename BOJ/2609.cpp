#include<cstdio>
#include<algorithm>
using namespace std;

int GCD(int a, int b) {
	if (b == 0) return a;
	if (a > b) swap(a, b);
	return GCD(a, b%a);
}

int main() {
	int n, m;
	scanf("%d %d", &n, &m);

	int g = GCD(n, m);
	printf("%d\n%d\n", g, g * (n / g)  * (m / g));

	return 0;
}