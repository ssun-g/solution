#include<bits/stdc++.h>
using namespace std;

int height[20000];

void solve(int h[], int size) {
	stack<pair<int, int> > st;
	int answer = -1;
	for (int i = 0; i <= size; i++) {
		while (!st.empty() && st.top().first > height[i]) {
			int sum;
			int top = st.top().first;
			st.pop();
			if (st.size() == 0) sum = top*i;
			else sum = top*(i - (st.top().second + 1));
			answer = (answer < sum) ? sum : answer;
		}
		st.push(make_pair(height[i], i));
	}
	cout << answer << '\n';
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
		solve(height, N);
	}

	return 0;
}