#include <stdio.h>

int han(int);
char arr[4];

int main(void) {
	int num;
	scanf("%d", &num);
	printf("%d\n", han(num));

	return 0;
}

int han(int num) {
	if (num < 100)
		return num;

	else {
		int a, b, c, i, cnt = 0;

		for (i = 100; i <= num; i++) {
			a = i / 100;
			b = ((i / 10) % 10);
			c = i % 10;

			if ((b - a) == (c - b))
				cnt++;
		}

		return cnt + 99;
	}
}