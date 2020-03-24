#include<cstdio>
using namespace std;

int n, m;
int check[9];
int arr[9];

void seq(int idx, int cnt) {
	if (cnt == m) {
		for (int i = 0; i < m; i++) {
			printf("%d ", arr[i]);
		}
		printf("\n");
	}
	for (int i = 1; i <= n; i++) {
		if (!check[i]) {
			check[i] = 1;
			arr[idx] = i;
			seq(idx + 1, cnt + 1);
			check[i] = 0;
		}
	}
}


int main() {
	scanf("%d %d", &n, &m);
	seq(0, 0);
	return 0;
}