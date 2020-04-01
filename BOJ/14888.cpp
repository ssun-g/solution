#include<cstdio>
#include<algorithm>
using namespace std;

int n;
int arr[11];
int check[4];
int MAX = -1000000001;
int MIN = 1000000001;

void dfs(int idx, int sum) {
	if (idx == n) {
		MIN = min(MIN, sum);
		MAX = max(MAX, sum);
		return;
	}

	for (int i = 0; i < 4; i++) {
		switch (i) {
		case 0:
			if (check[i]) {
				check[i]--;
				dfs(idx + 1, sum + arr[idx]);
				check[i]++;
			}
			break;
		case 1:
			if (check[i]) {
				check[i]--;
				dfs(idx + 1, sum - arr[idx]);
				check[i]++;
			}
			break;
		case 2:
			if (check[i]) {
				check[i]--;
				dfs(idx + 1, sum*arr[idx]);
				check[i]++;
			}
			break;
		case 3:
			if (check[i]) {
				check[i]--;
				dfs(idx + 1, sum / arr[idx]);
				check[i]++;
			}
			break;
		default:
			break;
		}
	}
	return;
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
	for (int i = 0; i < 4; i++)	scanf("%d", &check[i]);

	dfs(1, arr[0]);

	printf("%d\n", MAX);
	printf("%d\n", MIN);

	return 0;
}