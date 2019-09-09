#include<stdio.h>

int main() {
	int N;
	scanf("%d", &N);

	for (int a = 0; a < N; a++) {
		for (int b = 0; b <= a; b++)
			printf("*");
		printf("\n");
	}

	return 0;
}