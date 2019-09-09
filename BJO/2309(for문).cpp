#include<stdio.h>
#include<algorithm>
#include<iostream>

using namespace std;

int height[9], check[9], sum, temp, a, b;

int main() {
	for (int i = 0; i < 9; i++) {
		scanf("%d", &height[i]);
		sum += height[i];
	}
	temp = sum;
	sort(height, height + 9);

	for (int i = 0; i < 9; i++) {
		if (!check[i]) {
			check[i] = 1;
		}
		for (int j = 0; j < 9; j++) {
			if (!check[j]) {
				check[j] = 1;
			}

			if (sum - height[i] - height[j] == 100) {
				a = i;
				b = j;
			}
			check[i] = 0;
			check[j] = 0;
		}
	}

	for (int i = 0; i < 9; i++) {
		if (height[i] != height[a] && height[i] != height[b])
			printf("%d\n", height[i]);
	}

	return 0;
}
