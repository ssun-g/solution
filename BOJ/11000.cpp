#include<bits/stdc++.h>
using namespace std;

class Lecture {
public:
	int start;
	int end;

	Lecture(int start, int end) {
		this->start = start;
		this->end = end;
	}
};

struct leccmp {
	bool operator()(const Lecture& a, const Lecture& b) {
		return a.end > b.end;
	}
};

bool comp(const Lecture& a, const Lecture& b) {
	return a.start < b.start;
}

vector<Lecture> lec;
priority_queue<Lecture, vector<Lecture>, leccmp> pq;

int main() {
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		int s, e;
		cin >> s >> e;
		lec.push_back(Lecture(s, e));
	}
	sort(lec.begin(), lec.end(), comp);

	pq.push(lec[0]);
	int answer = 1;
	for (int i = 1; i < N; i++) {
		if (pq.top().end > lec[i].start) {
			answer++;
			pq.push(lec[i]);
		}
		else {
			pq.pop();
			pq.push(lec[i]);
		}
	}
	cout << answer << '\n';

	return 0;
}