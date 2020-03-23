#include<stdio.h>

int main() {
	int n, sum = 0;
	char N[100];
	scanf("%d", &n);
	scanf("%s", N);
	for (int i = 0; i < n; i++) {
		sum += N[i] - '0';
	}
	printf("%d", sum);
	return 0;
}