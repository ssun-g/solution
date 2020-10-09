#include<cstdio>
using namespace std;

int ccnt;
int cycle[1001];
int arr[1001];
int check[1001];

void Reset() {
	ccnt = 0;
	for (int i = 0; i < 1001; i++) {
		arr[i] = 0;
		check[i] = 0;
		cycle[i] = 0;
	}
}

void dfs(int init) {
	if (check[init] == 1) cycle[init] = 1;
	else if (check[init] == 0) check[init] = 1;
	if (cycle[init] == 1 || check[init] == -1) return;
	dfs(arr[init]);
	check[init] = -1;
}

int main() {
	int tc;
	scanf("%d", &tc);
	while (tc--) {
		Reset();
		int N;
		scanf("%d", &N);
		for (int i = 1; i <= N; i++) {
			scanf("%d", &arr[i]);
		}

		for (int i = 1; i <= N; i++) {
			if (check[i] == 0) {
				dfs(i);
				ccnt++;
			}
		}
		printf("%d\n", ccnt);
	}

	return 0;
}