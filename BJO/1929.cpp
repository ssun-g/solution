#include<cstdio>
#define ARR_MAX 1000001
using namespace std;

int arr[ARR_MAX];

int main() {
	int m, n;
	arr[0] = 1;
	arr[1] = 1;
	scanf("%d %d", &m, &n);
	for (int i = 2; i*i <= n; i++) {
		if (!arr[i]) {
			for (int j = i*i; j <= n; j += i) {
				arr[j] = 1;
			}
		}
	}
	for (int i = m; i <= n; i++) {
		if (!arr[i]) printf("%d\n", i);
	}

	return 0;
}