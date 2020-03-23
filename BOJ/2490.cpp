#include<stdio.h>

int main() {
	int arr[4], i, j, cnt = 0;

	for (i = 0; i < 3; i++) {
		for (j = 0; j < 4; j++) {
			scanf("%d", &arr[i]);

			if (arr[i] == 0) { cnt++; }
		}
		if (cnt == 1) {
			printf("A\n");
			cnt = 0;
		}
		else if (cnt == 2) {
			printf("B\n");
			cnt = 0;
		}
		else if (cnt == 3) {
			printf("C\n"); cnt = 0;
		}
		else if (cnt == 4) {
			printf("D\n"); cnt = 0;
		}
		else {
			printf("E\n"); cnt = 0;
		}
	}

	return 0;
}