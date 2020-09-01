#include<cstdio>
using namespace std;

int arr[10][10];

int main() {
	int r, c;
	scanf("%d %d", &r, &c);
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			scanf("%1d", &arr[i][j]);
		}
	}

	for (int i = 0; i < r; i++) {
		for (int j = c - 1; j >= 0; j--) {
			printf("%d", arr[i][j]);
		}
		printf("\n");
	}

	return 0;
}