#include<stdio.h>

int arr[10035];
void selfNum();

int main(void) {
	selfNum();

	return 0;
}

void selfNum() {
	int temp, temp2, i, a;
	for (a = 1; a < 10000; a++) {
		if (a > 0 && a < 10)
			arr[a + a] = 1;

		else if (a >= 10 && a < 100)
			arr[a + (a / 10) + (a % 10)] = 1;

		else if (a >= 100 && a < 1000) {
			temp = a / 10;
			arr[a + (a / 100) + (temp % 10) + a % 10] = 1;
		}

		else if (a >= 1000 && a < 10000) {
			temp = a / 100;
			temp2 = a / 10;
			arr[a + (a / 1000) + (temp % 10) + (temp2 % 10) + a % 10] = 1;
		}
	}

	for (i = 1; i < 10000; i++) {
		if (!arr[i])
			printf("%d\n", i);
	}
}