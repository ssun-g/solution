#include<cstdio>
using namespace std;

long long t[1000001];

int main() {
	int n, m;
	long long Max = 0;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%lld", &t[i]);
		if (Max < t[i]) Max = t[i];
	}

	long long left = 1, right = Max*m;
	long long ans = Max*m;
	while (left <= right) {
		long long mid = (left + right) / 2;
		long long total = 0;
		for (int i = 0; i < n; i++) {
			total += mid / t[i];
		}
		if (total < m) {
			left = mid + 1;
		}
		else {
			if (ans > mid)
				ans = mid;
			right = mid - 1;
		}
	}
	printf("%lld\n", ans);
	return 0;
}