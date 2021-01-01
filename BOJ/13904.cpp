#include<bits/stdc++.h>
using namespace std;

class Assignment {
public:
	int deadline;
	int score;

	Assignment(int deadline, int score) {
		this->deadline = deadline;
		this->score = score;
	}
};

bool comp(Assignment a, Assignment b) {
	if (a.score == b.score) a.deadline < b.deadline;
	return a.score > b.score;
}

int N;
int MAX = 0;
int assign[1001];
vector<Assignment> v;

int solve() {
	for (int i = 0; i < v.size(); i++) {
		int deadline = v[i].deadline;
		int score = v[i].score;
		if (assign[deadline] != 0) {
			for (int j = deadline; j >= 1; j--) {
				if (assign[j] == 0 || assign[j] < score) {
					assign[j] = score;
					break;
				}
			}
		}
		else assign[deadline] = score;
	}

	int ret = 0;
	for (int i = 1; i <= MAX; i++) {
		ret += assign[i];
	}

	return ret;
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		int d, s;
		cin >> d >> s;
		if (MAX < d) MAX = d;
		v.push_back(Assignment(d, s));
	}
	sort(v.begin(), v.end(), comp);

	cout << solve() << '\n';


	return 0;
}