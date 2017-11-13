#include<stdio.h>

int main() {
	int num;
	long long int fibo[91];
	fibo[0] = 0;
	fibo[1] = 1;

	scanf("%d", &num);

	for (int i = 2; i <= num; i++)
		fibo[i] = fibo[i - 1] + fibo[i - 2];

	printf("%lld\n", fibo[num]);

	return 0;
}
