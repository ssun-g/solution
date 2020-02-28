#include<cstdio>
#include<algorithm>
using namespace std;

int box[100];

int main() {
	int t;
	int MAX = -1;
	int MIN = 101;
	int Midx;
	int midx;
	for (int k = 0; k < 10; k++) {
		scanf("%d", &t);
		for (int i = 0; i < 100; i++) {
			scanf("%d", &box[i]);
		}

		for (int i = 0; i < t; i++) {
			for (int j = 0; j < 100; j++) {
				if (MAX < box[j]) {
					MAX = box[j];
					Midx = j;
				}
				if (MIN > box[j]) {
					MIN = box[j];
					midx = j;
				}
			}
			box[Midx]--;
			box[midx]++;
			MAX = -1;
			MIN = 101;
		}

		for (int i = 0; i < 100; i++) {
			MAX = max(MAX, box[i]);
			MIN = min(MIN, box[i]);
		}
		printf("#%d %d\n", k + 1, MAX-MIN);
	}
	return 0;
}