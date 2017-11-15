
#include<stdio.h>

int main() {
	int n, i, j, dice[3], sum = 0, maxdice = 0, maxsum = -1;
	scanf("%d", &n);

	for (i = 0; i < n; i++) {
		for (j = 0; j < 3; j++) {
			scanf("%d", &dice[j]);

			if (maxdice < dice[j]) maxdice = dice[j];
		}

		if (dice[0] == dice[1] && dice[1] == dice[2])
			sum = 10000 + (dice[0] * 1000);
		else if (dice[0] == dice[1] || dice[0] == dice[2])
			sum = 1000 + (dice[0] * 100);
		else if (dice[1] == dice[2])
			sum = 1000 + (dice[1] * 100);
		else
			sum = 100 * maxdice;

		if (maxsum < sum) maxsum = sum;
		maxdice = 0;
	}
	printf("%d\n", maxsum);

	return 0;
}