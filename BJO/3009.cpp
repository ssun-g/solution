#include<cstdio>
using namespace std;

int arrX[1001];
int arrY[1001];

int main() {
	int x, y;
	for (int i = 0; i < 3; i++) {
		scanf("%d %d", &x, &y);
		arrX[x]++;
		arrY[y]++;
	}

	for (int i = 0; i < 1001; i++) {
		if (arrX[i] == 1) {
			printf("%d ", i);
			break;
		}
	}

	for (int i = 0; i < 1001; i++) {
		if (arrY[i] == 1) {
			printf("%d\n", i);
			break;
		}
	}

	return 0;
}