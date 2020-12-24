#include<bits/stdc++.h>
using namespace std;

class strChange {
public:
	string s;
	int cnt;

	strChange(string s, int cnt) {
		this->s = s;
		this->cnt = cnt;
	}
};

string N;
int K;
int answer;
int check[1000001][11];

string strSwap(string s, int i, int j) {
	char ic = s[i];
	char jc = s[j];
	string ret = s.substr(0, i);
	ret += jc;
	ret += s.substr(i + 1, j - i - 1);
	ret += ic;
	ret += s.substr(j + 1);

	return ret;
}

void bfs(string start, int M) {
	queue<strChange> q;
	q.push(strChange(start, 0));

	while (!q.empty()) {
		strChange cur = q.front();
		q.pop();
		if (cur.cnt > K) return;

		for (int i = 0; i < M; i++) {
			for (int j = i + 1; j < M; j++) {
				string nextStr = strSwap(cur.s, i, j);
				int nextCnt = cur.cnt + 1;

				if (nextStr[0] != '0' && !check[stoi(nextStr)][nextCnt]) {
					check[stoi(nextStr)][nextCnt] = check[stoi(cur.s)][cur.cnt] + 1;
					q.push(strChange(nextStr, nextCnt));
					if (nextCnt == K)
						answer = max(answer, stoi(nextStr));
				}
			}
		}
	}
}

int main() {
	cin >> N >> K;

	bfs(N, N.length());
	if (answer == 0) cout << -1 << '\n';
	else cout << answer << '\n';

	return 0;
}