#include<cstdio>
using namespace std;

int main() {
	int n, q;
	long long sum = 0;
	int check[100001] = { 0, };
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int a;
		scanf("%d", &a);
		sum += a;
		check[a]++;
	}

	scanf("%d", &q);
	for (int i = 0; i < q; i++) {
		int b, c;
		scanf("%d %d", &b, &c);
		sum -= (long long)check[b] * b;
		sum += (long long)check[b] * c;
		check[c] += check[b];
		check[b] = 0;
		printf("%lld\n", sum);
	}

	return 0;
}