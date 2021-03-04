/*

시작 위치에서 4방향 모두 시그널을 보내보고 전파 시간이 가장 긴 놈을 출력.

*/
#include<bits/stdc++.h>
using namespace std;

int N, M;
vector<string> Map;
vector<pair<char, int> > answer; // (시작방향, 전파시간) 쌍을 저장하기 위한 vector

// 전파 시간이 긴 순으로 내림차순 정렬
bool comp(pair<char, int> a, pair<char, int> b) {
	return a.second > b.second;
}

int signal(int y, int x, char direction) {
	int prop = 0;
	while (true) {
		// 탈출 조건
		if (prop > N*M) break; // 항성계의 전체 크기보다 크다면 무한루프를 돌고 있는 것으로 판단.
		if (x < 0 || y < 0 || x >= M || y >= N || Map[y][x] == 'C') // 맵 밖으로 나가거나 블랙홀을 만난 경우
			break;

		prop++;

		// 진행 방향에 따라 1초씩 이동한다.
		if (direction == 'U') {
			if (Map[y][x] == '/') { // 진행 방향이 U이고 '/' 행성을 만났을 때, 다음 진행 방향은 R
				direction = 'R';
				x += 1;
			}
			else if (Map[y][x] == '\\') { // 진행 방향이 U이고 '\' 행성을 만났을 때, 다음 진행 방향은 L
				direction = 'L';
				x -= 1;
			}
			else y -= 1; // 행성이 없을 경우 원래 진행 방향.
		}
		else if (direction == 'R') {
			if (Map[y][x] == '/') {
				direction = 'U';
				y -= 1;
			}
			else if (Map[y][x] == '\\') {
				direction = 'D';
				y += 1;
			}
			else x += 1;
		}
		else if (direction == 'D') {
			if (Map[y][x] == '/') {
				direction = 'L';
				x -= 1;
			}
			else if (Map[y][x] == '\\') {
				direction = 'R';
				x += 1;
			}
			else y += 1;
		}
		else {
			if (Map[y][x] == '/') {
				direction = 'D';
				y += 1;
			}
			else if (Map[y][x] == '\\') {
				direction = 'U';
				y -= 1;
			}
			else x -= 1;
		}
	}

	return prop;
}

int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		string s;
		cin >> s;
		Map.push_back(s);
	}

	int sy, sx;
	cin >> sy >> sx;
	sy--; // 문제에서 index가 1부터 시작하기 때문에 -1해줌.
	sx--;

	// 시작 지점에서 4방향으로 진행했을 때의 거리를 저장해준다.
	answer.push_back(make_pair('U', signal(sy, sx, 'U')));
	answer.push_back(make_pair('R', signal(sy, sx, 'R')));
	answer.push_back(make_pair('D', signal(sy, sx, 'D')));
	answer.push_back(make_pair('L', signal(sy, sx, 'L')));

	sort(answer.begin(), answer.end(), comp);

	cout << answer[0].first << '\n';
	if (answer[0].second > N*M) cout << "Voyager" << '\n';
	else cout << answer[0].second << '\n';

	return 0;
}