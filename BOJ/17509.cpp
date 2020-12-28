#include<bits/stdc++.h>
using namespace std;

class Solve {
public:
	int D;
	int V;

	Solve(int D, int V) {
		this->D = D;
		this->V = V;
	}
};

bool comp(Solve a, Solve b) {
	return a.D < b.D;
}

vector<Solve> problems;

int main() {
	for (int i = 0; i < 11; i++) {
		int d, v;
		cin >> d >> v;
		problems.push_back(Solve(d, v));
	}
	sort(problems.begin(), problems.end(), comp);


	int D = 0;
	int V = 0;
	int answer = 0;
	for (int i = 0; i < problems.size(); i++) {
		D += problems[i].D;
		V = problems[i].V;
		answer += D + 20 * V;
	}
	cout << answer << '\n';

	return 0;
}