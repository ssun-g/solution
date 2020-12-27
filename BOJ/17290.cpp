#include<bits/stdc++.h>
using namespace std;

class Point {
public:
	int y, x;

	Point(int y, int x) {
		this->y = y;
		this->x = x;
	}
};

int r, c;
vector<string> Map;
bool check[10][10];

void spread(int y, int x) {
	check[y][x] = true;
	for (int i = 0; i < 10; i++) {
		if (!check[i][x] && Map[i][x] == 'x') {
			Map[i][x] = 'o';
			check[i][x] = true;
		}

		if (!check[y][i] && Map[y][i] == 'x') {
			Map[y][i] = 'o';
			check[y][i] = true;
		}
	}
}

int dist(vector<Point> point) {
	int ret = 987654321;
	for (int i = 0; i < point.size(); i++) {
		ret = min(ret, abs(r - point[i].y) + abs(c - point[i].x));
	}

	return ret;
}

int main() {
	cin >> r >> c;
	for (int i = 0; i < 10; i++) {
		string s;
		cin >> s;
		Map.push_back(s);
	}

	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if (!check[i][j] && Map[i][j] == 'o') spread(i, j);
		}
	}

	vector<Point> point;
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if (Map[i][j] == 'x') point.push_back(Point(i + 1, j + 1));
		}
	}
	cout << dist(point) << '\n';

	return 0;
}