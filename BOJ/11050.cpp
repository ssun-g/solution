#include<cstdio>
using namespace std;

int main() {
	int n, k;
	scanf("%d %d", &n, &k);
	int bin[11][11] = { 0, };
	for (int i = 1; i < 11; i++) {
		bin[i][1] = i;
		bin[i][i] = 1;
		bin[i][0] = 1;
	}
	for (int i = 2; i < 11; i++) {
		for (int j = 2; j < 11; j++) {
			bin[i][j] = bin[i - 1][j - 1] + bin[i - 1][j];
		}
	}
	printf("%d\n", bin[n][k]);


	return 0;
}