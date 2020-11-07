#include<cstdio>
#include<algorithm>
using namespace std;

int N, start;
int Min = 987654321;
int arr[10][10];
int check[10];

void cycle(int init, int sum, int cnt) {
	if (check[start] && cnt != N) return;
	if (init == start && cnt == N) {
		Min = min(Min, sum);
		return;
	}

	for (int i = 0; i < N; i++) {
		if (arr[init][i] != 0 && !check[i]) {
			check[i] = 1;
			cycle(i, sum + arr[init][i], cnt + 1);
			check[i] = 0;
		}
	}
}

int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &arr[i][j]);
		}
	}

	for (int i = 0; i < N; i++) {
		start = i;
		cycle(i, 0, 0);
	}
	printf("%d\n", Min);

	return 0;
}