// A 전봇대에 연결 되어 있는 전선을 오름차순으로 정렬하면
// dp, LIS를 이용하여 B 전봇대에 연결 되어 있는 전선을 탐색하면서
// 가장 많이 연결할 수 있도록 하는 개수를 찾는다.
// 제거 해야 할 개수가 출력 값이므로 전체 개수인 n 에서 최대 연결 개수를 뺀 값이 결과값이다.
#include<bits/stdc++.h>
using namespace std;

int n;
int dp[101];
vector<pair<int, int> > vp;

int solve() {
	int ret = 0;
	for (int i = 0; i < vp.size(); i++) {
		dp[i] = 1;
		for (int j = 0; j < i; j++) {
			if (vp[i].second > vp[j].second && dp[i] < dp[j] + 1) {
				dp[i] = dp[j] + 1;
				ret = max(ret, dp[i]);
			}
		}
	}

	return ret;
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		vp.push_back(make_pair(a, b));
	}
	sort(vp.begin(), vp.end());

	cout << n - solve() << '\n';

	return 0;
}