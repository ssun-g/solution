#include<stdio.h>
int n;

int fac(int);

int main() {
	scanf("%d", &n);
	printf("%d", fac(n));

	return 0;
}

int fac(int n) {
	if (n <= 1) {
		return 1;
	}

	return n*fac(n - 1);
}