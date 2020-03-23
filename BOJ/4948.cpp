#include<cstdio>
using namespace std;

int arr[300000];

int main() {
	arr[0] = 1;
	arr[1] = 1;
	for (int i = 2; i*i <= 300000; i++) {
		if (!arr[i]) {
			for (int j = i*i; j <= 300000; j += i) {
				arr[j] = 1;
			}
		}
	}
	while (true) {
		int n;
		int cnt = 0;
		scanf("%d", &n);
		if (n == 0) break;
		for (int i = n + 1; i <= 2 * n; i++) {
			if (!arr[i]) cnt++;
		}
		printf("%d\n", cnt);
	}

	return 0;
}