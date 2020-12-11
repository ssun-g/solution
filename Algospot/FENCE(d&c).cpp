#include<bits/stdc++.h>
using namespace std;

int height[20000];

// 최대 직사각형의 크기는 3가지 중 하나에 속한다
// 1. 왼쪽 부분, 2. 오른쪽 부분, 3. 왼쪽, 오른쪽에 걸쳐있다.
int solve(int left, int right) {
	if (left == right) return height[left];

	// 1, 2번 구간 중 최대 직사각혐의 크기를 구함
	int mid = (left + right) / 2;
	int maxHeight = max(solve(left, mid), solve(mid + 1, right));

	// 3번 구간을 구하기 위해 왼쪽, 오른쪽 부분에 걸쳐 있는 직사각형 중
	// 너비가 2인 가장 큰 직사각형의 넓이를 구하고 한칸씩 너비를 점점 늘려감.
	int lo = mid, hi = mid + 1;
	int h = min(height[lo], height[hi]);
	maxHeight = max(maxHeight, h * 2);
	while (left < lo || hi < right) {
		if (hi < right && (lo == left || height[lo - 1] < height[hi + 1]))
			h = min(h, height[++hi]);
		else
			h = min(h, height[--lo]);

		maxHeight = max(maxHeight, h*(hi - lo + 1));
	}

	return maxHeight;
}

int main() {
	int c;
	cin >> c;
	while (c--) {
		memset(height, -1, sizeof(height));

		int N;
		cin >> N;
		for (int i = 0; i < N; i++) {
			cin >> height[i];
		}
		cout << solve(0, N - 1) << '\n';
	}

	return 0;
}