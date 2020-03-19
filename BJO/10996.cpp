#include<cstdio>
using namespace std;

int main() {
	int n;
	scanf("%d", &n);
	if (n == 1) {
		printf("*\n");
		return 0;
	}

	for (int i = 0; i < 2 * n; i++) {
		if (i % 2 == 0) {
			for (int j = 0; j < n; j++) {
				if (j % 2 == 0) printf("*");
				else printf(" ");
			}
		}
		else {
			for (int j = 0; j < n; j++) {
				if (j % 2 == 0)  printf(" ");
				else printf("*");
			}
		}
		printf("\n");
	}

	return 0;
}