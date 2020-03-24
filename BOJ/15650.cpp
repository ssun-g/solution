#include<cstdio>
using namespace std;

int n, m;
int check[9];
int arr[9];

void seq(int init, int idx, int cnt) {
	if (cnt == m) {
		for (int i = 0; i < m; i++) {
			printf("%d ", arr[i]);
		}
		printf("\n");
		return;
	}

	for (int i = init; i <= n; i++) {
		if (!check[i]) {
			check[i] = 1;
			arr[idx] = i;
			seq(i + 1, idx + 1, cnt + 1);
			check[i] = 0;
		}
	}
}


int main() {
	scanf("%d %d", &n, &m);
	seq(1, 0, 0);
	return 0;
}