#include <bits/stdc++.h>
using namespace std;

int n, answer;
int L[20];
int J[20];
int check[20];

void bruteForce(int init, int bital, int happiness) {
	// 기저 조건. 체력이 0이하가 되면 더 이상 진행하지 않고 종료
	// 그렇지 않으면 정답 값을 계속 업데이트 해준다.
	if (bital <= 0) return;
	else answer = max(answer, happiness);

	// 최대 사람 수가 20명이기 때문에 모든 경우를 탐색하는 bruteforce를 사용할 것.
	for (int i = init; i < n; i++) {
		if (!check[i]) { // 방문하지 않은 노드가 있으면 방문 해본다.
			check[i] = 1;
			bruteForce(i + 1, bital - L[i], happiness + J[i]); // 인사를 할 때, 잃는 체력과 얻는 기쁨을 가지고 다음 task로 진행
			check[i] = 0;
		}
	}
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> L[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> J[i];
	}

	bruteForce(0, 100, 0);

	cout << answer << '\n';

	return 0;
}