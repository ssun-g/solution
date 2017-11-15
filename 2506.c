#include<stdio.h>
#include<string.h>

int main() {
	int arr[100], cnt = 0, sum = 0, i, j, n;
	scanf("%d", &n);

	for (i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}

	if (arr[0] == 1) {
		cnt++;
		sum += cnt;
	}

	for (j = 1; j < n; j++) {
		if (arr[j] == 1) {
			cnt++;
		}

		else {
			cnt = 0;
		}
		sum += cnt;
	}
	printf("%d\n", sum);

	return 0;
}