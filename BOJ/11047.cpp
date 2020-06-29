#include<cstdio>
using namespace std;

int main() {
	int coin[10] = { 0, };
	int n, k;
	int idx = 0;
	int answer = 0;
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++) {
		scanf("%d", &coin[i]);
	}

	for (int i = n - 1; i >= 0; i--) {
		if (coin[i] <= k) {
			answer += k / coin[i];
			k %= coin[i];
		}
	}
	printf("%d\n", answer);

	return 0;
}