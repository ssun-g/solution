#include<stdio.h>

int main() {
	int a, b, c, n, num, cnt = 0;
	scanf("%d", &n);

	num = n;
	do {
		a = num / 10;
		b = num % 10;
		c = (a + b) % 10;
		a = b;
		b = c;
		num = a * 10 + b;
		cnt++;
	} while (num != n);

	printf("%d", cnt);
	return 0;
}