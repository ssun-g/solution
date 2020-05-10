#include<cstdio>
#include<algorithm>
using namespace std;

int n;
int MAX = -1;
int arr[15][2];

void go(int init, int money) {
	if (init > n) return;
	MAX = max(MAX, money);
	for (int i = init; i < n; i++) {
		go(i + arr[i][0], money + arr[i][1]);
	}
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &arr[i][0], &arr[i][1]);
	}

	go(0, 0);
	printf("%d\n", MAX);

	return 0;
}