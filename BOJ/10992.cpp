#include<cstdio>
using namespace std;

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		if (i < n) {
			for (int j = i; j < n; j++) {
				printf(" ");
			}

			for (int j = 1; j <= 2 * i - 1; j++) {
				if (j == 1 || j == 2 * i - 1) printf("*");
				else printf(" ");

			}
			printf("\n");
		}
		else {
			for (int j = 1; j <= 2 * i - 1; j++) printf("*");
		}
	}

	return 0;
}