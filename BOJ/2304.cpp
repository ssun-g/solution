#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

vector<pair<int, int> > v;
queue<pair<int, int> > qf;
queue<pair<int, int> > qb;

bool comp(pair<int, int> a, pair<int, int> b) {
	return a.first < b.first;
}

pair<int, int> SumOfHeight(queue<pair<int, int> > qp, int flag) {
	int sum = 0;
	int last_location = qp.front().first;
	int preheight = qp.front().second;
	qp.pop();
	while (!qp.empty()) {
		sum += preheight*(qp.front().first - last_location)*flag;
		last_location = qp.front().first;
		if (preheight < qp.front().second)
			preheight = qp.front().second;
		qp.pop();
	}

	return make_pair(sum, last_location);
}

int main() {
	pair<int, int> p;
	int N;
	int max_height = -1;
	int answer = 0;
	int left_location;
	int right_location;
	cin >> N;
	for (int i = 0; i < N; i++) {
		int location;
		int height;
		cin >> location >> height;
		v.push_back(make_pair(location, height));
		if (max_height < height) {
			max_height = height;
		}
	}
	sort(v.begin(), v.end(), comp);

	for (int i = 0; v[i].second <= max_height; i++) {
		qf.push(make_pair(v[i].first, v[i].second));
		if (v[i].second == max_height) break;
	}

	for (int i = v.size() - 1; v[i].second <= max_height; i--) {
		qb.push(make_pair(v[i].first, v[i].second));
		if (v[i].second == max_height) break;
	}

	p = SumOfHeight(qf, 1);
	answer += p.first;
	left_location = p.second;

	p = SumOfHeight(qb, -1);
	answer += p.first;
	right_location = p.second;

	cout << answer + (right_location - left_location + 1)*max_height << '\n';

	return 0;
}