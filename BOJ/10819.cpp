#include<cstdio>
#include<algorithm>
#include<math.h>
using namespace std;

int n, MAX = -1;
int arr[8];
int per[8];
int check[8];

int cmp(int sel[]) {
	int sum = 0;
	for (int i = 0; i < n - 1; i++) {
		sum += abs(sel[i] - sel[i + 1]);
	}

	return sum;
}

void go(int cnt) {
	if (cnt == n) {
		MAX = max(MAX, cmp(per));
		return;
	}

	for (int i = 0; i < n; i++) {
		if (!check[i]) {
			check[i] = 1;
			per[cnt] = arr[i];
			go(cnt + 1);
			per[cnt] = 0;
			check[i] = 0;
		}
	}
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}

	go(0);
	printf("%d\n", MAX);

	return 0;
}