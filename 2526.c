#include<stdio.h>

int main(void) {
	int n, p, temp, arr[100];
	int  i = 0;
	scanf("%d%d", &n, &p);

	temp = n;
	arr[i++] = n;

	while (1) {
		temp = (temp * n) % p;

		for (int j = 0; j < i; j++) {
			if (arr[j] == temp) {
				printf("%d\n", i - j);
				return 0;
			}
		}
		arr[i++] = temp;
	}

	return 0;
}