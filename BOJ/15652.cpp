#include<cstdio>
using namespace std;

int n, m;
int check[9];
int arr[9] = { 1, };

void seq(int idx, int cnt) {
	if (cnt == m) {
		for (int i = 1; i <= m; i++) {
			printf("%d ", arr[i]);
		}
		printf("\n");
		return;
	}

	for (int i = 1; i <= n; i++) {
		if (arr[idx - 1] <= i) {
			arr[idx] = i;
			seq(idx + 1, cnt + 1);
		}
	}
	return;
}


int main() {
	scanf("%d %d", &n, &m);
	seq(1, 0);
	return 0;
}