/*

신호등의 위치를 loc, 신호등의 빨간불 지속시간과 초록불 지속시간을 더한값을 sum이라고 할 때
(loc%sum)값으로 loc위치에 도착했을 때, 현재 빨간불인지 초록불인지 알 수 있게 된다.
하지만 이전 신호등에서 대기 시간이 있다면 현재 위치까지 오는데에 시간이 그만큼 더 소요되었으므로
((loc+총 대기시간) % sum)을 구해줌으로써 현재 위치에서의 신호등 불빛이 어떤색인지 판별할 수 있다.

*/

#include <bits/stdc++.h>
using namespace std;

/*
- tl[i][j]
	i = 신호등의 위치
	j = 0 : 빨간불
	j = 1 : 초록불
*/

int tl[1001][2];

int main() {
	int answer = 0;
	int N, L;
	cin >> N >> L;
	for (int i = 0; i < N; i++) {
		int loc;
		cin >> loc;
		cin >> tl[loc][0] >> tl[loc][1];
	}

	int cnt = 0;
	for (int i = 1; i <= 1000; i++) {
		if (cnt >= N) break;
		if (tl[i][0] != 0 && tl[i][1] != 0) {
			int sum = tl[i][0] + tl[i][1]; // 빨간, 초록 신호등 지속시간의 합
			int rest = (i + answer) % sum; // 신호등의 위치에 도착했을 때 신호등이 빨간불인지 초록불인지 판별하기 위한 시간.
			bool isRed = (rest <= tl[i][0]) ? true : false; // 남은 시간이 빨간불의 지속시간보다 작다면 현재 빨간불인 것.

			if (isRed) answer += tl[i][0] - rest; // 현재 위치에서 빨간불이라면 대기시간을 더해준다.
			cnt++;
		}
	}
	cout << answer + L << '\n';

	return 0;
}