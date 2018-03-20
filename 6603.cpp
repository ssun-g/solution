#include<stdio.h>

int temp[13], arr[13], n;
void Comb(int, int);

int main() {
	while (1) {
		scanf("%d", &n);
		if (!n)
			break;

		for (int i = 0; i < n; i++) {
			scanf("%d", &arr[i]);
		}
		Comb(0, 0);
		printf("\n");
	}
	return 0;
}

void Comb(int init, int cnt) {
	if (cnt == 6) {
		for (int i = 0; i < 6; i++)
			printf("%d ", temp[i]);

		printf("\n");
		return;
	}

	for (int i = init; i < n; i++) {
		temp[cnt] = arr[i];
		Comb(i + 1, cnt + 1);
	}

	return;
}