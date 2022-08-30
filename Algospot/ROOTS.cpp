#include<bits/stdc++.h>
using namespace std;

const double L = 10;

// 미분하기
vector<double> differentiate(const vector<double>& poly) {
	int n = poly.size() - 1;
	vector<double> ret;
	for (int i = 0; i < n; i++) {
		ret.push_back(poly[i] * (n - i));
	}

	return ret;
}

// 2차 이하의 방정식 풀기
vector<double> solveNaive(const vector<double>& poly) {
	int n = poly.size() - 1;
	vector<double> ret;

	if (n == 1) {
		ret.push_back(-poly[1] / poly[0]);
	}
	else if (n == 2) {
		ret.push_back((-poly[1] + sqrt(pow(poly[1], 2) - 4 * poly[0] * poly[2])) / (2 * poly[0]));
		ret.push_back((-poly[1] - sqrt(pow(poly[1], 2) - 4 * poly[0] * poly[2])) / (2 * poly[0]));
	}
	sort(ret.begin(), ret.end());

	return ret;
}

// f(x)값 구하기.
double evaluate(const vector<double>& poly, double x) {
	int n = poly.size() - 1;
	double ret = 0;
	for (int i = 0; i < n + 1; i++) {
		ret += pow(x, n - i)*poly[i];
	}

	return ret;
}


vector<double> solve(const vector<double>& poly) {
	int n = poly.size() - 1;
	if (n <= 2) return solveNaive(poly);

	vector<double> ret;
	vector<double> derivative = differentiate(poly);
	vector<double> sols = solve(derivative);
	sols.insert(sols.begin(), -L - 1);
	sols.insert(sols.end(), L + 1);

	for (int i = 0; i < sols.size() - 1; i++) {
		double x1 = sols[i];
		double x2 = sols[i + 1];
		double y1 = evaluate(poly, x1);
		double y2 = evaluate(poly, x2);

		// 부호가 같은 경우 근은 없다.
		if (y1*y2 > 0) continue;
		if (y1 > y2) {
			swap(y1, y2);
			swap(x1, x2);
		}

		for (int j = 0; j < 100; j++) {
			double midX = (x1 + x2) / 2;
			double midY = evaluate(poly, midX);

			if (y1*midY > 0) {
				y1 = midY;
				x1 = midX;
			}
			else {
				y2 = midY;
				x2 = midX;
			}
		}
		ret.push_back((x1 + x2) / 2);
	}
	sort(ret.begin(), ret.end());

	return ret;
}

int main() {
	int tc, n;
	cin >> tc;
	while (tc--) {
		vector<double> poly;
		cin >> n;
		for (int i = 0; i < n + 1; i++) {
			double c;
			cin >> c;
			poly.push_back(c);
		}

		vector<double> answer = solve(poly);
		cout << fixed << setprecision(8);
		for (int i = 0; i < answer.size(); i++) {
			cout << answer[i] << ' ';
		}
		cout << '\n';
	}

	return 0;
}