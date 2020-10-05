#include<cstdio>
using namespace std;

int GCD(long long a, long long b) {
	if (b == 0) return a;
	return GCD(b, a%b);
}

int main() {
	long long a, b;
	scanf("%lld %lld", &a, &b);
	for (int i = 1; i <= GCD(a, b); i++) {
		printf("1");
	}

	return 0;
}