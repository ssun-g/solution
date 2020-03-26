#include<cstdio>
#include<math.h>
#include<algorithm>
using namespace std;

int n;
int result = 987654321;
int arr[21][21];
int check[21];
int teamF[10];
int teamS[10];

void dfs(int init, int cnt) {
	if (cnt == n / 2) {
		int idx = 0;
		int sumF = 0;
		int sumS = 0;
		for (int i = 1; i <= n; i++) {
			if (!check[i]) teamS[idx++] = i;
		}

		for (int i = 0; i < n / 2; i++) {
			for (int j = 1; j <= n; j++) {
				if (teamF[i] != j && check[j]) sumF += arr[teamF[i]][j];
				if (teamS[i] != j && !check[j]) sumS += arr[teamS[i]][j];
			}
		}
		result = min(result, abs(sumF - sumS));
	}
	for (int i = init + 1; i <= n; i++) {
		if (!check[i]) {
			check[i] = 1;
			teamF[cnt] = i;
			dfs(i, cnt + 1);
			check[i] = 0;
		}
	}
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			scanf("%d", &arr[i][j]);
		}
	}
	dfs(0, 0);
	printf("%d\n", result);

	return 0;
}