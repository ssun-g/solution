#include<stdio.h>
#include<algorithm>
#include<iostream>
using namespace std;

int height[10], check[10];
int go(int, int, int);

int main() {
	for (int i = 0; i < 9; i++) {
		scanf("%d", &height[i]);
	}
	sort(height, height + 9);
	go(0, 0, 0);

	return 0;
}

int go(int cnt, int sum, int here) {
	if (cnt == 7 && sum == 100) {
		for (int i = 0; i < 9; i++) {
			if (check[i])
				printf("%d\n", height[i]);
		}
		return 1;
	}
	else if (cnt >= 7 || sum >= 100)
		return 0;

	for (int i = here; i < 9; i++) {
		if (!check[i]) {
			check[i] = 1;
			if (go(cnt + 1, sum + height[i], i + 1))
				return 1;
			check[i] = 0;
		}
	}
	return 0;
}
