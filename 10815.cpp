#include<cstdio>
#include<algorithm>
#define MAX 500000
using namespace std;

int num[MAX];

int main() {
	int n, m, cmp, cnt = 0;
	int left;
	int right;
	int mid;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &num[i]);
	}
	sort(num, num + n);

	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		scanf("%d", &cmp);
		left = 0;
		right = n - 1;
		while (true) {
			mid = (left + right) / 2;
			if (left > right) {
				printf("0 ");
				break;
			}
			if (cmp == num[mid]) {
				if (i == m - 1) {
					printf("1");
					break;
				}

				printf("1 ");
				break;
			}
			else if (cmp > num[mid]) {
				left = mid + 1;
			}
			else {
				right = mid - 1;
			}
		}
		cnt++;
	}

	return 0;
}