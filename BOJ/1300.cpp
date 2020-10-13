#include<cstdio>
#include<algorithm>
using namespace std;

int main() {
	int N, k;
	scanf("%d %d", &N, &k);

	int left = 0;
	int right = 1000000001;
	int mid;
	while (left <= right) {
		int sum = 0;
		mid = (left + right) / 2;
		for (int i = 1; i <= N; i++) {
			sum += min(mid / i, N);
		}
		if (sum < k) left = mid + 1;
		else right = mid - 1;
	}
	printf("%d\n", left);

	return 0;
}