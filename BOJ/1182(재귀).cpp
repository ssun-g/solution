#include<stdio.h>

int n, s, check[20], subs[20], num;
int go(int, int, int);

int main() {
	scanf("%d%d", &n, &s);
	if (!s)
		num--;

	for (int i = 0; i < n; i++) {
		scanf("%d", &subs[i]);
	}
	go(0, 0, 0);
	printf("%d", num);

	return 0;
}

int go(int init, int sum, int cnt) {
	if (sum == s)
		num++;

	for (int i = init; i < n; i++) {
		if (!check[i]) {
			check[i] = 1;
			go(i + 1, sum + subs[i], cnt++);
			check[i] = 0;
		}
	}

	return 0;
}