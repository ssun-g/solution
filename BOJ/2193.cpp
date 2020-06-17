#include<cstdio>
using namespace std;

long long arr[91];

int main() {
	int n;
	arr[1] = 1;
	arr[2] = 1;
	scanf("%d", &n);
	for (int i = 3; i <= n; i++) {
		arr[i] = arr[i - 1] + arr[i - 2];
	}
	printf("%lld\n", arr[n]);

	return 0;
}