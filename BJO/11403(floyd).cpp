#include<cstdio>

using namespace std;

int mp[100][100];
int tc;

int main() {
	scanf("%d", &tc);
	// input
	for (int i = 0; i < tc; i++) {
		for (int j = 0; j < tc; j++) {
			scanf("%d", &mp[i][j]);
		}
	}

	// floyd
	for (int k = 0; k < tc; k++) {
		for (int j = 0; j < tc; j++) {
			if (mp[j][k] == 1) {
				for (int l = 0; l < tc; l++) {
					if (mp[k][l] == 1) {
						mp[j][l] = 1;
					}
				}
			}
		}
	}

	for (int i = 0; i < tc; i++) {
		for (int j = 0; j < tc; j++) {
			printf("%d ", mp[i][j]);
		}
		printf("\n");
	}

	return 0;
}