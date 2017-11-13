#include<stdio.h>

int main() {
	int a, mul = 1, num[10] = { 0 };

	for (int i = 0; i < 3; i++) {
		scanf("%d", &a);
		mul *= a;
	}

	while (mul > 0) {
		num[mul % 10]++;
		mul /= 10;
	}

	for (int j = 0; j < 10; j++)
		printf("%d\n", num[j]);
	return 0;
}