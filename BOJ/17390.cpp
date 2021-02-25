/*

문제에서 설명 했듯 N, Q가 최대 300,000이기 때문에
단순한 2중 for문으로는 시간 제한 안에 문제를 해결할 수 없기 때문에 시간복잡도를 줄어야 하고, 그 아이디어는 다음과 같다.

비내림차순 수열을 차례대로 보면서 현재 노드까지의 누적 합을 part_sum에 저장해주었다.
그 후, part_sum[R]-part_sum[L-1]을 해준다면 인덱스 L ~ R까지의 비내림차순 수열 값들의 합이 된다.
L-1을 해 준 이유는 L번째 값도 더해 주어야 하기 때문.

*/

#include <bits/stdc++.h>
using namespace std;

int part_sum[300001];

int main() {
	/* 아래 두 줄 안써주면 시간초과가 발생한다*/
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N, Q;
	cin >> N >> Q;
	vector<int> v(N + 1, 0);
	for (int i = 1; i <= N; i++) {
		cin >> v[i];
	}
	sort(v.begin(), v.end()); // 비내림차순 수열을 만들어준다.

	for (int i = 1; i <= N; i++) {
		part_sum[i] = v[i] + part_sum[i - 1]; // 누적합 저장
	}

	while (Q--) {
		int L, R;
		cin >> L >> R;
		cout << part_sum[R] - part_sum[L - 1] << '\n'; // L ~ R 까지의 합을 구해준다.
	}

	return 0;
}
