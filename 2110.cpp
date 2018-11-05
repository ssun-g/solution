#include<cstdio>
#include<algorithm>
using namespace std;

void wifi(int);

int arr[100000];
int n, k, ans, dist, cnt;

int main() {
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	sort(arr, arr + n);
	wifi(k);

	return 0;
}

void wifi(int num) {
	if (num == 2) {
		printf("%d\n", arr[n - 1] - arr[0]);
		return;
	}
	int left = 1;
	int right = arr[n-1] - arr[0];
	int mid = (left + right) / 2;

	while (left <= right) {
		int start = arr[0];
		cnt = 1;
		mid = (left + right) / 2; 
		for (int i = 1; i < n; i++) {
			dist = arr[i] - start;
			if (mid <= dist) {
				cnt++;
				start = arr[i];
			}
		}
		if (cnt >= k) {
			ans = mid;
			left = mid + 1;
		}
		else right = mid - 1;
	}
	printf("%d\n", ans);
}