/*

벚나무의 개수 N이 최대 10이므로 brutefoce를 사용했다.
4개의 그룹으로 나누는 모든 경우의 수마다 값을 구하고 가장 큰 값을 answer에 저장해주었다.

*/
#include<bits/stdc++.h>
using namespace std;

int answer = 0;
int N;
int sakura[10];
int check[10];

// init: 그룹의 시작 지점, cnt: 그룹을 나눈 횟수, sum: 네 개의 P의 최대값을 구하기 위해 그룹을 나눌 때마다 더해준다.
void bruteForce(int init, int cnt, int sum) {
	int tmp = 1;

	// 그룹을 3번 나누게 되면 4개의 그룹이 되므로 기저조건으로 잡았다.
	if (cnt == 3) {
		bool flag = false;
		for (int i = init; i < N; i++) {
			flag = true; // 4개의 그룹을 정확히 나누었는지 체크해준다.
			tmp *= sakura[i]; // 마지막 그룹의 P값을 tmp에 저장해준다.
		}
		if (flag)
			answer = (answer < sum + tmp) ? sum + tmp : answer;

		return;
	}

	for (int i = init; i < N; i++) {
		if (!check[i]) {
			check[i] = 1;
			tmp *= sakura[i]; // 벚꽃을 모두 같은 그룹으로 생각하고 계속 곱해준다.
			bruteForce(i + 1, cnt + 1, sum + tmp); // 그룹을 나눈다. 나눌 때마다 +연산을 해준다.
			check[i] = 0;
		}
	}
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> sakura[i];
	}

	bruteForce(0, 0, 0);

	cout << answer << '\n';

	return 0;
}
