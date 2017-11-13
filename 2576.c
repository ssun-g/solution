#include<stdio.h>

int main(void) {
	int num, i, sum = 0, min = 101;

	for (i = 0; i < 7; i++) {
		scanf("%d", &num);
		if (num % 2) {
			sum += num;
			if (min > num)
				min = num;
		}
	}

	if (sum == 0)
		printf("-1\n");

	else {
		printf("%d\n", sum);
		printf("%d\n", min);
	}

	return 0;
}