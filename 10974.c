#include<stdio.h>

int arr[8], check[8], n;
void go(int);

int main() {
	scanf("%d", &n);
	go(0);
	return 0;
}

void go(int cnt) {
	if (cnt == n) {
		for (int i = 0; i < n; i++) {
			printf("%d ", arr[i]);
		}
		printf("\n");
		return;
	}

	for (int i = 0; i < n; i++) {
		if (!check[i]) {
			check[i] = 1;
			arr[cnt] = i + 1;
			go(cnt + 1);
			check[i] = 0;
			arr[cnt] = 0;
		}
	}
	return;
}