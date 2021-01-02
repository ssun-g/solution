#include<bits/stdc++.h>
using namespace std;

class Rest {
public:
	long long stops;
	long long tastiness;

	Rest(long long stops, long long tastiness) {
		this->stops = stops;
		this->tastiness = tastiness;
	}
};

bool comp(Rest a, Rest b) {
	if (a.tastiness == b.tastiness) return a.stops < b.stops;
	return a.tastiness > b.tastiness;
}

vector<Rest> v;

long long solve(long long rF, long long rB) {
	long long cur = 0;
	long long ret = 0;
	for (int i = 0; i < v.size(); i++) {
		if (cur < v[i].stops) {
			ret += (v[i].stops - cur)*(rF - rB)*v[i].tastiness;
			cur = v[i].stops;
		}
	}

	return ret;
}

int main() {
	long long L, N, rF, rB;
	cin >> L >> N >> rF >> rB;
	for (int i = 0; i < N; i++) {
		long long stop, taste;
		cin >> stop >> taste;
		v.push_back(Rest(stop, taste));
	}
	sort(v.begin(), v.end(), comp);

	cout << solve(rF, rB) << '\n';

	return 0;
}