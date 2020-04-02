#include <vector>
#include <algorithm>
using namespace std;

vector<int> v;
int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { 1, -1, 0, 0 };
int check[100][100];

void res() {
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			check[i][j] = 0;
		}
	}
}

int go(int x, int y, int m, int n, vector<vector<int>> picture) {
	int ret = 1;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (0 <= nx && 0 <= ny && ny < m && nx < n && picture[ny][nx] == picture[y][x] && !check[ny][nx]) {
			check[ny][nx] = 1;
			ret += go(nx, ny, m, n, picture);
		}
	}

	return ret;
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<int> solution(int m, int n, vector<vector<int>> picture) {
	int number_of_area = 0;
	int max_size_of_one_area = 0;
	res();
	for (int i = 0; i < picture.size(); i++) {
		for (int j = 0; j < picture[i].size(); j++) {
			if (!check[i][j] && picture[i][j] != 0) {
				check[i][j] = 1;
				max_size_of_one_area = max(max_size_of_one_area, go(j, i, m, n, picture));
				number_of_area++;
			}
		}
	}

	vector<int> answer(2);
	answer[0] = number_of_area;
	answer[1] = max_size_of_one_area;
	return answer;
}