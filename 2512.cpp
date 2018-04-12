#include<cstdio>
using namespace std;

int arr[10000];
int Max;

int main() {
	int left, right, mid, n, m, sum = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
		if (arr[i] > Max)
			Max = arr[i];
	}
	scanf("%d", &m);

	left = 0;
	right = Max;
	mid = (left + right) / 2;

	while (left <= right) {
		sum = 0;
		mid = (left + right) / 2;
		for (int i = 0; i < n; i++) {
			if (arr[i] > mid)
				sum += mid;
			else
				sum += arr[i];
		}
		if (sum > m) {
			right = mid - 1;
		}
		else {
			left = mid + 1;
		}
	}
	printf("%d\n", right);

	return 0;
}