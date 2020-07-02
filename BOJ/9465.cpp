#include<cstdio>
#include<algorithm>
using namespace std;

int main() {
	int tc;
	scanf("%d", &tc);
	while (tc--) {
		int n;
		int Stick[2][100002] = { 0, };
		scanf("%d", &n);
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < n; j++) {
				scanf("%d", &Stick[i][j]);
			}
		}

		Stick[0][1] += Stick[1][0];
		Stick[1][1] += Stick[0][0];

		for (int j = 2; j < n; j++) {
			for (int i = 0; i < 2; i++) {
				if (i == 0) Stick[i][j] += max(Stick[i + 1][j - 1], Stick[i + 1][j - 2]);
				else Stick[i][j] += max(Stick[i - 1][j - 1], Stick[i - 1][j - 2]);
			}
		}
		printf("%d\n", max(Stick[0][n - 1], Stick[1][n - 1]));
	}

	return 0;
}