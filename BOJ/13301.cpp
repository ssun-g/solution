#include<cstdio>
#include<algorithm>
using namespace std;

long long arr[81];

int main() {
	int n;
	arr[0] = 1;
	arr[1] = 1;
	scanf("%d", &n);
	for (int i = 2; i < n + 1; i++) {
		arr[i] = arr[i - 1] + arr[i - 2];
	}

	printf("%lld\n", (arr[n] * 2) + (arr[n - 1] * 2));

	return 0;
}