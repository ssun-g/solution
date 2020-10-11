#include<cstdio>
#include<algorithm>
using namespace std;

int line[10001];

int main() {
	int K, N;
	long long answer = -1;
	scanf("%d %d", &K, &N);
	for (int i = 0; i < K; i++) {
		scanf("%d", &line[i]);
	}
	sort(line, line + K);

	long long left = 0;
	long long right = (1 << 31) - 1;
	long long mid;
	while (left <= right) {
		mid = (left + right) / 2;
		long long sum = 0;
		for (int i = 0; i < K; i++) {
			sum += line[i] / mid;
		}
		if (sum < N) right = mid - 1;
		else if (sum >= N) {
			left = mid + 1;
			answer = max(answer, mid);
		}
	}
	printf("%lld\n", answer);

	return 0;
}