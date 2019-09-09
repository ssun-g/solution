#include<cstdio>
using namespace std;

int n;
int ans[80];

int go(int i) {
	for (int k = 1; k <= i / 2; k++) {
		int cnt = 0;
		for (int j = 0; j < k; j++) {
			if (ans[i - 1 - j] == ans[i - 1 - k - j])
				cnt++;
		}
		if (cnt == k)
			return 0;
	}

	if (i == n)
		return 1;

	for (int k = 1; k <= 3; k++) {
		ans[i] = k;
		if (go(i + 1)) return 1;
	}
	return 0;
}

int main() {
	scanf("%d", &n);
	go(0);
	for (int i = 0; i < n; i++) {
		printf("%d", ans[i]);
	}

	return 0;
}