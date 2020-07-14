#include<cstdio>
#include<algorithm>
using namespace std;

int rope[100000];

bool comp(int a, int b) {
	return a > b;
}

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &rope[i]);
	}
	sort(rope, rope + n, comp);

	for (int i = 1; i < n; i++) {
		rope[i] = max(rope[i - 1], (i + 1)*rope[i]);
	}
	printf("%d\n", rope[n - 1]);

	return 0;
}