#include <stdio.h>

int main() {
	int a, b = 0, n;
	scanf("%d", &n);

	while (1) {
		if (n % 5 == 0) {
			printf("%d", ((n / 5) + b));
			break;
		}
		else if (n <= 0) {
			printf("-1");
			break;
		}
		n = n - 3;
		b++;
	}
	return 0;
}