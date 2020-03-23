#include<stdio.h>

int main() {
	int c, sum = 0, cnt = 0;
	double avg = 0;
	int arr[1001];

	scanf("%d", &c);
	for (int i = 0; i < c; i++) {
		scanf("%d", &arr[0]);
		for (int j = 0; j < arr[0]; j++) {
			scanf("%d", &arr[j + 1]);
		}
		for (int k = 0; k < arr[0]; k++) {
			sum += arr[k + 1];
		}
		avg = sum / arr[0];
		for (int l = 1; l <= arr[0]; l++) {
			if (avg < arr[l])
				cnt++;
		}
		double out = (double)cnt / (double)arr[0] * 100;
		printf("%.3f%%\n", out);
		cnt = 0;
		sum = 0;
	}

	return 0;
}