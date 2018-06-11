#include <cstdio>
using namespace std;

void star(int, int, int);

int main() {
	int n;
	scanf("%d", &n);

	for (int i = 0; i<n; i++) {
		for (int j = 0; j<n; j++)
			star(n, i, j);
		printf("\n");
	}

	return 0;
}

void star(int mod, int i, int j) {
	if ((i / mod) % 3 == 1 && (j / mod) % 3 == 1)
		printf(" ");
	else {
		if (mod / 3 == 0)
			printf("*");
		else
			star(mod / 3, i, j);
	}
}