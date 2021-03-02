#include<bits/stdc++.h>
using namespace std;

int N, K;
int death_game[150];
int check[150]; // 지목 당한 적이 있는지 확인하기 위한 배열
int depth[150]; // 몇 번째로 처음 지목 당했는지 저장하기 위한 배열

void Reset() {
	for (int i = 0; i < 150; i++) {
		depth[i] = -1;
	}
}

void solve(int cur, int d) {
	int next = death_game[cur];
	if (check[cur] == 1) return; // 이미 이전에 지목당한 적이 있으면 함수를 종료한다.

	// 지목당한 적이 없으면 게임을 계속 진행한다.
	check[cur] = 1;
	depth[cur] = d;
	solve(next, d + 1);
}

int main() {
	Reset(); // depth배열 초기화

	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		cin >> death_game[i];
	}

	solve(0, 0);

	// 지목당한 적이 없으면 배열의 초기화 값인 -1일 것이므로 지목당하지 않는 경우도 만족한다.
	cout << depth[K] << '\n';

	return 0;
}