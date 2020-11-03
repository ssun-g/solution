#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

class Point {
public:
	int x;
	int y;
};

vector<Point> p;

bool compX(Point a, Point b) {
	if (a.x == b.x) return a.y < b.y;
	return a.x < b.x;
}

bool compY(Point a, Point b) {
	if (a.y == b.y) return a.x < b.x;
	return a.y < b.y;
}

int dist(Point a, Point b) {
	return (a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y);
}

int closet(int left, int right) {
	int size = right - left + 1;
	if (size == 2) return dist(p[0], p[1]);
	if (size == 3) return min(min(dist(p[0], p[1]), dist(p[1], p[2])), dist(p[0], p[2]));

	int mid = (left + right) / 2;

	// 중앙선 기준 왼쪽, 오른쪽 구간에서의 최소값
	int ret = min(closet(left, mid), closet(mid + 1, right));

	// d 거리 이내에 존재하는 점들만 체크, y좌표 기준으로 정렬
	vector<Point> tmp;
	for (int i = left; i <= right; i++) {
		int t = p[mid].x - p[i].x;
		if (i == mid) {
			tmp.push_back(p[mid]);
			continue;
		}
		if (t*t < ret)
			tmp.push_back(p[i]);
	}
	sort(tmp.begin(), tmp.end(), compY);

	// 자신보다 y좌표 값이 큰 점만 체크
	for (int i = 0; i < tmp.size() - 1; i++) {
		for (int j = i + 1; j < tmp.size(); j++) {
			int t = tmp[j].y - tmp[i].y;
			if (t*t < ret)
				ret = min(ret, dist(tmp[i], tmp[j]));
			else break;
		}
	}

	return ret;
}

int main() {
	int n;
	scanf("%d", &n);
	Point point;
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &point.x, &point.y);
		p.push_back(point);
	}
	sort(p.begin(), p.end(), compX);

	printf("%d\n", closet(0, n - 1));

	return 0;
}