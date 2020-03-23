#include<stdio.h>

int n, s, cnt, subs[21];

int main() {
	scanf("%d%d", &n, &s);
	for (int i = 0; i < n; i++) {
		scanf("%d", &subs[i]);
	}

	for (int i = 1; i < (1 << n); i++) {
		int sum = 0;
		for (int j = 0; j < n; j++) {
			if (i & (1 << j)) {
				sum += subs[j];
			}
		}
		if (s == sum)
			cnt++;
	}
	printf("%d", cnt);

	return 0;
}