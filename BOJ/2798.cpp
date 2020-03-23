#include<cstdio>
#include<algorithm>
using namespace std;

int card[101], n, m, MAX, temp;

void blj(int, int, int);

int main() {
	scanf("%d%d", &n, &m);

	for (int i = 0; i < n; i++) {
		scanf("%d", &card[i]);
	}
	blj(0, 0, 0);
	printf("%d\n", MAX);

	return 0;
}

void blj(int init, int sum, int cnt) {
	if (cnt > 3 || MAX > m) return;
	if (cnt == 3) {
		if (sum <= m) {
			MAX = max(MAX, sum);
		}
	}

	for (int i = init; i < n; i++) {
		blj(i + 1, sum + card[i], cnt + 1);
	}
	return;
}