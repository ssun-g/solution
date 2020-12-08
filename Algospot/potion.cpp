#include<bits/stdc++.h>
using namespace std;

int recipe[200], put[200];

void Reset() {
	for (int i = 0; i < 200; i++) {
		recipe[i] = 0;
		put[i] = 0;
	}
}

int gcd(int p, int q) {
	if (q == 0) return p;
	return gcd(q, p%q);
}

void solve(const int recipe[], const int put[], int size) {
	vector<int> answer(size);
	int g = recipe[0];

	// 모든 recipe[]의 최대공약수
	for (int i = 1; i < size; i++) {
		g = gcd(g, recipe[i]);
	}

	double a = g;
	for (int i = 0; i < size; i++) {
		a = max(a, ceil((double)(put[i] * g) / (double)recipe[i]));
	}

	for (int i = 0; i < size; i++) {
		answer[i] = recipe[i] * a / g - put[i];
	}

	for (int i = 0; i < size; i++) {
		cout << answer[i] << ' ';
	}
}

int main() {
	int c;
	cin >> c;
	while (c--) {
		int n;
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> recipe[i];
		}

		for (int i = 0; i < n; i++) {
			cin >> put[i];
		}

		solve(recipe, put, n);
		cout << '\n';
		Reset();
	}

	return 0;
}