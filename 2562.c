#include<stdio.h>

int main(void) {
	int num[9], i, cnt = 1, max = 0;

	for (i = 0; i < 9; i++) {
		scanf("%d", &num[i]);

		if (max < num[i])
			max = num[i];
	}

	for (i = 0; i < 9; i++) {
		if (max != num[i]) {
			cnt++;
		}
		else break;
	}
	printf("%d\n", max);
	printf("%d\n", cnt);

	return 0;
}