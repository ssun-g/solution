#include<stdio.h>

int main(void) {
	int i, j, m, n, cnt = 0, sum = 0, min = 10001;
	scanf("%d%d", &m, &n);

	for (i = m; i <= n; i++) {
		for (j = 1; j <= i; j++) {
			if (i%j == 0)
				cnt++;
		}

		if (cnt == 2) {
			sum += i;
			cnt = 0;

			if (min > i)
				min = i;
		}
		cnt = 0;
	}
	if (sum == 0 && cnt != 2)
		printf("-1\n");

	else {
		printf("%d\n", sum);
		printf("%d\n", min);
	}

	return 0;
}