#include<cstdio>
using namespace std;

int floor[15][15];

int main() {
	for (int i = 0; i < 15; i++) floor[0][i] = i + 1;
	for (int i = 0; i < 15; i++) floor[i][0] = 1;
	for (int j = 1; j < 15; j++) {
		for (int l = 1; l < 15; l++) {
			floor[j][l] = floor[j - 1][l] + floor[j][l - 1];
		}
	}

	int tc;
	int k, n;
	scanf("%d", &tc);
	for (int i = 0; i < tc; i++) {
		scanf("%d %d", &k, &n);
		printf("%d\n", floor[k][n-1]);
	}

	return 0;
}