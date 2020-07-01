#include<cstdio>
using namespace std;

int gcd(int a, int b) {
	if (a == 0) return b;
	return gcd(b%a, a);
}

int main() {
	int tc;
	scanf("%d", &tc);
	for (int i = 0; i < tc; i++) {
		int a, b, G;
		scanf("%d %d", &a, &b);
		if (a > b) G = gcd(b, a);
		else G = gcd(a, b);
		printf("%d\n", (a / G)*(b / G)*G);
	}

	return 0;
}