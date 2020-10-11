#include<cstdio>
#include<algorithm>
using namespace std;

int house[200001];

int main() {
	int N, C;
	int answer = -1;
	scanf("%d %d", &N, &C);
	for (int i = 0; i < N; i++) {
		scanf("%d", &house[i]);
	}
	sort(house, house + N);

	int left = 0;
	int right = house[N - 1] - house[0];
	int mid;
	while (left <= right) {
		int cnt = 1;
		mid = (left + right) / 2;
		int cur = house[0];
		for (int i = 1; i < N; i++) {
			int dist = house[i] - cur;
			if (mid <= dist) {
				cnt++;
				cur = house[i];
			}
		}
		if (cnt < C) right = mid - 1;
		else if (cnt >= C) {
			left = mid + 1;
			answer = max(answer, mid);
		}

	}
	printf("%d\n", answer);

	return 0;
}