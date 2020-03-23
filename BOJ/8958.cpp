#include<stdio.h>

int main(void) {
	int n, sum = 0, cnt = 0, j = 0;
	char arr[81];
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%s", arr);

		while (arr[j]) {

			if (arr[j] == 'O') {
				arr[j] = 0;
				cnt++;
				sum += cnt;
			}
			else if (arr[j] == 'X') {
				arr[j] = 0;
				cnt = 0;
			}
			j++;

		}
		printf("%d\n", sum);

		sum = 0;
		j = 0;
		cnt = 0;
	}

	return 0;
}