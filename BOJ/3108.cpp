#include<iostream>
#include<queue>
#include<vector>
using namespace std;

class Rect {
public:
	int sx, sy, ex, ey;
};

Rect rect;
vector<Rect> vr;
queue<int> q;
int check[1001];

bool isMeet(int a, int b) {
	if (vr[a].ex < vr[b].sx || vr[b].ex < vr[a].sx || vr[a].sy > vr[b].ey || vr[b].sy > vr[a].ey) return false;
	if (vr[a].sx < vr[b].sx && vr[a].sy < vr[b].sy && vr[b].ex < vr[a].ex && vr[b].ey < vr[a].ey) return false;
	if (vr[b].sx < vr[a].sx && vr[b].sy < vr[a].sy && vr[a].ex < vr[b].ex && vr[a].ey < vr[b].ey) return false;

	return true;
}

int main() {
	int N;
	int answer = 0;
	cin >> N;

	rect.sx = 0;
	rect.sy = 0;
	rect.ex = 0;
	rect.ey = 0;
	vr.push_back(rect);
	for (int i = 0; i < N; i++) {
		cin >> rect.sx >> rect.sy >> rect.ex >> rect.ey;
		vr.push_back(rect);
	}

	for (int i = 0; i <= N; i++) {
		if (check[i]) continue;
		check[i] = 1;
		q.push(i);

		while (!q.empty()) {
			int front = q.front();
			q.pop();
			for (int j = 0; j <= N; j++) {
				if (front == j || !isMeet(front, j) || check[j]) continue;

				check[j] = 1;
				q.push(j);
			}
		}
		answer++;
	}
	cout << answer - 1 << '\n';

	return 0;
}