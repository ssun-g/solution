#include<stdio.h>

int count(int);
void move(int from, int to);
void hanoi(int n, int from, int by, int to);

int main(void) {
	int n;
	scanf("%d", &n);
	printf("%d\n", count(n));
	hanoi(n, 1, 2, 3);

	return 0;
}

int count(int num) {
	int d = 1;
	if (num == 1) return 1;
	else {
		for (int i = 1; i <= num; i++)
			d *= 2;
		return d - 1;
	}
}

void move(int from, int to) {
	printf("%d %d\n", from, to);
}

void hanoi(int n, int from, int by, int to) {
	if (n == 1)
		move(from, to);
	else {
		hanoi(n - 1, from, to, by);
		move(from, to);
		hanoi(n - 1, by, from, to);
	}
}