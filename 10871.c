#include<stdio.h>

int main() {
	int n, x, i = 0;
	int arr[10000];
	scanf("%d%d", &n, &x);
	while (i < n) {
		scanf("%d", &arr[i]);
		i++;
	}
	for (i = 0; i < n; i++) {
		if (arr[i] < x)
			printf("%d ", arr[i]);
	}

	return 0;
}