#include<cstdio>
#include<algorithm>
#define MAX 1000000
using namespace std;

int arr[MAX], cmp[MAX];
int Max;

int main() {
	int t, n, cnt = 0;
	int left, right, mid;
	scanf("%d", &t);
	for (int i = 0; i < t; i++) {
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			scanf("%d", &cmp[i]);
		}
		sort(cmp, cmp + n);
		for (int i = 0; i < n; i++) {
			scanf("%d", &arr[i]);
		}

		left = 0;
		right = n - 1;

		while (cnt < n) {
			left = 0;
			right = n - 1;
			bool flag = true;
			for (int i = 0; i < n; i++) {
				mid = (left + right) / 2;
				if (arr[cnt] == cmp[mid]) {
					cnt++;
					flag = false;
					break;
				}
				else if (arr[cnt] > cmp[mid]) {
					left = mid + 1;
				}
				else {
					right = mid - 1;
				}
			}
			if (flag) {
				printf("%d ", arr[cnt]);
				cnt++;
			}
			else if (!flag && cnt == n - 1) printf("0");
		}
		printf("\n");
		cnt = 0;
	}

	return 0;
}