#include<cstdio>
#include<algorithm>
#include<vector>
#include<utility>
using namespace std;

pair<int, int> p;
vector<pair<int, int> > v;

bool comp(pair<int, int> a, pair<int, int> b) {
	if (a.second == b.second) return a.first < b.first;
	return a.second < b.second;
}

int main() {
	int tc;
	scanf("%d", &tc);
	for (int i = 0; i < tc; i++) {
		scanf("%d %d", &p.first, &p.second);
		v.push_back(p);
	}

	sort(v.begin(), v.end(), comp);

	for (int i = 0; i < v.size(); i++) {
		printf("%d %d\n", v[i].first, v[i].second);
	}

	return 0;
}