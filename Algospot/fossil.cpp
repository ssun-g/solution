#include<bits/stdc++.h>
using namespace std;

class Point {
public:
	double x, y;
};

vector<Point> hull1, hull2;
// 위 껍질, 아래 껍질에 속하는 선분들의 집합
vector<pair<Point, Point> > upper, lower;

void Reset() {
	hull1.clear();
	hull2.clear();
	upper.clear();
	lower.clear();
}

double minX(const vector<Point>& p) {
	double ret = 101;
	for (int i = 0; i < p.size(); i++) {
		ret = min(ret, p[i].x);
	}

	return ret;
}

double maxX(const vector<Point>& p) {
	double ret = -1;
	for (int i = 0; i < p.size(); i++) {
		ret = max(ret, p[i].x);
	}

	return ret;
}

// x가 증가하면 아래껍질, 감소하면 위 껍질
void decompose(const vector<Point>& hull) {
	int n = hull.size();
	for (int i = 0; i < n; i++) {
		if (hull[i].x < hull[(i + 1) % n].x)
			lower.push_back(make_pair(hull[i], hull[(i + 1) % n]));
		else if (hull[i].x > hull[(i + 1) % n].x)
			upper.push_back(make_pair(hull[i], hull[(i + 1) % n]));
	}
}

// x가 a.x와 b.x사이에 포함되는지 확인
bool between(const Point& a, const Point& b, double x) {
	return (a.x <= x && x <= b.x) || (b.x <= x && x <= a.x);
}

// (a, b)선분과 주어진 위치의 수직전이 교차하는 위치를 찾는다.
double atPoint(const Point& a, const Point& b, double x) {
	double dx = b.x - a.x;
	double dy = b.y - a.y;

	return a.y + dy*(x - a.x) / dx;
}

double vertical(double x) {
	double minUp = 1e20, maxLow = -1e20;
	for (int i = 0; i < upper.size(); i++) {
		if (between(upper[i].first, upper[i].second, x))
			minUp = min(minUp, atPoint(upper[i].first, upper[i].second, x));
	}

	for (int i = 0; i < lower.size(); i++) {
		if (between(lower[i].first, lower[i].second, x))
			maxLow = max(maxLow, atPoint(lower[i].first, lower[i].second, x));
	}

	return minUp - maxLow;
}

double solve() {
	double left = max(minX(hull1), minX(hull2));
	double right = min(maxX(hull1), maxX(hull2));

	if (right < left) return 0;

	for (int i = 0; i < 100; i++) {
		double q2 = (2 * left + right) / 3;
		double q3 = (left + 2 * right) / 3;

		if (vertical(q2) < vertical(q3))
			left = q2;
		else
			right = q3;
	}

	return max(0.0, vertical(left));
}

int main() {
	int c;
	cin >> c;
	while (c--) {
		int n, m;
		cin >> n >> m;
		for (int i = 0; i < n; i++) {
			Point h;
			cin >> h.x >> h.y;
			hull1.push_back(h);
		}

		for (int i = 0; i < m; i++) {
			Point h;
			cin >> h.x >> h.y;
			hull2.push_back(h);
		}

		decompose(hull1);
		decompose(hull2);

		cout << fixed << setprecision(8);
		cout << solve() << '\n';
		Reset();
	}

	return 0;
}