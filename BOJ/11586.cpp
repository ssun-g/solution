#include<cstdio>
using namespace std;

char arr[100][100];

int main() {
	int n, flag;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf(" %c", &arr[i][j]);
		}
	}
	scanf("%d", &flag);
	if (flag == 1) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				printf("%c", arr[i][j]);
			}
			printf("\n");
		}
	}
	else if (flag == 2) {
		for (int i = 0; i < n; i++) {
			for (int j = n - 1; j >= 0; j--) {
				printf("%c", arr[i][j]);
			}
			printf("\n");
		}
	}
	else if (flag == 3) {
		for (int i = n - 1; i >= 0; i--) {
			for (int j = 0; j < n; j++) {
				printf("%c", arr[i][j]);
			}
			printf("\n");
		}
	}

	return 0;
}