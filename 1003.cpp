#include<stdio.h>

#define MAX 41

int cnt0 = 0, cnt1 = 0;
int fibo[MAX];
void fibonacci(int);

int main() {
	int n;
	fibo[0] = 0;
	fibo[1] = 1;

	scanf("%d", &n);

	for (int i = 2; i < MAX; i++)
		fibo[i] = fibo[i - 1] + fibo[i - 2];

	for (int i = 0; i < n; i++) {
		int num;
		scanf("%d", &num);

		fibonacci(num);

		printf("%d %d\n", cnt0, cnt1);
	}
	return 0;
}

void fibonacci(int n) {
	if (n == 0)
		cnt0 = 1;
	else {
		cnt0 = fibo[n - 1];
		cnt1 = fibo[n];
	}
}
