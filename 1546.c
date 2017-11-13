#include<stdio.h>

int main() {
	int n;
	double Max = 0, sum = 0;
	double arr[1000];
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%lf", &arr[i]);
	}
	for (int i = 0; i < n; i++) {
		if (Max < arr[i])
			Max = arr[i];
	}
	for (int i = 0; i < n; i++) {
		sum += (arr[i] / Max) * 100.00;
	}
	printf("%.2f", sum / n);
	return 0;
}