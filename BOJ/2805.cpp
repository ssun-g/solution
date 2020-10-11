#include<cstdio>
#include<algorithm>
using namespace std;

int tree[1000001];

int main() {
	int N, M;
	long long answer = -1;
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) {
		scanf("%d", &tree[i]);
	}
	sort(tree, tree + N);

	long long left = 0;
	long long right = tree[N - 1];
	long long mid;
	while (left <= right) {
		long long sum = 0;
		mid = (left + right) / 2;
		for (int i = 0; i < N; i++) {
			if (mid < tree[i]) sum += tree[i] - mid;
		}
		if (sum < M) right = mid - 1;
		else if (sum >= M) {
			left = mid + 1;
			answer = max(answer, mid);
		}
	}
	printf("%lld\n", answer);

	return 0;
}