#include<stdio.h>

int main() {
	int arr[10000], i, n, k, cnt = 0, arrNum = 0;
	scanf("%d%d", &n, &k);

	for (i = 1; i <= n; i++) {
		if (n%i == 0) {
			arr[arrNum++] = i;
		}
	}

	for (i = 1; i <= arrNum; i++) {
		if (k == i) {
			printf("%d\n", arr[k - 1]);
			cnt++;
		}
	}
	if (cnt == 0) printf("0\n");

	return 0;
}