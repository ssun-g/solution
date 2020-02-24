#include<cstdio>
#include<algorithm>

using namespace std;

int apt[1000];
int hei[1000];

int main() {
	for (int i = 0; i < 1000; i++) apt[i] = -1;

	int tc, height;
	for (int i = 1; i <= 10; i++) {
		int result = 0;
		for (int j = 0; j < 1000; j++) hei[j] = 0;

		scanf("%d", &tc);
		for (int j = 0; j < tc; j++) {
			scanf("%d", &height);
			apt[j] = height;
		}

		for (int j = 2; j < tc; j++) {
			hei[j] = min(min(apt[j] - apt[j + 1], apt[j] - apt[j + 2]), min(apt[j] - apt[j - 1], apt[j] - apt[j - 2]));
		}

		for (int j = 2; j < tc; j++) {
			if (hei[j] > 0) result += hei[j];
		}

		printf("#%d %d\n", i, result);
	}

	return 0;
}