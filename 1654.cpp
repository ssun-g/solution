#include<cstdio>
#include<algorithm>
using namespace std;

int len[10000];

int main() {
	int k, n, sum = 0;
	long long left = 1;
	long long right = (1 << 31) - 1;
	long long mid = (left + right) / 2;
	scanf("%d%d", &k, &n);
	for (int i = 0; i < k; i++) {
		scanf("%d", &len[i]);
	}
	sort(len, len + k);

	while (left <= right) {
		mid = (left + right) / 2;
		sum = 0;
		for (int i = 0; i < k; i++) {
			sum += (len[i] / mid);
		}
		if (sum < n) {
			right = mid - 1;
		}
		else {
			left = mid + 1;
		}
	}
	left -= 1;
	printf("%lld\n", left);

	return 0;
}

