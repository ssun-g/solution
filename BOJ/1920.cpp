#include<cstdio>
#include<algorithm>
#define MAX 100000
using namespace std;

int num[MAX], cmp[MAX];

int main() {
	int n, m, cnt = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &num[i]);
	}
	sort(num, num + n);

	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		scanf("%d", &cmp[i]);
	}

	int left;
	int right;
	int mid;

	for (int i = 0; i < m; i++) {
		left = 0;
		right = n - 1;
		while (true) {
			mid = (left + right) / 2;
			if (left > right) {
				printf("0\n");
				break;
			}
			if (cmp[cnt] == num[mid]) {
				printf("1\n");
				break;
			}
			else if (cmp[cnt] > num[mid]) {
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