#include<cstdio>
using namespace std;

int comb[35][35];

int main() {
	int t;
	int n, m;
	scanf("%d", &t);
	for (int i = 0; i < 35; i++) {
		comb[i][i] = 1;
		comb[i][0] = 1;
	}

	while (t--) {
		scanf("%d%d", &n, &m);
		for (int i = 2; i <= 30; i++) {
			for (int j = 1; j <= 30; j++) {
				comb[i][j] = comb[i - 1][j] + comb[i - 1][j - 1];
			}
		}
		printf("%d\n", comb[m][n]);
	}

	return 0;
}