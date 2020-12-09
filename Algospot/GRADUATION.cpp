#include<bits/stdc++.h>
#define INF 987654321
using namespace std;

int N, K, M, L;
int require[12];
int courses[10];
int cache[10][1 << 12];

int bitCount(int n) {
	if (n == 0) return 0;
	return n % 2 + bitCount(n / 2);
}

int graduation(int semester, int taken) {
	if (bitCount(taken) >= K) return 0;
	if (semester == M) return INF;


	int &ret = cache[semester][taken];
	if (ret != -1) return ret;
	ret = INF;

	int canTake = (courses[semester] & ~taken);
	for (int i = 0; i < N; i++) {
		if ((canTake & (1 << i)) && (taken & require[i]) != require[i])
			canTake &= ~(1 << i);
	}

	for (int i = canTake; i > 0; i = ((i - 1) & canTake)) {
		if (bitCount(i) > L) continue;
		ret = min(ret, graduation(semester + 1, taken | i) + 1);
	}
	ret = min(ret, graduation(semester + 1, taken));

	return ret;
}

int main() {
	int C;
	cin >> C;
	while (C--) {
		memset(require, 0, sizeof(require));
		memset(courses, 0, sizeof(courses));
		memset(cache, -1, sizeof(cache));

		cin >> N >> K >> M >> L;
		for (int i = 0; i < N; i++) {
			int pre;
			cin >> pre;
			for (int j = 0; j < pre; j++) {
				int sub;
				cin >> sub;
				require[i] |= (1 << sub);
			}
		}

		for (int i = 0; i < M; i++) {
			int courseNum;
			cin >> courseNum;
			for (int j = 0; j < courseNum; j++) {
				int sub;
				cin >> sub;
				courses[i] |= (1 << sub);
			}
		}

		int answer = graduation(0, 0);
		if (answer == INF) cout << "IMPOSSIBLE" << '\n';
		else cout << answer << '\n';
	}

	return 0;
}