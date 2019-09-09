#include<cstdio>
using namespace std;

long long arr[101];

int main() {
	int t;
	arr[0] = 1;
	arr[1] = 1;
	arr[2] = 1;
	scanf("%d", &t);
	for (int i = 0; i < t; i++) {
		int n;
		scanf("%d", &n);
		for (int j = 3; j < n; j++) {
			arr[j] = arr[j - 2] + arr[j - 3];
		}
		printf("%lld\n", arr[n - 1]);
	}

	return 0;
}